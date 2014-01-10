!---------------------------------------------------------------------------
!
!     This program converts the SDPA format to OSiL format
!
!     The SDPA format is explained in a text document at 
!     http://plato.asu.edu/ftp/sdpa_format.html
!
!     This version dated 10 January 2013
!     written by H.I. Gassmann
!
!     Approach: This program sets up what Brian Borchers calls the primal problem:
!
! (P)    min c1*x1 + c2*x2 + ... + cm*xm
!        st  F1*x1 + F2*x2 + ... + Fm*xm - F0 = X
!            X symmetric and positive definite
!
!     If the data matrices F are block-diagonal, this can be further decomposed into:
!
! (P)    min  c1*x1 +  c2*x2 + ... +  cm*xm
!        st  F11*x1 + F21*x2 + ... + Fm1*xm - F01 - X1 = 0
!            F12*x1 + F22*x2 + ... + Fm2*xm - F02 - X2 = 0
!            ...
!            Xi symmetric and positive definite
!
!---------------------------------------------------------------------------
!
      implicit none
      integer,parameter :: maxline=31768
      character(LEN=maxline) :: nextl
      integer lineno, ierr
      integer nmatrices, nblocks, nvar, nsize, nvar0, stride, start
      integer imtx, iblk, irow, icol
      integer,allocatable :: blksize(:)
      double  precision, allocatable :: cost(:)
      integer matno,blkno,i,j,k,l,n,maxblk
      double  precision value,vmark
      integer,allocatable :: row(:), next(:), trow(:), tnext(:)
      integer,allocatable :: first(:), last(:)
      integer,allocatable :: blkstart(:,:), blkelem(:,:), colstart(:)
      double  precision, allocatable :: coef(:), tcoef(:)
      integer nv, ncol, ncoef, nelem, nzeroblk, mult, incr, mark
!
!     First put the header information
!
      write (6,1001)
      write (6,1002)
      write (6,1003)
      write (6,1004)
      write (6,1005)
!
!     Now process the comments from the SDPA file. There could be
!     arbitrarily many lines, all starting with '"' or '*'. We
!     simply echo them to the OSiL file.
!
      lineno = 0
      do
          lineno = lineno  + 1
          read(5,1100) nextl
          nextl = adjustl(nextl)
          if (nextl(1:1) .ne. '"' .and. nextl(1:1) .ne. '*') exit
              write (6,*) trim(adjustl(nextl(2:)))
      end do
      write (6,1006)
!
!     At this point nextl does not start with a comment indicator. 
!     This means it must contain the number of constraint matrices.
!     Read the problem dimensions and the cost vector 
!     (four records including nextl)
!
      read (nextl,*,err=900) nmatrices
      lineno = lineno + 1
      read (5,*) nblocks
      allocate(blksize(nblocks))
      allocate(   cost(nmatrices))
      read (5,*) (blksize(i),i=1,nblocks) 
      read (5,*) (   cost(i),i=1,nmatrices) 
!
!     Now write this information 
!
!     Count the variables --- The X matrix is structured and uses the upper triangle only
!
      nvar = nblocks
      do i=1,nblocks
         if (blksize(i) .gt. 0) then
            nvar = nvar + blksize(i)*(blksize(i)+1)/2
         else
            nvar = nvar - blksize(i)
         endif
      end do
      write (6,1007) nvar,nvar
!
!     Now the cost coefficients
!
      write (6,1008) nmatrices
      do i=1,nmatrices
         write (6,1009) i-1,cost(i)
      end do
      write (6,1010)
!
!     Now the <matrices> section.  
!     The description of the format is silent on whether the coefficients must be ordered,
!     so we assume the worst case: No ordering at all.
!
!     In order to process the coefficient matrices, we build a number of linked lists,
!     one for each column and one set for each matrix and each block. The linked lists 
!     are maintained as allocatable arrays, which may have to be re-sized if the original 
!     allocation proves insufficient. 
!
      allocate(blkstart(0:nmatrices,nblocks),blkelem(0:nmatrices,nblocks))
      ncol = 0
      maxblk = 0
      blkelem = 0
      do i=1,nblocks
         blkstart(0,i) = ncol
         ncol = ncol + abs(blksize(i))
         maxblk = max(maxblk, abs(blksize(i)))
      end do
      do j=1,nmatrices
         do i=1,nblocks
            blkstart(j,i) = blkstart(j-1,i) + ncol
         end do
      end do
