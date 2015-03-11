!---------------------------------------------------------------------------
!
!     This program converts the SDPA format to OSiL format
!
!     The SDPA format is explained in a text document at 
!     http://plato.asu.edu/ftp/sdpa_format.html
!
!     This version dated 10 January 2015
!     written by H.I. Gassmann
!
!     Approach: This program sets up what Brian Borchers calls the dual problem:
!
! (D)    max tr(F0*X)
!        st  tr(F1*X) = c1
!            tr(F2*X) = c2
!               ...   
!            tr(Fm*X) = cm
!            X symmetric and positive definite.
!
!     Each of the data matrices F are assumed block-diagonal, with identical block sizes.
!     (The nonzero structure within each block is allowed to vary.) 
!
!     The same data requirements also define the primal problem
!
! (P)    min c1*x1 + c2*x2 + ... + cm*xm
!        st  F1*x1 + F2*x2 + ... + Fm*xm - F0 = X
!            X symmetric and positive definite.
!
!     This problem could be further decomposed into:
!
! (P)    min  c1*x1 +  c2*x2 + ... +  cm*xm
!        st  F11*x1 + F21*x2 + ... + Fm1*xm - F01 - X1 = 0
!            F12*x1 + F22*x2 + ... + Fm2*xm - F02 - X2 = 0
!            ...
!            Xi symmetric and positive definite
!
!     Usage;
!         SDPA2OSiL -p|-d <inputFileName> [<outputFileName>]
! 
!      If outputFileName is missing, it is created from inputFileName by appending ".osil". 
!
!---------------------------------------------------------------------------
!
      implicit none
      integer,parameter :: maxline=31768
      character(LEN=maxline) :: nextl,infilenm,outfilenm
      integer lineno, ierr
      integer nmatrices, nblocks, nvar, nelem0, nelem1, nsize, stride, start
      integer imtx, iblk, irow, icol
      integer,allocatable :: blksize(:)
      double precision, allocatable :: cost(:)
      integer matno,blkno,i,j,k,l,n,maxblk
      double precision value,vmark
      integer,allocatable :: row(:), next(:), trow(:), tnext(:)
      integer,allocatable :: first(:), last(:)
      integer,allocatable :: blkstart(:,:), blkelem(:,:), colstart(:)
      double precision, allocatable :: coef(:), tcoef(:)
      integer nv, ncol, ncoef, nelem, nzeroblk, mult, incr, mark
      integer narg, iloc, clen, istart, lmn
      logical dual
      character*2 primaldual
      character*30 compress_real
!
!     command line handling
!
      narg = iargc()
      if (narg .le. 1) then
          write (6, 9999)
          stop
      endif
      call getarg(1, primaldual)
      if (primaldual(2:2) .eq. 'd' .OR. primaldual(2:2) .eq. 'D') then
          dual =.true.
      else
          dual = .false.
      endif
!
      call getarg(2, infilenm)
!
      if (narg .ge. 3) then
          call getarg(3, outfilenm)
      else
          outfilenm = trim(adjustl(infilenm)) // ".osil"
      endif
!
      open (15, file=infilenm,  err=9015)
      open (16, file=outfilenm, err=9016)
      print *, 'Translating file ', trim(adjustl(infilenm))
!
!     First put the header information
!
      write (16, 1001)
      write (16, 1002)
      write (16, 1003) trim(adjustl(infilenm))
      write (16, 1004)
!
!     Now process the comments from the SDPA file. There could be
!     arbitrarily many lines, all starting with '"' or '*'. We
!     simply echo them to the OSiL file.
!
      lineno = 0
      do
          lineno = lineno  + 1
          read(15, 1100) nextl
          nextl = adjustl(nextl)
          if (nextl(1:1) .ne. '"' .and. nextl(1:1) .ne. '*') exit
              write (16,*) trim(adjustl(nextl(2:)))
      end do
      write (16, 1005)
      write (16, 1006)
