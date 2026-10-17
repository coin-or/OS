
/* include the COIN-OR-wide system specific configure header */
#include "configall_system.h"

/* this needs to come before the include of config_os_default.h */
#ifndef OSLIB_EXPORT
#if defined(_WIN32) && defined(DLL_EXPORT)
#define OSLIB_EXPORT __declspec(dllexport)
#else
#define OSLIB_EXPORT
#endif
#endif

/* include the public project specific macros */
#include "config_os_default.h"

/***************************************************************************/
/*             HERE DEFINE THE PROJECT SPECIFIC MACROS                     */
/*    These are only in effect in a setting that doesn't use configure     */
/***************************************************************************/

/* Define to the debug sanity check level (0 is no test) */
#define OS_CHECKLEVEL 0

/* Define to the debug verbosity level (0 is no output) */
#define OS_VERBOSITY 0

/* Define to 1 if the Cbc package is available */
#define OS_HAS_CBC 1

/* Define to 1 if the Cgl package is used */
#define OS_HAS_CGL 1

/* Define to 1 if the Clp package is used */
#define OS_HAS_CLP 1

/* Define to 1 if the CoinUtils package is used */
#define OS_HAS_COINUTILS 1

/* Define to 1 if the Cpx package is available */
#undef OS_HAS_CPX

/* Define to 1 if the Csdp package is available */
#undef OS_HAS_CSDP

/* Define to 1 if the Grb package is available */
#undef OS_HAS_GRB

/* Define to 1 if the Knitro package is available */
#undef OS_HAS_KNITRO

/* Define to 1 if the Lindo package is available */
#undef OS_HAS_LINDO

/* Define to 1 if the Msk package is available */
#undef OS_HAS_MSK

/* Define to 1 if the OSI package is used */
#define OS_HAS_OSI 1

/* Define to 1 if the SoPlex package is available */
#undef OS_HAS_SOPLEX

/* Define to 1 if the Xpr package is available */
#undef OS_HAS_XPR

#ifdef _MSC_VER
/* Define to be the name of C-function for NaN check */
#define COIN_C_ISNAN _isnan
#endif


