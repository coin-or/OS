
/* ---------------------------------------------------------------- */
/*               KNITRO DRIVER FOR C/C++ INTERFACE                  */
/* ---------------------------------------------------------------- */

#include "org_optimizationservices_ossolver_solver_KnitroSolver.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h> 
#include <jni.h>
#include "knitro.h"
#include "driverC.h"  

 

// global JNI variables
jfieldID jfid;
jclass cls;
JNIEnv *globalJavaEnv;
jobject globalJavaObject;
jmethodID javaEvalfcID;
jmethodID javaEvalgaID;

JNIEXPORT void JNICALL
Java_org_optimizationservices_ossolver_solver_KnitroSolver_nativeMain
(
    JNIEnv *env, 
    jobject obj,
    jint n,
    jint m,
    jint nnzj,
    jint nnzh,
    jint ftype,
    jdoubleArray jbl,
    jdoubleArray jbu,
    jdoubleArray jcl,
    jdoubleArray jcu,
    jintArray jctype,
    jdoubleArray jx,
    jintArray jindvar,
    jintArray jindfun
)
{
    /* Declare variables which are passed to function KTR_solve(). */
   
    int  *hrow, *hcol;
    double *fgrad, *c, *cjac, *lambda, *hess,   *vector;
    jdouble *bl, *bu, *cl, *cu, *x;
    jint *ctype, *indvar, *indfun;
    double f;
  
    /* KNITRO context pointer */
    KTR_context *kc;
  
    /* Declare other variables. */ 
    int i, j, k, errorflag, status;
    int hessopt, gradopt;
    double *tmp;

    
    // set the global JNI variables so we can use anywhere
    globalJavaEnv = env;
    globalJavaObject = obj;  
    cls = (*globalJavaEnv)->GetObjectClass(globalJavaEnv, globalJavaObject);
    javaEvalfcID = (*globalJavaEnv)->GetMethodID(globalJavaEnv, cls, "javaEvalfc", "([D[D)D");
    javaEvalgaID = (*globalJavaEnv)->GetMethodID(globalJavaEnv, cls, "javaEvalga", "([D[D[D)V");
    
    
    /* Create a new problem instance */
    /* (install_interrupt_handler) */
    kc = KTR_new(1); 
    if(kc == NULL) {
      fprintf (stderr, "Failure to get license.\n");
      exit(1);
    }
  
    /* Three redundant examples of setting a parameter */
    errorflag = KTR_set_int_param_by_name(kc,"algorithm", KTR_ALG_IPCG);
    if (errorflag) {
      fprintf (stderr, "Failure to set param. %d file=%s line=%d\n",
               errorflag,__FILE__,__LINE__);
      exit(1);
    }
    errorflag = KTR_set_int_param(kc,KTR_PARAM_ALGORITHM, KTR_ALG_IPCG);
    if (errorflag) {
      fprintf (stderr, "Failure to set param. %d file=%s line=%d\n",
               errorflag,__FILE__,__LINE__);
      exit(1);
    }
    errorflag = KTR_set_char_param_by_name(kc,"algorithm", "cg");
    if (errorflag) {
      fprintf (stderr, "Failure to set param. %d file=%s line=%d\n",
               errorflag,__FILE__,__LINE__);
      exit(1);
    }
    
    errorflag = KTR_set_int_param(kc, KTR_PARAM_HESSOPT, 4);
    if (errorflag) {
      fprintf (stderr, "Failure to set param. %d file=%s line=%d\n",
               errorflag,__FILE__,__LINE__);
      exit(1);
    }
  
    /* Here we read and write our whole config to a file, for easy */
    /* runtime changing and debugging. */
    /* (uncomment the lines below to read or write an options file) */
    /*KTR_load_param_file(kc,"knitro.opt");*/
    /*KTR_save_param_file(kc,"knitro.opt");*/

  
    /* Get the Hessian option used */
    errorflag = KTR_get_int_param(kc,KTR_PARAM_HESSOPT,&hessopt);
    if (errorflag) {
      fprintf (stderr, "Failure to get param. %d file=%s line=%d\n",
               errorflag,__FILE__,__LINE__);
      exit(1);
    }
  

    /* Allocate arrays that get passed to KTR_solve */  
    //x         = (double *)malloc(n*sizeof(double));
    fgrad     = (double *)malloc(n*sizeof(double));
    c         = (double *)malloc(m*sizeof(double));
    cjac      = (double *)malloc(nnzj*sizeof(double));
    //indvar    = (int *)malloc(nnzj*sizeof(int));  
    //indfun    = (int *)malloc(nnzj*sizeof(int));
    lambda    = (double *)malloc((m+n)*sizeof(double));
    //bl        = (double *)malloc(n*sizeof(double));
    //bu         = (double *)malloc(n*sizeof(double));
    //ctype     = (int *)malloc(m*sizeof(int));
    //cl        = (double *)malloc(m*sizeof(double));
    //cu        = (double *)malloc(m*sizeof(double));

    /* Arrays only needed for exact Hessian */
    if (hessopt == 1) {
      hess      = (double *)malloc(nnzh*sizeof(double));
      hrow      = (int *)malloc(nnzh*sizeof(int));
      hcol      = (int *)malloc(nnzh*sizeof(int));
    }
    

    /* Arrays only needed for exact Hessian-vector products */
    if (hessopt == 5) {
      vector    = (double *)malloc(n*sizeof(double)); 
      tmp       = (double *)malloc(n*sizeof(double));
    }

    /* Arrays only needed if performing gradient check */
    errorflag = KTR_get_int_param(kc,KTR_PARAM_GRADOPT,&gradopt);
    if (errorflag) {
      fprintf (stderr, "Failure to get param. %d file=%s line=%d\n",
               errorflag,__FILE__,__LINE__);
      exit(1);
    }
 
    bl = (*globalJavaEnv)->GetDoubleArrayElements(globalJavaEnv, jbl, NULL);
    bu = (*globalJavaEnv)->GetDoubleArrayElements(globalJavaEnv, jbu, NULL);
    cl = (*globalJavaEnv)->GetDoubleArrayElements(globalJavaEnv, jcl, NULL);
    cu = (*globalJavaEnv)->GetDoubleArrayElements(globalJavaEnv, jcu, NULL);
    ctype = (*globalJavaEnv)->GetIntArrayElements(globalJavaEnv, jctype, NULL);
    x = (*globalJavaEnv)->GetDoubleArrayElements(globalJavaEnv, jx, NULL);
    indvar = (*globalJavaEnv)->GetIntArrayElements(globalJavaEnv, jindvar, NULL);
    indfun = (*globalJavaEnv)->GetIntArrayElements(globalJavaEnv, jindfun, NULL);
         for (i = 0; i < n; i++) {
         printf("From C, x[ i] = %f \n", x[ i]);
         printf("From C, x[ i] = %f \n", bu[ i]);
     }

    //
  // Hessian stuff if necessary
    /* Specify sparsity info for Hessian (if using exact Hessian)
   *
   * NOTE: Only the NONZEROS of the UPPER TRIANGLE (including 
   *       diagonal) of this matrix should be stored.  
   */

  if (hessopt == 1) {
    hrow[0] = 0;
    hcol[0] = 0;
    
    hrow[1] = 0;
    hcol[1] = 1;
    
    hrow[2] = 0;
    hcol[2] = 2;
    
    hrow[3] = 1;
    hcol[3] = 1;
    
    hrow[4] = 2;
    hcol[4] = 2;
  }
  
  //


    KTR_set_func_callback(kc,&evalfc);

    if (gradopt == 1) {
      KTR_set_grad_callback(kc,&evalga);
    } else {
      fprintf(stderr,"Finite-difference gradient not implemented for callback example.\n");
      exit(1);
    }

    if(hessopt == 5) {
        KTR_set_hess_callback(kc,&evalhessvec);
    } else { 
        KTR_set_hess_callback(kc,&evalhess);
    }

    /* Call KNITRO solver routine */
    status = KTR_solve(kc, &f, ftype, n, x, bl, bu, fgrad, m, c,  
                       cl, cu, ctype, nnzj, cjac, indvar, indfun,
                       lambda, nnzh, hess, hrow, hcol, vector, tmp);


    /* Delete problem instance */
    
  
    KTR_free(&kc);

    free(x);
    free(fgrad);
    free(c);
    free(cjac);
    free(indvar);  
    free(indfun);
    free(lambda);  
    free(bl);
    free(bu);
    free(ctype);
    free(cl);
    free(cu);
    if (hessopt == 1) {
      free(hess);
      free(hrow); 
      free(hcol);
    }
    if (hessopt == 5) {
      free(vector);
      free(tmp);
    }

    return ;
}