!
!     At this point nextl does not start with a comment indicator. 
!     This means it must contain the number of constraint matrices.
!     Read the problem dimensions and the cost vector 
!     (four records including nextl)
!
      read (nextl,*,err=900) nmatrices
      lineno = lineno + 1
      read (15,*) nblocks
      allocate(blksize(nblocks  ))
      allocate(   cost(nmatrices))
      read (15,*) (blksize(i),i=1,nblocks) 
      read (15,*) (   cost(i),i=1,nmatrices)
!
!     Now write this information
!
      print *, 'Number of matrices ', nmatrices 
      print *, 'Number of blocks   ', nblocks
      nvar = 0
      do i=1,nblocks
         nvar = nvar + abs(blksize(i))
      end do
      print *, 'Number of rows     ', nvar
!
      if (.not. dual) then
!
!     First the scalar variables --- primal problem only
!
         write (16, 1007) nmatrices,nmatrices
!
!     Now the cost coefficients
!
         write (16, 1008) nmatrices
         do i=1,nmatrices
            write (16, 1009) i-1,trim(compress_real(cost(i)))
         end do
         write (16, 1010)
!
!     The dual problem uses implicit variables and matrix expressions in the objective,
!     but there is a constraints section containing nonlinear expressions
!      
      else
         write (16, 1107)
         write (16, 1108) nmatrices
         i = 1
         do while (i .le. nmatrices)
            mult = 1
            if (i .lt. nmatrices) then
               vmark = cost(i)
               do j=i+1,nmatrices
                  if (cost(j) .ne. vmark) exit
                  mult = mult + 1
               end do
            endif
            if (mult .eq. 1) then
               write (16, 1109) trim(compress_real(cost(i))),                &
     &                          trim(compress_real(cost(i)))
            else
               write (16, 11095) trim(compress_real(vmark)),                 &
     &                           trim(compress_real(vmark)),mult
            end if
            i = i + mult
         end do
         write (16, 1110)
!
!     Write the nonlinear expressions for the objective and the body for each constraint
!
         write (16, 1111) nmatrices+1
         do i=0,nmatrices
            write (16, 1112) i-1,i
         end do   
         write (16, 1113)
      endif
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
!     blkstart is a pointer into the array of column starts. 
!     It essentially gives colOffsets for each matrix block in one long array
!
!     blkelem counts the number of elements in each block 
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
      nsize = max(1000, ((nmatrices+1)*ncol*5) )
! 
!     row gives the row indices, value the coefficients, next is a pointer to the next element
!
      allocate(row(nsize), coef(nsize), next(nsize), stat=ierr)
      if (ierr .ne. 0) goto 999
!
      row  = -1
      next = 0
      coef = 0.d0
!
!     first points to the first element in each column, last to the last element
!     This allows access to the entries in the row and coef arrays
!
      allocate(first((nmatrices+1)*ncol), last((nmatrices+1)*ncol), stat=ierr)
      if (ierr .ne. 0) goto 999
      first = 0
      last  = 0
      ncoef = 0
!
!     Read the elements
!     Matrices are assumed symmetric and seem to contain (in the examples available to me)
!     only elements in the lower triangular part. Therefore ignore other elements. 
!
      nelem0 = 0
      nelem1 = 0
      do
         read (15,*,err=900, end=200) imtx, iblk, icol, irow, value
         nelem1 = nelem1 + 1
         if (imtx .lt. 0 .or. imtx .gt. nmatrices) goto 900
         if (iblk .le. 0 .or. iblk .gt. nblocks  ) goto 900
         if (irow .le. 0 .or. irow .gt. abs(blksize(iblk))) goto 900
         if (icol .le. 0 .or. icol .gt. abs(blksize(iblk))) goto 900
         if (irow .lt. icol) then
            nelem0 = nelem0 + 1
            cycle
         endif
