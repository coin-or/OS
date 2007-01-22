
#include <iostream>
#include <string>
#include "mex.h"
#include <stdlib.h>
#include "OSMatlab.h"
#include "OSDataStructures.h"
#include "OSParameters.h"



/* If you are using a compiler that equates NaN to be zero, you must
 * compile this example using the flag  -DNAN_EQUALS_ZERO. For example:
 *
 *     mex -DNAN_EQUALS_ZERO fulltosparse.c
 *
 * This will correctly define the IsNonZero macro for your C compiler.
 */

#if defined(NAN_EQUALS_ZERO)
#define IsNonZero(d) ((d)!=0.0 || mxIsNaN(d))
#else
#define IsNonZero(d) ((d)!=0.0)
#endif

using namespace std;
using std::cout;
using std::endl;


void mexFunction( int  nlhs, mxArray   *plhs[], int  nrhs, const mxArray *prhs[] ) {
   /**
    * The parameters are:
    * A -- the constraint matrix
    * BU -- upper bounds on the constraints
    * BL -- lower bounds on the  constraints
    * C -- objective function vector
    * VL -- lower bounds on the variables
    * VU -- upper bounds on the variables
    * ObjType -- 1 for max, 0 for min
    */
     int i;
     double *pr;
     OSMatlab *d = new OSMatlab();
     string sTest = "";
     char *buf;
     SparseMatrix* getConstraintMatrix( const mxArray *prhs);
     //
     // Check for proper number of input and output arguments
     mexPrintf("BEGIN PROCESSING DATA\n");
     if (nrhs != 12) {
          mexErrMsgTxt("Twelve input arguments are required.");
     }
     
     
     //
     // get number of variables and number of constraints
     d->numVar =  (int) mxGetScalar( prhs[ 0]) ;
     d->numCon = (int) mxGetScalar( prhs[ 1]);
     //
     // get the constraint matrix
     // check the data type
     if (!(mxIsDouble(prhs[2 ]))){
          mexErrMsgTxt("Constraint matrix A must be of type double.");
     }
     // check the dimension
     if ( (mxGetN(prhs[ 2]) != d->numVar) ||  (mxGetM(prhs[2]) != d->numCon) ){
          mexErrMsgTxt(" Constraint matrix A must have number of rows equal to number of constraints and columns equal number of variables \n");
     }
     d->sparseMat = getConstraintMatrix( prhs[2])   ;
     // get the rest of the model
     //
     // both bl and bu should equal the number of rows
     //
     if(  !mxIsEmpty( prhs[ 3]) ){
          if (mxGetN(prhs[3]) != d->numCon ){
               mexErrMsgTxt(" Vector BL size must equal the number of rows\n");
          }
          d->bl =  mxGetPr( prhs[ 3]);
          // convert Matlab -infinity to OS -infinity
          for(i = 0;  i < d->numCon;  i++){
               if(  mxIsInf(  -(d->bl[i]) ) ) d->bl[ i] = -OSINFINITY;
          }
     }
     //
     //
     if(  !mxIsEmpty( prhs[ 4]) ){
          if (mxGetN(prhs[4]) != d->numCon ){
               mexErrMsgTxt(" Vector BU size must equal the number of rows\n");
          }
          d->bu =  mxGetPr( prhs[ 4]);
          // convert Matlab infinity to OS infinity
          for(i = 0;  i < d->numCon;  i++){
               if(  mxIsInf( d->bu[i]) ) d->bu[ i] = OSINFINITY;
          }
     }
     //
     //
     if (mxGetN(prhs[5]) != d->numVar ){
          mexErrMsgTxt(" Vector OBJ size must equal the number of variables\n");
     }
     d->obj =  mxGetPr( prhs[ 5]);
     //
     //
     if(  !mxIsEmpty( prhs[ 6]) ){
          if (mxGetN(prhs[6]) != d->numVar ){
               mexErrMsgTxt(" Vector VL size must equal the number of variables\n");
          }
          d->vl =  mxGetPr( prhs[ 6]);
          // convert Matlab -infinity to OS -infinity
          for(i = 0;  i < d->numVar;  i++){
               if(  mxIsInf(  -(d->vl[i]) ) ) d->vl[ i] = -OSINFINITY;
          }
     }
     //
     //
     if(  !mxIsEmpty( prhs[ 7]) ){
          if (mxGetN(prhs[7]) != d->numVar ){
               mexErrMsgTxt(" Vector VU size must equal the number of variables\n");
          }
          d->vu =  mxGetPr( prhs[ 7]);
          // convert Matlab infinity to OS infinity
          for(i = 0;  i < d->numVar;  i++){
               if(  mxIsInf( d->vu[i]) ) d->vu[ i] = OSINFINITY;
          }
     }
     //
     //
     if ( (mxGetScalar( prhs[ 8]) != 0) && (mxGetScalar( prhs[ 8]) != 1)){
          mexErrMsgTxt(" The objective type must be either 1 (max) or 0 (min)\n");
     }
     mxGetScalar( prhs[ 8]) > 0 ?  d->objType = 1 : d->objType = 0; 
     //printf("Objective Function Type = %d\n", d->objType);
     //
     // get the variable types, this is character data
     if(!mxIsChar( prhs[ 9])){
          mexErrMsgTxt(" Vector VarType  must be a character array\n");
     }
     if (mxGetN(prhs[ 9]) != d->numVar ){
          mexErrMsgTxt(" Vector VarType size must equal the number of variables\n");
     }
     buf = mxArrayToString( prhs[ 9]);
     d->varType = buf;
     
     //
     // get the quadratic terms
     
     int j;
     int k = 0;
     if(  !mxIsEmpty( prhs[ 10]) ){
          if( mxGetM( prhs[ 10])  != 4) mexErrMsgTxt(" Vector Q Must have 4 rows\n");
          int numQTerms = mxGetN( prhs[ 10]);
          //printf("NUMBER OF Q TERMS =  %d \n", numQTerms);
          d->numQTerms = numQTerms;
          d->qRows = new int[ numQTerms];
          d->qIndex1 = new int[ numQTerms];
          d->qIndex2 = new int[ numQTerms];
          d->qVal = new double[ numQTerms];
          pr= mxGetPr( prhs[ 10]);
          for(i = 0; i < numQTerms; i++){
               for(j = 0; j <= 3; j++){
                    //printf(" Q COMP = %f\n", pr[ k]) ;
                    switch( j){
                         case 0:
                              d->qRows[ i] = (int) pr[ k];
                              break;
                         case 1:
                              d->qIndex1[ i] = (int) pr[ k];
                              break;
                         case 2:
                              d->qIndex2[ i] = (int) pr[ k];
                              break;
                         case 3:
                              d->qVal[ i] =  pr[ k];
                              break;
                    }
                    k++;
               }
          }
     }
     if(  !mxIsEmpty( prhs[ 11]) ){
           d->instanceName = mxArrayToString( prhs[ 11]);
     }
     // create the OSInstance
     mexPrintf("CREATE THE INSTANCE \n");
     d->createOSInstance();
     mexPrintf("CALL THE REMOTE SERVER \n");
    sTest = d->display();
     mexPrintf("DONE WITH THE REMOTE CALL \n");
    // mexPrintf(&sTest[0] );
    //char *str[100];
     //plhs[0]= mxCreateCharMatrixFromStrings(  1,    (const char **)str); 
     //plhs = 'DOES THIS WORK';
     // garbage collection
      char *str[ 1];
      //str[ 0] = mxArrayToString( prhs[ 9]);
      str[ 0] = &sTest[0] ;
      plhs[0]= mxCreateCharMatrixFromStrings( 1, (const char **)str); 
     delete d;
     return;
}
SparseMatrix* getConstraintMatrix( const mxArray *prhs){
     SparseMatrix *sparseMat = NULL;
     sparseMat = new SparseMatrix();
    /* Declare variable */
     mxArray *plhs;
     //mwSize m,n;
     // mwSize nzmax;
     //mwIndex *irs, *jcs, j, k;
     int m,n;
     int nzmax;
     int *irs, *jcs, j, k;
     int  cmplx;
     double *pr, *pi, *si, *sr;
    /* Get the size and pointers to input data */
     m  = mxGetM( prhs);
     n  = mxGetN( prhs);
     pr = mxGetPr( prhs);
     pi = mxGetPi( prhs);
     cmplx = (pi==NULL ? 0 : 1);
     nzmax = n*m;
     plhs = mxCreateSparse(m, n, nzmax, (mxComplexity)cmplx);
     sr  = mxGetPr( plhs);
     si  = mxGetPi( plhs);
     irs = mxGetIr( plhs);
     jcs = mxGetJc( plhs);
    /* Copy nonzeros */
     k = 0;
     for (j=0; (j<n); j++) {
          int i;
          jcs[j] = k;
          for (i=0; (i<m ); i++) {
               if (IsNonZero(pr[i]) || (cmplx && IsNonZero(pi[i]))) {
                    sr[k] = pr[i];
                    if (cmplx){
                         si[k]=pi[i];
                    }
                    irs[k] = i;
                    k++;
               }
          }
          pr += m;
          pi += m;
     }
     jcs[ n] = k;
     int km;
     for(j = 0;  j < n;  j++){
          //printf("Column start = %d\n", jcs[ j]);
          for(km = jcs[ j]; km < jcs[ j+1]; km++ ){
               // printf("row index= %d\n",  irs[ km]);
               //  printf("nonzero value = %f\n",   sr[ km]);
          }
     }
     // now fill in a sparse matrix data structure
     sparseMat->bDeleteArrays = false;
     sparseMat->isColumnMajor = true;
     sparseMat->startSize = n + 1;
     sparseMat->valueSize = jcs[ n];
     sparseMat->starts = jcs;
     sparseMat->indexes = irs;
     sparseMat->values = sr;
     return sparseMat;
}