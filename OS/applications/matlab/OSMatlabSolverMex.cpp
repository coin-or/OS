
#include <iostream>
#include <string>
#include "mex.h"



// OS includes
#include "OSDataStructures.h"
//#include "OSParameters.h"
#include "OSMatlabSolver.h"



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
     OSMatlab *matlabModel = new OSMatlab();
     string sTest = "";
     char *buf;
     SparseMatrix* getConstraintMatrix( const mxArray *prhs);
     //
     // Check for proper number of input and output arguments
     mexPrintf("BEGIN PROCESSING DATA\n");
     if (nrhs != 15) {
          mexErrMsgTxt("Fifteen input arguments are required.");
     }
     
     
     //
     // get number of variables and number of constraints
     matlabModel->numVar =  (int) mxGetScalar( prhs[ 0]) ;
     //printf("variable numVar = %i\n",  matlabModel->numVar );
     matlabModel->numCon = (int) mxGetScalar( prhs[ 1]);
     //
     // get the constraint matrix
     // check the data type
     if (!(mxIsDouble(prhs[2 ]))){
          mexErrMsgTxt("Constraint matrix A must be of type double.");
     }
     // check the dimension
     if ( (mxGetN(prhs[ 2]) != matlabModel->numVar) ||  (mxGetM(prhs[2]) != matlabModel->numCon) ){
          mexErrMsgTxt(" Constraint matrix A must have number of rows equal to number of constraints and columns equal number of variables \n");
     }
     matlabModel->sparseMat = getConstraintMatrix( prhs[2])   ;
     // get the rest of the model
     //
     // both bl and bu should equal the number of rows
     //
     if(  !mxIsEmpty( prhs[ 3]) ){
          if (mxGetN(prhs[3]) != matlabModel->numCon ){
               mexErrMsgTxt(" Vector BL size must equal the number of rows\n");
          }
          matlabModel->bl =  mxGetPr( prhs[ 3]);
          // convert Matlab -infinity to OS -infinity
          for(i = 0;  i < matlabModel->numCon;  i++){
               if(  mxIsInf(  -(matlabModel->bl[i]) ) ) matlabModel->bl[ i] = -OSDBL_MAX;
          }
     }
     //
     //
     if(  !mxIsEmpty( prhs[ 4]) ){
          if (mxGetN(prhs[4]) != matlabModel->numCon ){
               mexErrMsgTxt(" Vector BU size must equal the number of rows\n");
          }
          matlabModel->bu =  mxGetPr( prhs[ 4]);
          // convert Matlab infinity to OS infinity
          for(i = 0;  i < matlabModel->numCon;  i++){
               if(  mxIsInf( matlabModel->bu[i]) ) matlabModel->bu[ i] = OSDBL_MAX;
          }
     }
     //
     //
     if (mxGetN(prhs[5]) != matlabModel->numVar ){
          mexErrMsgTxt(" Vector OBJ size must equal the number of variables\n");
     }
     matlabModel->obj =  mxGetPr( prhs[ 5]);
     //
     //
     if(  !mxIsEmpty( prhs[ 6]) ){
          if (mxGetN(prhs[6]) != matlabModel->numVar ){
               mexErrMsgTxt(" Vector VL size must equal the number of variables\n");
          }
          matlabModel->vl =  mxGetPr( prhs[ 6]);
          // convert Matlab -infinity to OS -infinity
          for(i = 0;  i < matlabModel->numVar;  i++){
              //printf("variable lb = %f\n",  matlabModel->vl[i] );
               if(  mxIsInf(  -(matlabModel->vl[i]) ) ) matlabModel->vl[ i] = -OSDBL_MAX;
          }
     }
     //
     //
     if(  !mxIsEmpty( prhs[ 7]) ){
          if (mxGetN(prhs[7]) != matlabModel->numVar ){
               mexErrMsgTxt(" Vector VU size must equal the number of variables\n");
          }
          matlabModel->vu =  mxGetPr( prhs[ 7]);
          // convert Matlab infinity to OS infinity
          for(i = 0;  i < matlabModel->numVar;  i++){
              //printf("variable ub = %f\n",  matlabModel->vu[i] );
               if(  mxIsInf( matlabModel->vu[i]) ) matlabModel->vu[ i] = OSDBL_MAX;
          }
     }
     //
     //
     if ( (mxGetScalar( prhs[ 8]) != 0) && (mxGetScalar( prhs[ 8]) != 1)){
          mexErrMsgTxt(" The objective type must be either 1 (max) or 0 (min)\n");
     }
     mxGetScalar( prhs[ 8]) > 0 ?  matlabModel->objType = 1 : matlabModel->objType = 0; 
     //printf("Objective Function Type = %d\n", matlabModel->objType);
     //
     // get the variable types, this is character data
     if(!mxIsChar( prhs[ 9])){
          mexErrMsgTxt(" Vector VarType  must be a character array\n");
     }
     if (mxGetN(prhs[ 9]) != matlabModel->numVar ){
          mexErrMsgTxt(" Vector VarType size must equal the number of variables\n");
     }
     buf = mxArrayToString( prhs[ 9]);
     matlabModel->varType = buf;
     
     //
     // get the quadratic terms
     
     int j;
     int k = 0;
     if(  !mxIsEmpty( prhs[ 10]) ){
          if( mxGetM( prhs[ 10])  != 4) mexErrMsgTxt(" Vector Q Must have 4 rows\n");
          int numQTerms = mxGetN( prhs[ 10]);
          //printf("NUMBER OF Q TERMS =  %d \n", numQTerms);
          matlabModel->numQTerms = numQTerms;
          matlabModel->qRows = new int[ numQTerms];
          matlabModel->qIndex1 = new int[ numQTerms];
          matlabModel->qIndex2 = new int[ numQTerms];
          matlabModel->qVal = new double[ numQTerms];
          pr= mxGetPr( prhs[ 10]);
          for(i = 0; i < numQTerms; i++){
               for(j = 0; j <= 3; j++){
                    //printf(" Q COMP = %f\n", pr[ k]) ;
                    switch( j){
                         case 0:
                              matlabModel->qRows[ i] = (int) pr[ k];
                              break;
                         case 1:
                              matlabModel->qIndex1[ i] = (int) pr[ k];
                              break;
                         case 2:
                              matlabModel->qIndex2[ i] = (int) pr[ k];
                              break;
                         case 3:
                              matlabModel->qVal[ i] =  pr[ k];
                              break;
                    }
                    k++;
               }
          }
     }
     if(  !mxIsEmpty( prhs[ 11]) ){
           matlabModel->instanceName = mxArrayToString( prhs[ 11]);
     }
     //
     buf = mxArrayToString( prhs[ 12]);
     const char *password = "chicagoesmuyFRIO";
     if( strcmp(buf,  password) != 0) mexErrMsgTxt(" Incorrect Password\n");
     //
     // get the name of the solver
      matlabModel->sSolverName = mxArrayToString( prhs[ 13]);    
      printf("WE ARE USING SOLVER %s\n", &matlabModel->sSolverName[0]);
     //
     // get the name of the solver service
      matlabModel->sAgentAddress = mxArrayToString( prhs[ 14]);    
      printf("WE ARE USING AGENT %s\n", &matlabModel->sAgentAddress[0]);
     //
     // create the OSInstance
     mexPrintf("CREATE THE INSTANCE \n");
     matlabModel->createOSInstance();
     mexPrintf("CALL THE REMOTE SERVER \n");
     sTest = matlabModel->solve();
     std::string osil = matlabModel->osil;
     char *ch = &osil[0];
    printf("HERE IS THE INSTANCE %s\n", ch);
    mexPrintf("DONE WITH THE REMOTE CALL \n");
     mexPrintf("HERE IS THE SOLUTION \n");
     mexPrintf(&sTest[0] );
    //char *str[100];
     //plhs[0]= mxCreateCharMatrixFromStrings(  1,    (const char **)str); 
     //plhs = 'DOES THIS WORK';
     // garbage collection
      char *str[ 1];
      //str[ 0] = mxArrayToString( prhs[ 9]);
      str[ 0] = &sTest[0] ;
      plhs[0]= mxCreateCharMatrixFromStrings( 1, (const char **)str); 
     delete matlabModel;
     return  ;
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