!
!     When putting the coefficients into the data structure,
!     make sure nonzeroes in each column are sorted by increasing row number.
!
         ncoef = ncoef + 1
         k = first(blkstart(imtx,iblk)+icol)
         l =  last(blkstart(imtx,iblk)+icol)
         if (k .eq. 0) then
            first(blkstart(imtx,iblk)+icol) = ncoef
             last(blkstart(imtx,iblk)+icol) = ncoef
         else
            if (irow .ge. row(l)) then
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
  200 continue
      print *, 'Number of nonzeros ', nelem1
      if (nelem0 .gt. 0) print *, '    Eliminated     ', nelem0, ' superdiagonals'
!
!     Now write the matrices and blocks one at a time. 
!     There are (nmatrices+1) of them, including some blocks that may be empty.
!     This section is the same for primal and dual problems.
!
      write (16, 1200) nmatrices+1
      do j=0,nmatrices
!
!     Write column and row offsets
!
         write (16, 1201) ncol,ncol,j 
         nzeroblk = 0
         do i=1,nblocks
            if (blkelem(j,i) .eq. 0) nzeroblk = nzeroblk + 1 
         end do
         write (16, 1202) nblocks-nzeroblk
         write (16, 1203) nblocks+1
         lmn = 0
         mark = -1
         mult = 0
         incr = 0
         call iprint0(mark,lmn,mult,incr)
!         write (16, 1205) lmn
!
         do i=1,nblocks
            lmn = lmn + abs(blksize(i))
!            write (16, 1205) lmn
            call iprint0(mark,lmn,mult,incr)
         enddo
         call iflush(mark,mult,incr)
         write (16, 1206)
         write (16, 1204) nblocks+1
         lmn = 0
         mark = -1
         mult = 0
         incr = 0
         call iprint0(mark,lmn,mult,incr)
!         write (16, 1205) lmn
         do i=1,nblocks
            lmn = lmn + abs(blksize(i))
!            write (16, 1205) lmn
            call iprint0(mark,lmn,mult,incr)
         enddo
         call iflush(mark,mult,incr)
         write (16, 1207)
!
         do i=1,nblocks
            if (blkelem(j,i) .gt. 0) then
               write (16, 1208) i-1,i-1
               write (16, 1209) blkelem(j,i)
!
!     Write the column starts in the current block (<start> element)
!
               write (16, 1210)
               istart = 0
               mark = -1
               mult = 0
               incr = 0
               call iprint0(mark,istart,mult,incr)
               do k=1,abs(blksize(i))
                  iloc = first(blkstart(j,i)+k)
                  if (iloc .eq. 0) then
                     clen = 0
                  else
                     clen = 1
                     do while (next(iloc) .gt. 0)
                        iloc = next(iloc)
                        clen = clen + 1
                     end do
                  endif
                  istart = istart + clen
                  call iprint0(mark,istart,mult,incr)
!                  write (16, 1205) istart
               end do
               call iflush(mark,mult,incr)
               write (16, 1211)
!
!     Write the row indices (<indexes> element)
!
               write (16, 1212)
               mark = -1
               mult = 0
               incr = 0
               do k=1,abs(blksize(i))
                  iloc = first(blkstart(j,i)+k)
                  if (iloc .gt. 0) then
                     do while (iloc .gt. 0)
!                        write (16, 1213) row(iloc) - 1
                        call iprint0(mark,row(iloc) - 1,mult,incr)
                        iloc = next(iloc)
                     end do
                  endif
               end do
               call iflush(mark,mult,incr)
               write (16, 1214)
               write (16, 1215)
!
!     Write the coefficients (<values> element)
!
               mult = 0
               do k=1,abs(blksize(i))
                  iloc = first(blkstart(j,i)+k)
                  if (iloc .gt. 0) then
                     do while (iloc .gt. 0)
                        call dprint0(vmark,coef(iloc),mult)
                        iloc = next(iloc)
                     end do
                  endif
               end do
               call dflush(vmark,mult)
               write (16, 1216)
               write (16, 1217)
               write (16, 1218)

            endif
         end do
         write (16, 1219)
         write (16, 1220)
      end do 
      write (16, 1221)