!
!     The number of nonzeroes is not available yet, so make a guess
!     and resize later if this proves necessary
!
      nsize = max(1000, ((nmatrices+1)*nblocks*5) )
      allocate(row(nsize), coef(nsize), next(nsize), stat=ierr)
      if (ierr .ne. 0) goto 999
!
      row  = -1
      next = 0
      coef = 0.d0
      allocate(first((nmatrices+1)*ncol), last((nmatrices+1)*ncol), stat=ierr)
      if (ierr .ne. 0) goto 999
      first = 0
      last  = 0
      ncoef = 0
!
!     Read the elements
!
      do
         read (5,*,err=900, end=200) imtx, iblk, irow, icol, value
         if (imtx .lt. 0 .or. imtx .gt. nmatrices) goto 900
         if (iblk .le. 0 .or. iblk .gt. nblocks  ) goto 900
         if (irow .le. 0 .or. irow .gt. abs(blksize(iblk))) goto 900
         if (icol .le. 0 .or. icol .gt. abs(blksize(iblk))) goto 900
         if (irow .gt. icol) goto 900
!
!     When putting the coefficients into the data structure,
!     make sure nonzeroes in each column are sorted by increasing row number 
!
         ncoef = ncoef + 1
         k = first(blkstart(imtx,iblk)+icol)
         l =  last(blkstart(imtx,iblk)+icol)
         if (k .eq. 0) then
             first(blkstart(imtx,iblk)+icol) = ncoef
              last(blkstart(imtx,iblk)+icol) = ncoef
         else
             if (irow .ge. row(l)) then
             if (irow .eq. row(l)) goto 900
                next(l)                        = ncoef
                last(blkstart(imtx,iblk)+icol) = ncoef
             else
                if (irow .lt. row(k)) then
                   first(blkstart(imtx,iblk)+icol) = ncoef
                   next(ncoef) = k
                else
                   do while (irow .lt. row(next(k)))
                      k = next(k)
                   end do
                   next(ncoef) = next(k)
                   next(k) = ncoef
                endif
             endif
         endif
!
!     Resize arrays if necessary
!
         if (ncoef .gt. nsize) then
            allocate (trow(nsize), tcoef(nsize), tnext(nsize), stat=ierr)
            if (ierr .ne. 0) goto 999
            trow  = row
            tcoef = coef
            tnext = next
            deallocate (row, coef, next)
            allocate (row(2*nsize), coef(2*nsize), next(2*nsize), stat=ierr)
            if (ierr .ne. 0) goto 999
!
             row(1:nsize) = trow
            coef(1:nsize) = tcoef
            next(1:nsize) = tnext
             row(nsize+1:2*nsize) = -1
            next(nsize+1:2*nsize) = 0
            coef(nsize+1:2*nsize) = 0.d0
            deallocate (trow, tcoef, tnext)
            nsize = 2*nsize
         endif
!
         blkelem(imtx,iblk) = blkelem(imtx,iblk) + 1
         coef(ncoef) = value
          row(ncoef) = irow
      end do
!
!     Now write the blocks one at a time. Including F0 and X there are 
!     (nmatrices+2)*nblocks of them, including the blocks that have no elements.
!
  200 continue
      nzeroblk = 0
      do j=0,nmatrices
         do i=1,nblocks
            if (blkelem(j,i) .eq. 0) nzeroblk = nzeroblk + 1 
         end do
      end do 
!
!     The X blocks are easier; deal with them first.
!
      write (6,1011) (nmatrices+2)*nblocks
      nvar0 = nblocks
      do i=1,nblocks
         write (6,1012) abs(blksize(i)), abs(blksize(i)),                &
     &                  abs(blksize(i)) + 1
!
!     Variable blocks inherit their structure (diagonal or full upper triangular)
!     from the structure of the underlying data matrices
!     (diagonal if blksize(i) > 0 and full upper triangular otherwise)
!
         if (blksize(i) .gt. 0) then
            start  = 0
            do j=0,abs(blksize(i))
               write (6,1013) start
               start = start + j + 1
            end do
