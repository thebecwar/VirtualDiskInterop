// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

// Version Selection Macros - Override SDK version.
//#define FORCE_WINDOWS_8_1 // Windows 8.1
//#define FORCE_WINDOWS_8 // Windows 8
//#define FORCE_WINDOWS_7 // Windows 7

// To force the build of the library targeting a different SDK than the one you have
#if defined(FORCE_WINDOWS_8_1)
#define WINVER 0x0603
#define _WIN32_WINNT 0x0603
#elif defined(FORCE_WINDOWS_8)
#define WINVER 0x0602
#define _WIN32_WINNT 0x0602
#elif defined(FORCE_WINDOWS_7)
#define WINVER 0x0601
#define _WIN32_WINNT 0x0601
#endif


#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <virtdisk.h>


// If targeting older SDK versions these macros may not be defined.
#ifndef _WIN32_WINNT_WIN10
#define _WIN32_WINNT_WIN10					0x0A00 // Windows 10
#endif
#ifndef _WIN32_WINNT_WINBLUE
#define _WIN32_WINNT_WINBLUE                0x0603 // Windows 8.1
#endif
#ifndef _WIN32_WINNT_WIN8
#define _WIN32_WINNT_WIN8                   0x0602 // Windows 8
#endif

#if (WINVER >= _WIN32_WINNT_WIN10)
#define WIN10SUPPORT
#define WIN8SUPPORT
#elif (WINVER >= _WIN32_WINNT_WIN8)
#define WIN8SUPPORT
#endif