!
!     Next we write the cones section. 
!     The primal problem has two cones, the dual problem has only one
!
      if (dual) then
         write (16, 1230) 1
      else
         write (16, 1230) 2
      endif
      write (16, 1231) ncol,ncol
      if (.not. dual) then
         write (16, 1232) ncol,ncol
      endif
      write (16, 1233)
!
!     Last major element: the <matrixProgramming> element.
!     There are again differences between the primal and dual problems:
!     The primal problem has a matrix-valued constraint A1x1 + A2x2 + ... + Anxn - A0 - X = 0
!
      write (16, 1240) ncol,ncol
      if (.not. dual) then
         write (16, 1241) ncol,ncol
         write (16, 1242)
         do j=1,nmatrices
            write (16, 1243) j-1,j
         end do
         write (16, 1244)
      endif
      write (16, 1245)
!   
!     And that's it. Sew 'er up.
!
      write (16, 1044)
      stop
!
!     Input file has errors
!
  900 continue
      write (6, 1900)
      stop
!
!     File handling error
!
 9015 continue
      write (6, 9915)
      stop
!
 9016 continue
      write (6, 9916)
      stop
!
!     Insufficient memory
!
  999 continue
      write (6, 1999)
      stop
!
 1001 format('<?xml version="1.0" encoding="UTF-8"?>',/,                    &
     &       '<osil xmlns="os.optimizationservices.org" ',/,                &  
     &       'xmlns:os="os.optimizationservices.org" ',/,                   &
     &       'xmlns:xs="http://www.w3.org/2001/XMLSchema" ',/,              &
     &       'xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" ',/,    &
     &       'xsi:schemaLocation="os.optimizationservices.org ',/,          &
     &       'http://www.optimizationservices.org/schemas/2.0/OSiL.xsd">')
 1002 format('<instanceHeader>')
 1003 format('<name>SDPA problem ',A,'</name>')
 1004 format('<description>Translated from SDPA format using SDPA2OSiL',/,  &
     &       '       (C) H.I. Gassmann 2010-2015')
 1005 format('</description>')
 1006 format('</instanceHeader>')
 1007 format('<instanceData>',/,                                            &
     &       '<variables numberOfVariables="',I0,'">',/,                    &
     &       '<var lb="-INF" ub="INF" mult="',I0,'"/>',/,                   &
     &       '</variables>')
 1008 format('<objectives>',/,                                              &
     &       '<obj maxOrMin="min" numberOfObjCoef="',I0,'">')
 1009 format('<coef idx="',I0,'">',A,'</coef>')
 1010 format('</obj>',/,'</objectives>')

 1107 format('<instanceData>',/,                                            &
     &       '<objectives>',/,                                              &
     &       '<obj maxOrMin="max" numberOfObjCoef="0"/>',                   &
     &       '</objectives>')
 1108 format('<constraints numberOfConstraints="',I0,'">')
 1109 format('<con lb="',A,'" ub="',A,'"/>') 
11095 format('<con lb="',A,'" ub="',A,'" mult="',I0,'"/>')
 1110 format('</constraints>')
 1111 format('<nonlinearExpressions numberOfNonlinearExpressions="',I0,'">')
 1112 format('<nl idx="',I0,'">',/,                                         &
     &       '<matrixTrace>',/,                                             &
     &       '<matrixTimes>',/,                                             &
     &       '<matrixReference idx="',I0,'"/>',/,                           &
     &       '<matrixVar idx="0"/>',/,                                      &
     &       '</matrixTimes>',/,                                            &
     &       '</matrixTrace>',/,                                            &
     &       '</nl>')
 1113 format('</nonlinearExpressions>')

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

 1044 format('</instanceData>',/,'</osil>')
 1045 format('<el mult="',I0,'">',I0,'</el>')
 1046 format('<el mult="',I0,'" incr="',I0,'">',I0,'</el>')