!
            nv = blksize(i)*(blksize(i)+1)/2
            write (6,1014) nv
!
            do j=0,abs(blksize(i))-1
               if     (j .eq. 0) then
                  write (6,1015)
               elseif (j .eq. 1) then
                  write (6,1016)
               else 
                  write (6,1017) j + 1
               endif
            end do
!
!     Here we have diagonal matrices
!
         else
            if (blksize(i) .eq. -1) then
               write (6,1016)
            else
               write (6,1017) 1 - blksize(i)
            endif
!
            nv = -blksize(i)
            write (6,1014) nv
!
            if     (blksize(i) .eq. -1) then
               write (6,1015)
            elseif (blksize(i) .eq. -2) then
               write (6,1016)
            else 
               write (6,1017) -blksize(i)
            endif
         endif
!
         write (6,1018) nv, nvar0
         nvar0 = nvar0 + nv
      end do
!
!     For other blocks we have to establish the column starts. 
!
      allocate(colstart(maxblk+1), stat=ierr)
      if (ierr .ne. 0) goto 999
!
      do j=0,nmatrices
         do i=1,nblocks
            nelem = 0
            do k=1,abs(blksize(i))
               colstart(k) = nelem
               n = first(blkstart(j,i)+k)
               do while (n .gt. 0)
                  nelem = nelem + 1
                  n = next(n)
               end do
            end do
            colstart(abs(blksize(i))+1) = nelem
!
!     Try to compress using mult and incr. 
!     If two or more consecutive numbers are the same, use mult.
!     For a run of three or more, use mult and incr.
!     Index counting is easier if all matrices --- even zero ones --- are mentioned
!
            write (6,1019) abs(blksize(i)),abs(blksize(i))
!
!     Write the <start> element
!
            if (nelem .gt. 0) then
               write (6,1020) abs(blksize(i)) + 1
               k = 1
               do 
                  mult = 1
                  incr = 0
                  mark = colstart(k)
                  if (k .eq. abs(blksize(i))+1) then
                     write (6,1021) colstart(k)
                     exit
                  else
                     k = k + 1
                     do while (k .le. abs(blksize(i))+1 )
                        if (colstart(k) .ne. mark) exit
                           mult = mult + 1
                           k = k + 1
                     end do
                     if (mult .gt. 1) then
                        write (6,1045) mult, mark
                     else
                        if (k .eq. abs(blksize(i))+2) then
                           write (6,1021) mark
                           write (6,1021) colstart(k-1)
                           exit
                        else
                           mult = 2
                           incr = colstart(k) - mark
                           do while (k .le. abs(blksize(i)))
                              if (colstart(k+1) - colstart(k) .ne. incr) exit
                                 mult = mult + 1
                                 k = k + 1
                           end do
                           if (mult .eq. 2) then
                              write (6,1021) mark
                           else
                              write (6,1046) mult, incr, mark
                              k = k + 1
                           endif
                        endif
                     endif
                     if (k .gt. abs(blksize(i))+1) exit
                  endif
               end do
               write (6,1022) nelem
!
!    Put the <indexes> element
!
               mult = 0
               do k=1,abs(blksize(i))
                  n = first(blkstart(j,i)+k)
                  do while (n .gt. 0)
                     if (mult .eq. 0) then
                         mult = 1
                         mark = row(n)
                     elseif (mult .eq. 1) then
                         incr = row(n) - mark
                         mult = 2
                     else
                         if (row(n) .eq. mark + mult*incr) then
                            mult = mult + 1
                         else
                            if (incr .eq. 0) then
                               write (6, 1045) mult, mark - 1
                            elseif (mult .eq. 2) then
                               write (6, 1021) mark - 1
                               write (6, 1021) mark + incr - 1
                            else
                               write (6, 1046) mult, incr, mark - 1
                            endif
                            mult = 1
                            mark = row(n)
                         endif
                     endif
                     n = next(n)
                  end do
               end do
               if (mult .gt. 0) then
                  if (mult .eq. 1) then
                     write (6, 1021) mark - 1
                  elseif (incr .eq. 0) then
                     write (6, 1045) mult, mark - 1
                  elseif (mult .eq. 2) then
                     write (6, 1021) mark - 1
                     write (6, 1021) mark + incr - 1
                  else
                     write (6, 1046) mult, incr, mark - 1
                  endif
               endif
               write (6,1023)
