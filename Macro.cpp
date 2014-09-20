#ifndef _MACRO_H_
#define _MACRO_H_

#if defined(_X64_)
	#define CALLCONV __fastcall
#elif defined(_X86_)
	#define CALLCONV __stdcall
#else
	#define CALLCONV
#endif

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
#endif // _MACRO_H_