!
 1100 format(a)
 1200 format('<matrices numberOfMatrices="',I0,'">')
 1201 format('<matrix numberOfColumns="',I0,'" numberOfRows="',I0,          &
     &     '" symmetry="lower" name="F',I0,'">')
 1202 format('<blocks numberOfBlocks="',I0,'">')
 1203 format('<colOffsets numberOfEl="',I0,'">')   
 1204 format('<rowOffsets numberOfEl="',I0,'">')
 1205 format('<el>',I0,'</el>')
 1206 format('</colOffsets>')
 1207 format('</rowOffsets>')
 1208 format('<block blockRowIdx="',I0,'" blockColIdx="',I0,'">')
 1209 format('<constantElements numberOfValues="',I0,'">')
 1210 format('<start>')
 1211 format('</start>')
 1212 format('<indexes>')
 1213 format('<el>',I0,'</el>')
 1214 format('</indexes>')
 1215 format('<values>')
 1216 format('</values>')
 1217 format('</constantElements>')
 1218 format('</block>')
 1219 format('</blocks>')
 1220 format('</matrix>')
 1221 format('</matrices>')
 1230 format('<cones numberOfCones="',I0,'">')
 1231 format('<semidefiniteCone numberOfColumns="',I0,                      &
     &       '" numberOfRows="',I0,'"/>')
 1232 format('<nonnegativeCone numberOfColumns="',I0,                       &
     &       '" numberOfRows="',I0,'"/>')
 1233 format('</cones>')
 1240 format('<matrixProgramming>',/,                                       &
     &       '<matrixVariables numberOfMatrixVar="1">',/,                   &
     &       '<matrixVar numberOfColumns="',I0,'" numberOfRows="',I0,       &
     &       '" lbConeIdx="0"/>',/,'</matrixVariables>')
 1241 format('<matrixConstraints numberOfMatrixCon="1">',/,                 &
     &       '<matrixVar numberOfColumns="',I0,'" numberOfRows="',I0,       &
     &       '" lbConeIdx="1" ubConeIdx="1"/>',/,'</matrixConstraints>')
 1242 format('<matrixExpressions numberOfExpr="1">',/,                      &
     &       '<expr idx="0" shape="linear">',/,'<matrixSum>')
 1243 format('<matrixScalarTimes>',/,                                       &
     &       '<variable idx="',i0,'">',/,                                   &
     &       '<matrixReference idx="',i0,'">',/,                            &
     &       '</matrixScalarTimes>')
 1244 format('<matrixNegate>',/,                                            &
     &       '<matrixReference idx="0">',/,                                 &
     &       '</matrixNegate>',/,                                           &
     &       '<matrixNegate>',/,                                            &
     &       '<matrixVar idx="0">',/,                                       &
     &       '</matrixNegate>',/,                                           &
     &       '</matrixSum>',/,                                              &
     &       '</expr>',/,                                                   &
     &       '</matrixExpressions>')
 1245 format('</matrixProgramming>')
 1900 format(' ERROR: Input file improperly formed')
 1999 format(' ERROR: Could not allocate sufficient memory')
!
 9915 format(' ERROR: Could not open input file')
 9916 format(' ERROR: Could not open output file')
 9999 format(' ERROR: Missing command line arguments',//,                   &
     &       '        Usage: SDPA2OSiL -p|-d <infile> [<outfile>]')
      end
!
!     Four subroutines to compress the output further (using mult and incr)
!
!     iprint0 prints nonnegative integers, possibly holding back one value
!     iflush  makes sure that any values not printed by iprint0 get flushed at the end
!     dprint0 prints real numbers (using mult only)
!     dflush  makes sure that any values not printed by dprint0 get flushed at the end
!
      subroutine iprint0(prev, ival, mult, incr)
!
      integer prev, ival, mult, incr
      integer itmp
