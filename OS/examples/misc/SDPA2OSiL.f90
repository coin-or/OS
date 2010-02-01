!     This is a first attempt at converting the SDPA format to OSiL format
!
!     The SDPA format is explained in a text document at 
!     http://plato.asu.edu/ftp/sdpa_format.html
!
!     This version dated 31 January 2010
!     written by H.I. Gassmann
!
!-----------------------------------------------------------------------------------------------------------------------------------
!
      implicit none
      integer,parameter :: maxline=255
      character(LEN=maxline) :: nextl
      integer lineno
      integer nmatrices, nblocks, nvar, nsize, nvar0
      integer imtx, iblk, irow, icol
      integer,allocatable :: blksize(:)
      double precision, allocatable :: cost(:)
      integer matno,blkno,i,j,k,n,maxblk
      double precision value
      integer, allocatable :: row(:), next(:), trow(:), tnext(:)
      integer, allocatable :: first(:), last(:)
      integer, allocatable :: blkstart(:,:), colstart(:)
      double precision, allocatable :: coef(:), tcoef(:)
      integer nv, ncol, ncoef, nelem
!
!     First put the header information
!
      write (6,1000)
      write (6,1001)
      write (6,1002)
      write (6,1003)
      write (6,1004)
!
!     Now process the comments from the SDPA file. There could be
!     arbitrarily many lines, all starting with '"' or '*'
!
      lineno = 0
      do
          lineno = lineno  + 1
          read(5,1100) nextl
          nextl = adjustl(nextl)
          if (nextl(1:1) .ne. '"' .and. nextl(1:1) .ne. '*') exit
              write (6,*) trim(adjustl(nextl(2:)))
      end do
      write (6,1005)
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
      nvar = nblocks
      do i=1,nblocks
         if (blksize(i) .gt. 0) then
            nvar = nvar + blksize(i)*(blksize(i)+1)/2
         else
            nvar = nvar - blksize(i)
         endif
      end do
      write (6,1006) nvar,nvar
      write (6,1007) nmatrices
      do i=1,nmatrices
         write (6,1008) i-1,cost(i)
      end do
      write (6,1009)
!
!     Now the <matrices> section. There are (nmatrices+2)*nblocks of them,
!     including F0 and X. (No attempt is made to detect and suppress empty blocks)
!     The X blocks are easiest and can be dealt with first.
!
      write (6,1010) (nmatrices+2)*nblocks
      nvar0 = nblocks
      do i=1,nblocks
         if (blksize(i) .gt. 0) then
            nv = blksize(i)*(blksize(i)+1)/2
         else
            nv = -blksize(i)
         endif
         write (6,1011) i, abs(blksize(i)), abs(blksize(i)), nvar0, nvar0+nv-1
         nvar0 = nvar0 + nv
      end do
!
!     In order to process the coefficient matrices, we need to build a number of
!     linked lists, one for each column and, if the values are not sorted by block,
!     one set for each matrix and each block. The linked lists are maintained as 
!     allocatable arrays, which may have to be re-sized if the original allocation
!     proves insufficient. 
!
      nsize = max(1000, ((nmatrices+1)*nblocks*3) )
      allocate(row(nsize), coef(nsize), next(nsize))
      row  = -1
      next = 0
      coef = 0.d0
      allocate(blkstart(0:nmatrices,nblocks))
      ncol = 0
      maxblk = 0
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
      allocate(first((nmatrices+1)*ncol), last((nmatrices+1)*ncol))
      next  = 0
      first = 0
      last  = 0
      ncoef = 0
      ncol  = 0
!
!     Start reading the elements
!
      do
         read (5,*,err=900, end=200) imtx, iblk, irow, icol, value
         if (imtx .lt. 0 .or. imtx .gt. nmatrices) goto 900
         if (iblk .le. 0 .or. iblk .gt. nblocks  ) goto 900
         if (irow .le. 0 .or. irow .gt. abs(blksize(iblk))) goto 900
         if (icol .le. 0 .or. icol .gt. abs(blksize(iblk))) goto 900
         ncoef = ncoef + 1
         k = first(blkstart(imtx,iblk)+icol)
         if (k .eq. 0) then
             first(blkstart(imtx,iblk)+icol) = ncoef
              last(blkstart(imtx,iblk)+icol) = ncoef
         else
             do while (next(k) .ne. 0)
                k = next(k)
             end do
             next(k) = ncoef
         endif
!
!     Resize if necessary
!
         if (ncoef .gt. nsize) then
            allocate (trow(nsize), tcoef(nsize), tnext(nsize))
            trow  = row
            tcoef = coef
            tnext = next
            deallocate (row, coef, next)
            allocate (row(2*nsize), coef(2*nsize), next(2*nsize))
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
         coef(ncoef) = value
          row(ncoef) = irow
      end do
!
!     Now write the blocks one at a time. For each block we must establish
!     the number of elements (no attempt is made to squeeze out any zeroes)
!     and the column starts
!
  200 continue
      allocate(colstart(maxblk))
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
!
            write (6,1012) j,i,abs(blksize(i)),abs(blksize(i)),nelem
            write (6,1013)
            do k=1,abs(blksize(i))
               write (6,1014) colstart(k)
            end do
            write (6,1014) nelem
!
            write (6,1015)
            do k=1,abs(blksize(i))
               colstart(k) = nelem
               n = first(blkstart(j,i)+k)
               do while (n .gt. 0)
                  write (6,1014) row(n)-1
                  n = next(n)
               end do
            end do