!
!     Put the <value> element
!
               mult = 0
               do k=1,abs(blksize(i))
                  n = first(blkstart(j,i)+k)
                  do while (n .gt. 0)
                     if (mult .eq. 0) then
                         mult = 1
                         vmark = coef(n)  
                     else                 
                         if (coef(n) .eq. vmark) then
                            mult = mult + 1
                         else
                            if (mult .eq. 1) then
                                write (6, 1024) vmark
                            else
                                write (6, 1047) mult, vmark
                            endif
                            mult = 1
                            vmark = coef(n)
                         endif
                     endif
                     n = next(n)
                  end do
               end do
               if (mult .gt. 0) then
                  if (mult .eq. 1) then
                     write (6, 1024) vmark
                  else
                     write (6, 1037) mult, vmark
                  endif
               endif
               write (6,1025)
!
            endif
            write (6,1026)
         end do
      end do
      write (6,1027)
!
!     Next we write the cones, two for each block. Since different blocks 
!     may have the same size, we might get away with fewer cones, but it does
!     not seem worth the trouble to detect this redundancy.
!
      write (6,1028) 2*nblocks
      do i=1,nblocks
         write (6,1029)  i,abs(blksize(i)),abs(blksize(i))
         write (6,1030) i,abs(blksize(i)),abs(blksize(i))
      end do
      write (6,1031)
!
!     Last major element: the <matrixProgramming> element. 
!
      write (6,1032) nblocks
      do i=1,nblocks
         write (6,1033) i-1, i
      end do
      write (6,1034)
!
!        st  F11*x1 + F21*x2 + ... + Fm1*xm - X1 = F01 
!
      write (6,1035) nblocks
      do i=1,nblocks
         write (6,1036) nblocks + i -1, nblocks + i -1, i, i, nmatrices+1
         do j=1,nmatrices
            write (6,1037) j-1, (j+1)*nblocks + i - 1 	
         end do   
         write (6,1038) i-1
      end do
      write (6,1039)
!
!     Last component: <linearConstraintMatrixOperators>
!
!      write (6,1040) nblocks*(nmatrices+1) - nzeroblk
!      do i=1,nblocks
!         write (6,1041) i-1, i-1
!         do j=1,nmatrices
!            if (blkelem(j,i) .gt. 0) then
!               write (6,1042) j-1, i-1, j, i
!            endif
!         end do
!      end do
!      write (6,1043)
!
!     And that's it. Sew 'er up.
!
      write (6,1044)
      stop
!
!     Input file has errors
!
  900 continue
      write (6,1900)
      stop
!
!     Insufficient memory
!
  999 continue
      write (6,1999)
      stop
