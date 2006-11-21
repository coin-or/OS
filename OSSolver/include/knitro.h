/* Copyright (c) 2001-2004 Ziena Optimization Inc. */

/* KNITRO 4.x header file */

#ifndef KNITRO_H___
#define KNITRO_H___

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
# ifdef MAKE_KNITRO_DLL
#  define KNITRO_4_API __declspec(dllexport) __stdcall
# else
//#  define KNITRO_4_API __declspec(dllimport) __stdcall
#  define KNITRO_4_API __stdcall
# endif
#else
# define KNITRO_4_API
#endif

/* KNITRO data types */
typedef struct KTR_context KTR_context, *KTR_context_ptr;   

/* ----  creating and destroying objects ---- */

/* Call this function first.  It returns an object that is used for every other call. */
/* The KNITRO license is reserved until the last KTR_context_ptr has KTR_free() */
/* called for it, or the program ends. */
/* If install_interrupt_handler is nonzero, KNITRO will be able to free a */
/* network license on abnormal program termination. */
KTR_context_ptr KNITRO_4_API KTR_new(int install_interrupt_handler);

/* Free work memory and close files associated with a context. */
/* The context pointer can still be used to solve another problem, */
/* and keeps all its settings.  The context pointer still retains the */
/* license, if a floating license is used. */
int KNITRO_4_API KTR_free_tempwork(KTR_context_ptr kc);

/* Free the context. */
/* You actually pass the address of your pointer so */
/* that KNITRO can clobber it to NULL.  This helps to avoid mistakes.  */
/* If this was the last context, the license is freed. */
int KNITRO_4_API KTR_free(KTR_context_ptr *kc_handle);

/* This is only used for legacy compatability */
/* This function returns the global context used by the legacy */
/* KNITRO 3.1 API below. */
KTR_context_ptr KNITRO_4_API KTR_legacy_3_context(void);

/* ----- changing and reading object parameters ---- */

/* Many integer parameter are just multiple choice, so each one of */
/* those choices has a name that can be used with KTR_set_char_command. */
/* They return non-zero on error. */
/* The _by_name routines take a name string like names used in the spec file. */
int KNITRO_4_API KTR_set_int_param(KTR_context_ptr kc,int which_param,int value);
int KNITRO_4_API KTR_set_int_param_by_name(KTR_context_ptr kc,char const * param_name,int value);
int KNITRO_4_API KTR_set_char_param_by_name(KTR_context_ptr kc,char const * param_name,
                               char const *value);
int KNITRO_4_API KTR_set_double_param(KTR_context_ptr kc,int which_param,double value);
int KNITRO_4_API KTR_set_double_param_by_name(KTR_context_ptr kc,char const * param_name,
                                 double value);
int KNITRO_4_API KTR_get_int_param(KTR_context_ptr kc,int which_param,int *value);
int KNITRO_4_API KTR_get_int_param_by_name(KTR_context_ptr kc,char const * name,int *value);
int KNITRO_4_API KTR_get_double_param(KTR_context_ptr kc,int which_param,double *value);
int KNITRO_4_API KTR_get_double_param_by_name(KTR_context_ptr kc,char const * name,double *value);

/* These return 0 on sucess and -1 on error. */
int KNITRO_4_API KTR_load_param_file(KTR_context_ptr kc,char const * filename);
int KNITRO_4_API KTR_save_param_file(KTR_context_ptr kc,char const * filename);
int KNITRO_4_API KTR_load_param_filep(KTR_context_ptr kc,FILE *fp);
int KNITRO_4_API KTR_save_param_filep(KTR_context_ptr kc,FILE *fp);

int KNITRO_4_API KTR_reset_params_to_defaults(KTR_context *kc);

/* ----- solving ---- */

/* There are two ways to solve.  One is called reverse communication */
/* where you call KTR_solve() repeatedly until it returns with a done */
/* code (zero or less).  If KTR_solve() returns with a */
/* positive code, it means you need to evaluate objective/constraint */
/* functions, gradients, or the Hessian then call KTR_solve() again. */

/* The other way to solve is callbacks, where you give KNITRO */
/* several function pointers that KNITRO uses when it needs new */
/* function/gradient/Hessian values.   KTR_solve() still requires */
/* valid addresses for x, bl, bu, etc. so they can be passed to */
/* the callbacks. */

/* For convenience every callback receives every parameter.  It is */
/* fine to populate extra parameters early, for example assigning the gradient */
/* in the objective value callback, but you will still need to define */
/* a gradient callback function that does nothing, or KTR_solve() */
/* will return with KTR_RC_EVALGA (2).  KNITRO has separate */
/* callbacks for efficiency, because if a trial point is worse */
/* than the current point, the step is rejected and the gradient and */
/* Hessian values at the trial point are not used. */

/* If your callback requires additional parameters, you are encouraged */
/* to create a struct of them, and pass its address with the "user" pointer. */
/* KNITRO does not modify or dereference the user pointer, so it is */
/* safe to use for this purpose. */