!
            write (6,1016)
            do k=1,abs(blksize(i))
               colstart(k) = nelem
               n = first(blkstart(j,i)+k)
               do while (n .gt. 0)
                  write (6,1017) coef(n)
                  n = next(n)
               end do
            end do
            write (6,1018)
         end do
      end do
      write (6,1019)
!
!     Next we write the cones, one for each block. Since different blocks 
!     may have the same size, we might get away with fewer cones, but it does
!     not seem worth the trouble to detect this redundancy.
!
      write (6,1020) nblocks
      do i=1,nblocks
         write (6,1021) i,abs(blksize(i)),abs(blksize(i))
      end do
      write (6,1022)
!
!    Last major element: the <matrixProgramming> element. 
!    First component: <matrixVariables>
!
      write (6,1023) nblocks
      do i=1,nblocks
         write (6,1024) i, i
      end do
      write (6,1025)
!
!     Next component: <matrixConstraints>
!                                         
      write (6,1026) nblocks
      do i=1,nblocks
         write (6,1027) i, i
      end do
      write (6,1028)
!
!     Last component: <linearConstraintMatrixOperators>
!
      write (6,1029) nblocks*(nmatrices+1)
      do i=1,nblocks
         write (6,1030) i-1, i-1
         do j=1,nmatrices
         write (6,1031) j-1, i-1, j, i
         end do
      end do
      write (6,1032)
!
!     And that's it. Sew 'er up.
!
      write (6,1033)
      stop
!
!     Input file has errors
!
  900 continue
      write (6,1900)
      stop
 1000 format(' <?xml version="1.0" encoding="UTF-8"?>',/,                    &
     &       ' <osil xmlns="os.optimizationservices.org"',/,                 &  
     &       ' xmlns:os="os.optimizationservices.org"',/,                   &
     &       ' xmlns:xs="http://www.w3.org/2001/XMLSchema"',/,              &
     &       ' xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"',/,    &
     &       ' xsi:schemaLocation="os.optimizationservices.org',/,          &
!     &       ' http://www.optimizationservices.org/schemas/2.0/OSiL.xsd">')
     &       ' C:\datafiles\research\os\os-trunk-work\os\schemas\OSiL.xsd">')
 1001 format(' <instanceHeader>')
 1002 format(' <name>SDPA problem</name>')
 1003 format(' <source>Translated from SDPA format using SDPA2OSiL',/,       &
     &       '        (C) H.I. Gassmann 2010</source>')
 1004 format(' <description>')
 1005 format(' </description>',/,'</instanceHeader>')
 1006 format(' <instanceData>',/,                                            &
     &       ' <variables numberOfVariables="',I0,'">',/,                    &
     &       ' <var lb="-INF" ub="INF" mult="',I0,'"></var>',/,              &
     &       ' </variables>')                                        
 1007 format(' <objectives>',/,                                              &
     &       ' <obj maxOrMin="min" numberOfObjCoef="',I0,'">')
 1008 format(' <coef idx="',I0,'">',G30.15,'</coef>')
 1009 format(' </obj>',/,'</objectives>')
 1010 format(' <matrices numberOfMatrices="',I0,'">')
 1011 format(' <linearMatrix id="X',I0,'" numberOfColumns="',I0,                &
     &       '" numberOfRows="',I0,'" symmetric="true" numberOfEl="0"',        &
     &       ' varIdxStart="',I0,'" varIdxEnd="',I0,'"/>')
 1012 format(' <constantMatrix id="F',I0,':',I0,'" numberOfColumns="',I0,    &
     &       '" numberOfRows="',I0,'" numberOfEl="',I0,'">')
 1013 format(' <elements>',/,'<start>')
 1014 format(' <el>',I0,'</el>')
 1015 format(' </start>',/,'<rowIdx>')
 1016 format(' </rowIdx>',/,'<value>')
 1017 format(' <el>',G30.15,'</el>')
 1018 format(' </value>',/,'</elements>',/,'</constantMatrix>')
 1019 format(' </matrices>')
 1020 format(' <cones numberOfCones="',I0,'">')
 1021 format(' <semidefiniteCone id="C',I0,'" numberOfColumns="',I0,         &
     &                                    '" numberOfRows="',I0,'"/>')
 1022 format(' </cones>')
 1023 format(' <matrixProgramming>',/,                                         &
     &       ' <matrixVariables numberOfMatrixVariables="',I0,'">')
 1024 format(' <matrixVar matrixID="X',I0,'" lbConeId="C',I0,'"/>')
 1025 format(' </matrixVariables>')
 1026 format(' <matrixConstraints numberOfMatrixConstraints="',I0,'">')
 1027 format(' <matrixCon numberOfRows="1" numberOfCols="1" lbMatrixID="F0',I0,  &
     &       '" ubMatrixID="F0',I0,'"/>')                
 1028 format(' </matrixConstraints>')
 1029 format(' <linearConstraintMatrixOperators numberOfOperators="',I0,'">')
 1030 format(' <matrixVarOperator matrixVarIdx="',I0,'" matrixConIdx="',I0,  &
     &       '" scalarCoef="-1"/>')
 1031 format(' <scalarVarOperator varIdx="',I0,'" matrixConIdx="',I0,        &
     &       '" matrixID="F',I0,':',I0,'"/>')
 1032 format(' </linearConstraintMatrixOperators>')
 1033 format(' </matrixProgramming>',/,'</instanceData>',/,'</osil>')

 1100 format(a)
 1900 format(' ERROR: Input file improperly formed')
      end