!
 1001 format('<?xml version="1.0" encoding="UTF-8"?>',/,                    &
     &       '<osil xmlns="os.optimizationservices.org"',/,                 &  
     &       'xmlns:os="os.optimizationservices.org"',/,                    &
     &       'xmlns:xs="http://www.w3.org/2001/XMLSchema"',/,               &
     &       'xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"',/,     &
     &       'xsi:schemaLocation="os.optimizationservices.org',/,           &
!     &       ' http://www.optimizationservices.org/schemas/2.0/OSiL.xsd">')
     &       'C:\datafiles\research\os\os-trunk-work\os\schemas\OSiL.xsd">')
 1002 format('<instanceHeader>')
 1003 format('<name>SDPA problem</name>')
 1004 format('<source>Translated from SDPA format using SDPA2OSiL',/,       &
     &       '       (C) H.I. Gassmann 2010-2013</source>')
 1005 format('<description>')
 1006 format('</description>',/,'</instanceHeader>')
 1007 format('<instanceData>',/,                                            &
     &       '<variables numberOfVariables="',I0,'">',/,                    &
     &       '<var lb="-INF" ub="INF" mult="',I0,'"></var>',/,              &
     &       '</variables>')                                        
 1008 format('<objectives>',/,                                              &
     &       '<obj maxOrMin="min" numberOfObjCoef="',I0,'">')
 1009 format('<coef idx="',I0,'">',G30.15,'</coef>')
 1010 format('</obj>',/,'</objectives>')
 1011 format('<matrices numberOfMatrices="',I0,'">')
 1012 format('<matrix numberOfColumns="',I0,                                &
     &       '" numberOfRows="',I0,'" symmetric="true">',/,                 &
     &       '<elements>',/,'<varReferenceElements>',/,                     &  
     &       '<start numberOfEl="',I0,'">')
 1013 format('<el>',I0,'</el>')
 1014 format('</start>',/,'<nonzeros numberOfEl="',I0,'">',/,               &
     &       '<indexes>')
 1015 format('<el>0</el>')
 1016 format('<el>0</el>   <el>1</el>')    
 1017 format('<el mult="',I0,'" incr="1">0</el>')
 1018 format('</indexes>',/,'<values>',/,                                   &
     &       '<el mult="',I0,'" incr="1">',I0,'</el>',/,                    &
     &       '</values>',/,'</nonzeros>',/,                                 &
     &       '</varReferenceElements>',/,'</elements>',/,'</matrix>')
 1019 format('<matrix numberOfColumns="',I0,                                &
     &       '" numberOfRows="',I0,'">')
 1020 format('<elements>',/,'<constantElements>',/,                         &
     &       '<start numberOfEl="',I0,'">')
 1021 format('<el>',I0,'</el>')
 1022 format('</start>',/,'<nonzeros numberOfEl="',I0,'">',/,               &
     &       '<indexes>')
 1023 format('</indexes>',/,'<values>')
 1024 format('<el>',G30.15,'</el>')
 1025 format('</values>',/,'</nonzeros>',/,'</constantElements>',/,         &
     &       '</elements>')
 1026 format('</matrix>')
 1027 format('</matrices>')
 1028 format('<cones numberOfCones="',I0,'">')
 1029 format('<semidefiniteCone id="C',I0,'" numberOfColumns="',I0,         &
     &                                    '" numberOfRows="',I0,'"/>')
 1030 format('<nonnegativeCone id="P',I0,'" numberOfColumns="',I0,          &
     &                                    '" numberOfRows="',I0,'"/>')
 1031 format('</cones>')
 1032 format('<matrixProgramming_new>',/,                                   &
     &       '<matrixBounds numberOfBounds="',I0,'">')
 1033 format('<bound matrixIdx="',I0,'" lbConeID="C',I0,'"/>')
 1034 format('</matrixBounds>')
 1035 format('<matrixConstraints numberOfMatrixCon="',I0,'">')
 1036 format('<matrixCon lbMatrixIdx="',I0,'" ubMatrixIdx="',I0,            &
     &       '" lbConeID="P',I0,'" ubConeID="P',I0,                         &
     &       '" numberOfMatrixTerms="',I0,'">')
 1037 format('<matrixTerm>',/,'<matrixScalarTimes>',/,                      &
     &       '<variable idx="',I0,'"/>',/,                                  &
     &       '<matrix idx="',I0,'"/>',/,                                    &
     &       '</matrixScalarTimes>',/,'</matrixTerm>')
 1038 format('<matrixTerm>',/,'<matrixScalarTimes>',/,                      &
     &      '<number type="real" value="-1"/>',/,                           &
     &      '<matrix idx="',I0,'"/>',/,                                     &
     &      '</matrixScalarTimes>',/,'</matrixTerm>',/,'</matrixCon>')
 1039 format('</matrixConstraints>')
 1040 format('<linearConstraintMatrixOperators numberOfOperators="',I0,'">')
 1041 format('<matrixVarOperator matrixVarIdx="',I0,'" matrixConIdx="',I0,  &
     &       '" scalarCoef="-1"/>')
 1042 format('<scalarVarOperator varIdx="',I0,'" matrixConIdx="',I0,        &
     &       '" matrixID="F',I0,':',I0,'"/>')
 1043 format('</linearConstraintMatrixOperators>')

 1044 format('</matrixProgramming_new>',/,'</instanceData>',/,'</osil>')
 1045 format('<el mult="',I0,'">',I0,'</el>')
 1046 format('<el mult="',I0,'" incr="',I0,'">',I0,'</el>')
 1047 format('<el mult="',I0,'">',G30.15,'</el>')
!
 1100 format(a)
 1900 format(' ERROR: Input file improperly formed')
 1999 format(' ERROR: Could not allocate sufficient memory')
      end
