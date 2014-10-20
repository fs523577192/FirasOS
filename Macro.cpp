#ifndef _MACRO_H_
#define _MACRO_H_

#if defined(_X64_)
	#define CALLCONV __fastcall
#elif defined(_X86_)
	#define CALLCONV __stdcall
#else
	#define CALLCONV
#endif

typedef signed char	INT8;
typedef signed short	INT16;
typedef signed long	INT32;
typedef signed long long	INT64;

typedef unsigned char	BYTE, UINT8;
#if 1
// on x86 and x64
typedef unsigned short	WORD, UINT16;
typedef unsigned long	DWORD, UINT32;
typedef unsigned long long	QWORD, UINT64;
#elif 0
typedef unsigned short	HWORD, UINT16;
typedef unsigned long	WORD, UINT32;
typedef unsigned long long	DWORD, UINT64;
#endif
typedef float		REAL4;
typedef double		REAL8;
typedef long double 	REAL10;
typedef unsigned int	BOOLEAN;
#define TRUE	((BOOLEAN)1)
#define FALSE	((BOOLEAN)0)

const unsigned	UINT_MAX = ~0;
const int	INT_MAX = (UINT_MAX >> 1),	INT_MIN = ~INT_MAX;

const INT8	INT8_MAX = 0x7F,	INT8_MIN = 0x80;
const UINT8	UINT8_MAX = 0xFF;
const INT16	INT16_MAX = 0x7FFF,	INT16_MIN = 0x8000;
const UINT16	UINT16_MAX = 0xFFFF;
const INT32	INT32_MAX = 0x7FFFFFFF,	INT32_MIN = 0x80000000;
const UINT32	UINT32_MAX = 0xFFFFFFFF;
const INT64	INT64_MAX = 0x7FFFFFFFFFFFFFFFLL;
const INT64	INT64_MIN = 0x8000000000000000LL;
const UINT64	UINT64_MAX = 0xFFFFFFFFFFFFFFFFLL;
#endif // _MACRO_H_