/****************************************************/
/**
evalfc is the C call back function -- it just calls the java callback
function javaEvalfc
*/
int evalfc(KTR_context_ptr kc,
    double *f, int ftype, int n, double *x, double *bl, double *bu, double *fgrad,
    int m, double *c, double *cl, double *cu, int *ctype, int nnzj, 
    double *cjac, int *indvar, int *indfun, double *lambda,
    int nnzh, double *hess, int *hrow, int *hcol, double *vector, void *user )
{
  /* Objective function and constraint values for the 
   * given problem.
   */
   double funval;

   /**

   */
   jdouble *jxpt, *jcpt;
   int i;
   if (javaEvalfcID == NULL) {
        return 0; 
    }
    else{
        jdoubleArray jx = (*globalJavaEnv)->NewDoubleArray(globalJavaEnv, n);
        jdoubleArray jc = (*globalJavaEnv)->NewDoubleArray(globalJavaEnv, m);
        /* Allocate the memory for jxpt and jcpt */
        jxpt = (*globalJavaEnv)->GetDoubleArrayElements(globalJavaEnv, jx, 0);
        jcpt = (*globalJavaEnv)->GetDoubleArrayElements(globalJavaEnv, jc, 0);
        for(i = 0; i < n; i++)
        {
            jxpt[ i] = x[ i];
        }
        /* put current solution x[ i] into the java array jx using jxpt */
        (*globalJavaEnv)->ReleaseDoubleArrayElements(globalJavaEnv, jx, jxpt, 0);
        // Now that we have solution vector, call back to Java to evaluate
        //printf("We are in the Knitro Interface, call back to Java \n");
        funval = (*globalJavaEnv)->CallDoubleMethod(globalJavaEnv, globalJavaObject,javaEvalfcID, jx, jc);
        // copy results back to C array
        jcpt = (*globalJavaEnv)->GetDoubleArrayElements(globalJavaEnv, jc, 0);
    }
    
  *f = funval;
  for(i = 0; i < m; i++){
    c[ i] = jcpt[ i];
  }
 // free( jxpt);
 // free( jcpt);

  return 0;
} // end evalfc()
/****************************************************/
int evalga(KTR_context_ptr kc,
    double *f, int ftype, int n, double *x, double *bl, double *bu, double *fgrad,
    int m, double *c, double *cl, double *cu, int *ctype, int nnzj, 
    double *cjac, int *indvar, int *indfun, double *lambda,
    int nnzh, double *hess, int *hrow, int *hcol, double *vector, void *user )
{
  /* Routine for computing gradient values.  Objective gradient
   * "fgrad" specified in dense array of size n, constraint gradients
   * "cjac" in sparse form.
   *
   * NOTE: Only NONZERO constraint gradient elements should be specified.
   */
   jdouble *jxpt, *jfgradpt, *jcjacpt;
   int i;
   if (javaEvalgaID == NULL) {
        return 0; 
    }
    else{
        jdoubleArray jx = (*globalJavaEnv)->NewDoubleArray(globalJavaEnv, n);
        jdoubleArray jfgrad = (*globalJavaEnv)->NewDoubleArray(globalJavaEnv, n);
        jdoubleArray jcjac = (*globalJavaEnv)->NewDoubleArray(globalJavaEnv, nnzj);
        jxpt = (*globalJavaEnv)->GetDoubleArrayElements(globalJavaEnv, jx, 0);
        jfgradpt = (*globalJavaEnv)->GetDoubleArrayElements(globalJavaEnv, jfgrad, 0);
        jcjacpt = (*globalJavaEnv)->GetDoubleArrayElements(globalJavaEnv, jcjac, 0);
        for(i = 0; i < n; i++)
        {
            jxpt[ i] = x[ i];
        }
        /* put current solution x[ i] into the java array jx using jxpt */
        (*globalJavaEnv)->ReleaseDoubleArrayElements(globalJavaEnv, jx, jxpt, 0);
        // Now that we have solution vector, call back to Java to evaluate
        //printf("We are in the Knitro Interface, call back to Java \n");
        (*globalJavaEnv)->CallVoidMethod(globalJavaEnv, globalJavaObject,javaEvalgaID, jx, jfgrad, jcjac);
        // copy results back to C array
        jfgradpt = (*globalJavaEnv)->GetDoubleArrayElements(globalJavaEnv, jfgrad, 0);
        jcjacpt = (*globalJavaEnv)->GetDoubleArrayElements(globalJavaEnv, jcjac, 0);
    }
    

  for(i = 0; i < nnzj; i++){
    cjac[ i] = jcjacpt[ i];
  }
  
  for(i = 0; i < n; i++){
    fgrad[ i] = jfgradpt[ i];
  }
  // why don't the following work???
  //free(jxpt);
  //free(jcjacpt);
  //free(jfgradpt);
  return 0;
} // end evalga
/****************************************************/
int evalhess(KTR_context_ptr kc,
    double *f, int ftype, int n, double *x, double *bl, double *bu, double *fgrad,
    int m, double *c, double *cl, double *cu, int *ctype, int nnzj, 
    double *cjac, int *indvar, int *indfun, double *lambda,
    int nnzh, double *hess, int *hrow, int *hcol, double *vector, void *user )
{
  /*
   * Compute the Hessian of the Lagrangian.
   *  
   * NOTE: Only the NONZEROS of the UPPER TRIANGLE (including 
   *       diagonal) of this matrix should be stored.  
   */
    /*
  hess[0] = 2.0e0*(lambda[1]-1.0e0);
  hess[1] = -1.0e0;
  hess[2] = -1.0e0;
  hess[3] = 2.0e0*(lambda[1]-2.0e0);
  hess[4] = 2.0e0*(lambda[1]-1.0e0);
*/
  return 0;
}
/****************************************************/
int evalhessvec(KTR_context_ptr kc,
    double *f, int ftype, int n, double *x, double *bl, double *bu, double *fgrad,
    int m, double *c, double *cl, double *cu, int *ctype, int nnzj, 
    double *cjac, int *indvar, int *indfun, double *lambda,
    int nnzh, double *hess, int *hrow, int *hcol, double *vector, void *user )
{
  double *tmp = user;
  /*
   * Compute the Hessian of the Lagrangian times "vector"
   * and store the result in "vector".
   */
/*
  int i;

  tmp[0] = 2.0e0*(lambda[1]-1.0e0)*vector[0] - vector[1] - vector[2];
  tmp[1] = -vector[0] + 2.0e0*(lambda[1]-2.0e0)*vector[1];
  tmp[2] = -vector[0] + 2.0e0*(lambda[1]-1.0e0)*vector[2];

  for (i=0; i<n; i++) {
    vector[i] = tmp[i];
  }   
  */ 
  return 0;
}
/****************************************************/