/* The return values are... 
    6    newpoint "callback"
    4    need evaluation of functions f and c and gradients fgrad and cjac
    3    need evaluation of hessian hess or hessian-vector product
    2    need evaluation of gradients fgrad and cjac 
    1    need evaluation of functions f and c
    0    done. locally optimal value found
   -1    done. iteration limit reached
   -2    done. convergence to infeasible point.  Problem may
               be locally infeasible.
   -3    done. problem appears unbounded
   -4    done. current point cannot be improved.
   -5    done. current point cannot be improved.  It appears to be
               optimal, but desired accuracy could not be achieved. 
   -6    done. time limit reached.
  -50 to -60  done. some kind of input error.
  -90   done. Callback error.
  -97   done. LP solver error.
  -98   done. evaluation error.
  -99   done. out of memory.

*/
int KNITRO_4_API KTR_solve(KTR_context *kc,
    double *f,      /* (scalar) Objective function value, passed by address */
    int ftype,      /* (scalar) Indicates type of objective */
    int n,          /* (scalar) The number of unknowns  */
    double *x,      /* (length n, vector) The unknowns (input/output) */
    double *bl,     /* (length n, vector) lower bounds on the unknowns */
    double *bu,     /* (length n, vector) upper bounds on the unknowns */
    double *fgrad,  /* (length n, vector) gradient of the objective, (1st derivative) */
    int m,          /* (scalar) The number of general constraints */
    double *c,      /* (length m, vector) results of the general constraint functions */
    double *cl,     /* (length m, vector) lower bounds on general constraint functions, c */
    double *cu,     /* (length m, vector) upper bounds on general constraint functions, c */
    int *ctype,     /* (length m, vector) indicate type of constraint */
    int nnzj,       /* (scalar)  number of nonzeros in jacobian */
    double *cjac,   /* (length nnzj, vector) Jacobian of general constraint functions, c (1st derivative) */
    int *indvar,    /* (length nnzj) column (variable index) of sparse jacobian */
    int *indfun,    /* (length nnzj) row (constraint function index) of sparse jacobian */
    double *lambda, /* (length m+n, vector) optimal lagrange multiplier values of x and c (output only) */
    int nnzh,       /* (scalar) number of possible non-zeros in the hessian */
    double *hess,   /* (length nnzh, sparse matrix) upper right triangle of the hessian of the lagrangian */
    int *hrow,      /* (length nnzh) row index of sparse hessian */
    int *hcol,      /* (length nnzh) column index of sparse hessian */
    double *vector, /* (length n) hessian vector products */
    void *user      /* pointer passed to objective function callback */
);

/* define callback prototype */
typedef int KTR_callback(KTR_context_ptr kc,
    double *f, int ftype, int n, double *x, double *bl, double *bu, double *fgrad,
    int m, double *c, double *cl, double *cu, int *ctype, int nnzj, 
    double *cjac, int *indvar, int *indfun, double *lambda,
    int nnzh, double *hess, int *hrow, int *hcol, double *vector, void *user );

typedef KTR_callback *KTR_callback_ptr;

/* This callback should modify f and c */
int KNITRO_4_API KTR_set_func_callback(KTR_context_ptr kc,KTR_callback *func);

/* This callback should modify fgrad and cjac */
int KNITRO_4_API KTR_set_grad_callback(KTR_context_ptr kc,KTR_callback *func);

/* This callback should modify hess or vector, */
/* depending on which hessopt you are using. */
int KNITRO_4_API KTR_set_hess_callback(KTR_context_ptr kc,KTR_callback *func);

/* This callback should modify nothing. */
/* It can be used for updating your graphical user inteface. */
int KNITRO_4_API KTR_set_newpoint_callback(KTR_context_ptr kc,KTR_callback *func);

/* By default KNITRO prints to stdout or a "knitro.out" file. */
/* This is controlled with the KTR_PARAM_OUTMODE option. */
/* Alternatively you can define a callback function which handles */
/* this output */

typedef int KTR_puts(char *str,void *user);

typedef KTR_puts *KTR_puts_ptr;

int KNITRO_4_API KTR_set_puts_callback(KTR_context_ptr kc,KTR_puts *puts_func);


/* ----- constants ---- */

/* Any numbers greater than or equal to KTR_INFBOUND in magnitude 
   are treated as infinite by KNITRO */
#define KTR_INFBOUND 1.0e20

/* Define some flag values used by KNITRO for reverse communication.
   These are return codes normally, but the ones beginning at 90 
   are used as input codes if something goes bad. */
#define KTR_RC_INITIAL    0
#define KTR_RC_EVALFC     1
#define KTR_RC_EVALGA     2
#define KTR_RC_EVALH      3
#define KTR_RC_EVALX0     4
#define KTR_RC_FINISHED   5
#define KTR_RC_NEWPOINT   6
#define KTR_RC_EVALHV     7
#define KTR_RC_BADFC     91
#define KTR_RC_BADGA     92
#define KTR_RC_BADH      93
#define KTR_RC_BADX0     94
#define KTR_RC_TERMINATE 99

