
/***************************************************************************/
/*           HERE DEFINE THE PROJECT SPECIFIC PUBLIC MACROS                */
/*    These are only in effect in a setting that doesn't use configure     */
/***************************************************************************/

/* Version number of project */
#define OS_VERSION      "devel"

/* Major Version number of project */
#define OS_VERSION_MAJOR   9999

/* Minor Version number of project */
#define OS_VERSION_MINOR   9999

/* Release Version number of project */
#define OS_VERSION_RELEASE 9999

/* Define to 1 if OS uses CppAD */
#define OS_HAS_CPPAD

/* Define to 1 if OS uses Ipopt */
#define OS_HAS_IPOPT

/* Define to 1 if OS uses Bonmin */
#define OS_HAS_BONMIN

/* Define to 1 if OS uses Couenne */
#define OS_HAS_COUENNE

/* Define to 1 if OS uses SYMPHONY */
#define OS_HAS_SYMPHONY

/* Define to 1 if OS uses DyLP */
#define OS_HAS_DYLP

/* Define to 1 if OS uses Vol */
#define OS_HAS_VOL

/* Define to 1 if OS uses Glpk */
#define OS_HAS_GLPK

/* Define to 1 if OS uses ASL */
#define OS_HAS_ASL

/* use 64 bit integers */
#undef OS_USE_XML_LONG_INTEGER

/* integer size */
#define OS_INT_SIZE 4

/* Define to 64-bit integer type */
#undef OS_XML_INT64

/* Define to 64-bit unsigned integer type */
#undef OS_XML_UINT64

#ifndef OSLIB_EXPORT
#if defined(_WIN32) && defined(DLL_EXPORT)
#define OSLIB_EXPORT __declspec(dllimport)
#else
#define OSLIB_EXPORT
#endif
#endif