!
      if (mult .eq. 0) then
         mult = 1
         prev = ival
      else if (mult .eq. 1) then
         incr = ival - prev
         mult = 2
      else if (ival .eq. prev + mult*incr) then
            mult = mult + 1
!
!     Here we print something and reset
!
      else
         if (incr .eq. 0) then
            if (mult .eq. 1) then
               write (16, 1601) prev
            else
               write (16, 1602) mult, prev
            endif
            prev = ival
            mult = 1   
         else
            if (mult .eq. 2) then
               write (16, 1601) prev
               prev = prev + incr
               mult = 2   
               incr = ival - prev
            else
               if (mult .eq. 1) then
                  write (16, 1601) prev
               else
                  write (16, 1603) mult, incr, prev
               endif
               prev = ival
               mult = 1   
               incr = 0
            endif
         endif
      endif
      return
!
 1601 format('<el>',i0,'</el>')
 1602 format('<el mult="',i0,'">',i0,'</el>')
 1603 format('<el mult="',i0,'" incr="',i0,'">',i0,'</el>')
      end
!
      subroutine iflush( prev, mult, incr)
!
      integer prev, mult, incr
!
!     Here we just print and reset
!
      if (incr .eq. 0) then
         if (mult .eq. 1) then
            write (16, 1601) prev
         else
            write (16, 1602) mult, prev
         endif
         prev = -1
         mult = 0   
      else
         if (mult .eq. 1) then
            write (16, 1601) prev
         elseif (mult .eq. 2) then
            write (16, 1601) prev
            write (16, 1601) prev + incr
         else
            write (16, 1603) mult, incr, prev
         endif
         prev = -1
         mult = 0   
         incr = 0
      endif
      return
!
 1601 format('<el>',i0,'</el>')
 1602 format('<el mult="',i0,'">',i0,'</el>')
 1603 format('<el mult="',i0,'" incr="',i0,'">',i0,'</el>')
      end
!
      subroutine dprint0(prev, dval, mult, incr)
!
      integer mult, incr
      double precision prev, dval
      character*30 compress_real
!
      if (mult .eq. 0) then
         mult = 1
         prev = dval
      else if (prev .eq. dval) then
         mult = mult + 1
!
!     Here we print something and reset
!
      else
         if (mult .eq. 1) then
            write (16, 1601) trim(compress_real(prev))
         else
            write (16, 1602) mult, trim(compress_real(prev))
         endif
         prev = dval
         mult = 1
      endif
      return
!
 1601 format('<el>',A,'</el>')
 1602 format('<el mult="',i0,'">',A,'</el>')
      end
!
      subroutine dflush( prev, mult)
!
      integer mult
      double precision prev
      character*30 compress_real
!
!     Here we just print and reset
!
      if (mult .eq. 1) then
         write (16, 1601) trim(compress_real(prev))
      else
         write (16, 1602) mult, trim(compress_real(prev))
      endif
      mult = 0   
      return
!
 1601 format('<el>',A,'</el>')
 1602 format('<el mult="',i0,'">',A,'</el>')
      end
!
!     This function compresses a real number as much as possible
!     without going into the ramifications of using David Gay's dtoa
!
      character*30 function compress_real(x)
!
      character*30 temp, temp2
      double precision x
      integer first, last
!
      if (x .eq. 0.0) then
         compress_real = '0'
         return
      endif
!
      write (temp, *) x
!
!     suppress leading blanks
!  
      first = 1
      do while (temp(first:first) .eq. ' ')
         first = first + 1
      end do
!
!     suppress trailing blanks
!  
      last = 30
      do while (temp(last:last) .eq. ' ')
         last = last - 1
      end do
!
!     suppress trailing zeros if not exponential form
!
      if (scan(temp(first:last),'eEdD') .eq. 0) then
         do while (temp(last:last) .eq. '0')
            last = last - 1
         end do
      endif
!
      compress_real = temp(first:last)
      return
      end 