#define KTR_RC_OPTIMAL         0
#define KTR_RC_ITER_LIMIT     -1
#define KTR_RC_INFEASIBLE     -2
#define KTR_RC_UNBOUNDED      -3
#define KTR_RC_NO_IMPROVE     -4
#define KTR_RC_XTOL_ERR       -4
#define KTR_RC_NEAR_OPT       -5
#define KTR_RC_TIME_LIMIT     -6
#define KTR_RC_CALLBACK_ERR  -90
#define KTR_RC_LP_SOLVER_ERR -97
#define KTR_RC_EVAL_ERR      -98
#define KTR_RC_OUT_OF_MEMORY -99



#define KTR_PARAM_NEWPOINT       1001
/* KTR_PARAM_CALLBACK is depreciated.  Do not use. */
#define KTR_PARAM_CALLBACK       1001
#define KTR_PARAM_HONORBNDS      1002
#define KTR_PARAM_ALG            1003
#define KTR_PARAM_ALGORITHM      1003
#  define KTR_ALG_AUTOMATIC         0
#  define KTR_ALG_AUTO              0
#  define KTR_ALG_IPDIRECT          1
#  define KTR_ALG_IPCG              2
#  define KTR_ALG_ACTIVE            3
#define KTR_PARAM_BARRULE        1004
#  define KTR_BARRULE_AUTOMATIC     0
#  define KTR_BARRULE_AUTO          0
#  define KTR_BARRULE_MONOTONE      1
#  define KTR_BARRULE_ADAPTIVE      2
#  define KTR_BARRULE_PROBING       3
#  define KTR_BARRULE_DAMPMPC       4
#  define KTR_BARRULE_FULLMPC       5
#  define KTR_BARRULE_QUALITYF      6
#define KTR_PARAM_FEASIBLE       1006
#  define KTR_FEASIBLE_NO           0
#  define KTR_FEASIBLE_ALWAYS       1
#define KTR_PARAM_GRADOPT        1007
#  define KTR_GRADOPT_EXACT         1
#  define KTR_GRADOPT_FORWARD       2
#  define KTR_GRADOPT_CENTRAL       3
#  define KTR_GRADOPT_FORWARD_CHECK 4
#  define KTR_GRADOPT_CENTRAL_CHECK 5
#define KTR_PARAM_HESSOPT        1008
#  define KTR_HESSOPT_EXACT         1
#  define KTR_HESSOPT_BFGS          2
#  define KTR_HESSOPT_SR1           3
#  define KTR_HESSOPT_FINITE_DIFF   4
#  define KTR_HESSOPT_PRODUCT       5
#  define KTR_HESSOPT_LBFGS         6
#define KTR_PARAM_INITPT         1009
#  define KTR_INITPT_NO             0
#  define KTR_INITPT_YES            1
#define KTR_PARAM_ISLP           1010
#  define KTR_ISLP_MAYBE            0
#  define KTR_ISLP_YES              1
#define KTR_PARAM_ISQP           1011
#  define KTR_ISQP_MAYBE            0
#  define KTR_ISQP_YES              1
#define KTR_PARAM_LPSOLVER       1012
#  define KTR_LP_INTERNAL           1
#  define KTR_LP_CPLEX              2
#define KTR_PARAM_MAXCGIT        1013
#define KTR_PARAM_MAXIT          1014
#define KTR_PARAM_OUTLEV         1015
#  define KTR_OUTLEV_NONE           0
#  define KTR_OUTLEV_SUMMARY        1
#  define KTR_OUTLEV_MAJORIT10      2
#  define KTR_OUTLEV_MAJORIT        3
#  define KTR_OUTLEV_ALLIT          4
#  define KTR_OUTLEV_ALLIT_X        5
#  define KTR_OUTLEV_ALL            6
#define KTR_PARAM_OUTMODE        1016
#define KTR_PARAM_SCALE          1017
#  define KTR_SCALE_NEVER           0
#  define KTR_SCALE_ALLOW           1
#define KTR_PARAM_SHIFTINIT      1018
#  define KTR_SHIFTINIT_NO          0
#  define KTR_SHIFTINIT_YES         1
#define KTR_PARAM_SOC            1019
#  define KTR_SOC_NO                0
#  define KTR_SOC_YES               1
#define KTR_PARAM_DELTA          1020
#define KTR_PARAM_FEASMODETOL    1021
#define KTR_PARAM_FEASTOL        1022
#define KTR_PARAM_FEASTOLABS     1023
#define KTR_PARAM_MAXTIME        1024
#define KTR_PARAM_MU             1025
#define KTR_PARAM_OBJRANGE       1026
#define KTR_PARAM_OPTTOL         1027
#define KTR_PARAM_OPTTOLABS      1028
#define KTR_PARAM_PIVOT          1029
#define KTR_PARAM_XTOL           1030

  
#ifdef __cplusplus
}
#endif

#endif