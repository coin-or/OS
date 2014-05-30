
/* include the COIN-OR-wide system specific configure header */
#include "configall_system.h"

/* include the public project specific macros */
#include "config_os_default.h"

/***************************************************************************/
/*             HERE DEFINE THE PROJECT SPECIFIC MACROS                     */
/*    These are only in effect in a setting that doesn't use configure     */
/***************************************************************************/

/* Define to the debug sanity check level (0 is no test) */
#define COIN_OS_CHECKLEVEL 0

/* Define to the debug verbosity level (0 is no output) */
#define COIN_OS_VERBOSITY 0

/* Define to 1 if the ASL package is available */
#undef COIN_HAS_ASL

/* Define to 1 if the Bcp package is available */
#undef COIN_HAS_BCP

/* Define to 1 if the Bonmin package is available */
#undef COIN_HAS_BONMIN

/* Define to 1 if the Cbc package is available */
#define COIN_HAS_CBC 1

/* Define to 1 if the Cgl package is used */
#define COIN_HAS_CGL 1

/* Define to 1 if the Clp package is used */
#define COIN_HAS_CLP 1

/* Define to 1 if the CoinUtils package is used */
#define COIN_HAS_COINUTILS 1

/* Define to 1 if the Couenne package is available */
#undef COIN_HAS_COUENNE

/* Define to 1 if the cppad package is available */
#undef COIN_HAS_CPPAD

/* Define to 1 if the Cpx package is available */
#undef COIN_HAS_CPX

/* Define to 1 if the Csdp package is available */
#undef COIN_HAS_CSDP

/* Define to 1 if the DyLP package is available */
#undef COIN_HAS_DYLP

/* Define to 1 if the Glpk package is available */
#undef COIN_HAS_GLPK

/* Define to 1 if the Grb package is available */
#undef COIN_HAS_GRB

/* Define to 1 if the Ipopt package is available */
#undef COIN_HAS_IPOPT

/* Define to 1 if the Knitro package is available */
#undef COIN_HAS_KNITRO

/* Define to 1 if the Lindo package is available */
#undef COIN_HAS_LINDO

/* Define to 1 if the Msk package is available */
#undef COIN_HAS_MSK

/* Define to 1 if the OSI package is used */
#define COIN_HAS_OSI 1

/* Define to 1 if the SoPlex package is available */
#undef COIN_HAS_SOPLEX

/* Define to 1 if the SYMPHONY package is used */
#define COIN_HAS_SYMPHONY 1

/* Define to 1 if the Vol package is used */
#define COIN_HAS_VOL 1

/* Define to 1 if the Xpr package is available */
#undef COIN_HAS_XPR

/* Define to 1 if the CppAD package is used */
/* #define COIN_HAS_CPPAD 1 */

#ifdef _MSC_VER
/* Define to be the name of C-function for NaN check */
#define COIN_C_ISNAN _isnan
#endif


