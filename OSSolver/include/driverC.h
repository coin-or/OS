
#ifndef _DRIVERC_H__
#define _DRIVERC_H__

#include "knitro.h"

#ifdef __cplusplus
extern "C" {
#endif

/* define the problem size so the correct amount of memory is allocated. */
void sizes(int *n, int *m, int *nnzj, int *nnzh, int hessopt);

/* Initialize some parameters that do not change during the problem, */
/* such as upper and lower bounds, or sparseness. */
void setup(int n, int m, int nnzj, int nnzh, 
           double *x, double *bl, double *bu,
           int *ftype, int *ctype, double *cl, double *cu,
           int *indvar, int *indfun, int *hrow, int *hcol,
           int gradopt, int hessopt);

/* Evaluate the objective function and the constraint functions. */
int evalfc(KTR_context_ptr kc,
    double *f, int ftype, int n, double *x, double *bl, double *bu, double *fgrad,
    int m, double *c, double *cl, double *cu, int *ctype, int nnzj, 
    double *cjac, int *indvar, int *indfun, double *lambda,
    int nnzh, double *hess, int *hrow, int *hcol, double *vector, void *user );

/* Evaluate the gradient of the objective and jacobian (gradient of contraints) */
int evalga( KTR_context_ptr kc,
    double *f, int ftype, int n, double *x, double *bl, double *bu, double *fgrad,
    int m, double *c, double *cl, double *cu, int *ctype, int nnzj, 
    double *cjac, int *indvar, int *indfun, double *lambda,
    int nnzh, double *hess, int *hrow, int *hcol, double *vector, void *user );

/* Evaluate the hessian of the lagrangian function */
int evalhess(KTR_context_ptr kc,
    double *f, int ftype, int n, double *x, double *bl, double *bu, double *fgrad,
    int m, double *c, double *cl, double *cu, int *ctype, int nnzj, 
    double *cjac, int *indvar, int *indfun, double *lambda,
    int nnzh, double *hess, int *hrow, int *hcol, double *vector, void *user );

/* Evaluate the hessian vector product */
int evalhessvec( KTR_context_ptr kc,
    double *f, int ftype, int n, double *x, double *bl, double *bu, double *fgrad,
    int m, double *c, double *cl, double *cu, int *ctype, int nnzj, 
    double *cjac, int *indvar, int *indfun, double *lambda,
    int nnzh, double *hess, int *hrow, int *hcol, double *vector, void *user );

#ifdef __cplusplus
}
#endif

#endif 
