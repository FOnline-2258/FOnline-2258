/*
   AngelCode Scripting Library
   Copyright (c) 2003-2013 Andreas Jonsson

   This software is provided 'as-is', without any express or implied
   warranty. In no event will the authors be held liable for any
   damages arising from the use of this software.

   Permission is granted to anyone to use this software for any
   purpose, including commercial applications, and to alter it and
   redistribute it freely, subject to the following restrictions:

   1. The origin of this software must not be misrepresented; you
      must not claim that you wrote the original software. If you use
      this software in a product, an acknowledgment in the product
      documentation would be appreciated but is not required.

   2. Altered source versions must be plainly marked as such, and
      must not be misrepresented as being the original software.

   3. This notice may not be removed or altered from any source
      distribution.

   The original version of this library can be located at:
   http://www.angelcode.com/angelscript/

   Andreas Jonsson
   andreas@angelcode.com
*/


//
// as_config.h
//
// this file is used for configuring the compilation of the library
//

#ifndef AS_CONFIG_H
#define AS_CONFIG_H



//
// Features
//-----------------------------------------

// AS_NO_THREADS
// Turns off support for multithreading. By turning off
// this when it's not needed a bit of performance is gained.

// AS_WINDOWS_THREADS
// If the library should be compiled using windows threads.

// AS_POSIX_THREADS
// If the library should be compiled using posix threads.

// AS_NO_ATOMIC
// If the compiler/platform doesn't support atomic instructions
// then this should be defined to use critical sections instead.

// AS_DEBUG
// This flag can be defined to make the library write some extra output when
// compiling and executing scripts.

// AS_DEPRECATED
// If this flag is defined then some backwards compatibility is maintained.
// There is no guarantee for how well deprecated functionality will work though
// so it is best to exchange it for the new functionality as soon as possible.

// AS_NO_CLASS_METHODS
// Disables the possibility to add class methods. Can increase the
// portability of the library.

// AS_MAX_PORTABILITY
// Disables all platform specific code. Only the asCALL_GENERIC calling
// convention will be available in with this flag set.

// AS_DOUBLEBYTE_CHARSET
// When this flag is defined, the parser will treat all characters in strings
// that are greater than 127 as lead characters and automatically include the
// next character in the script without checking its value. This should be
// compatible with common encoding schemes, e.g. Big5. Shift-JIS is not compatible
// though as it encodes some single byte characters above 127.
//
// If support for international text is desired, it is recommended that UTF-8
// is used as this is supported natively by the compiler without the use for this
// preprocessor flag.

// AS_NO_COMPILER
// Compiles the library without support for compiling scripts. This is intended
// for those applications that will load pre-compiled bytecode and wants to decrease
// the size of the executable.

// AS_NO_EXCEPTIONS
// Define this if exception handling is turned off or not available on the target platform.

// AS_NO_MEMBER_INIT
// Disable the support for initialization of class members directly in the declaration.
// This was as a form to maintain backwards compatibility with versions before 2.26.0
// if the new order of the member initialization caused null pointer exceptions in older
// scripts (e.g. if a base class accessed members of a derived class through a virtual method).


//
// Library usage
//------------------------------------------

// ANGELSCRIPT_EXPORT
// This flag should be defined when compiling the library as a lib or dll.

// ANGELSCRIPT_DLL_LIBRARY_IMPORT
// This flag should be defined when using AngelScript as a dll with automatic
// library import.

// ANGELSCRIPT_DLL_MANUAL_IMPORT
// This flag should be defined when using AngelScript as a dll with manual
// loading of the library.




//
// Compiler differences
//-----------------------------------------

// asVSNPRINTF(a,b,c,d)
// Some compilers use different names for this function. You must
// define this macro to map to the proper function.

// ASM_AT_N_T or ASM_INTEL
// You should choose what inline assembly syntax to use when compiling.

// VALUE_OF_BOOLEAN_TRUE
// This flag allows to customize the exact value of boolean true.

// AS_SIZEOF_BOOL
// On some target platforms the sizeof(bool) is 4, but on most it is 1.

// STDCALL
// This is used to declare a function to use the stdcall calling convention.

// AS_USE_NAMESPACE
// Adds the AngelScript namespace on the declarations.

// AS_NO_MEMORY_H
// Some compilers don't come with the memory.h header file.



//
// How to identify different compilers
//-----------------------------------------

// MS Visual C++
//  _MSC_VER   is defined
//  __MWERKS__ is not defined

// Metrowerks
//  _MSC_VER   is defined
//  __MWERKS__ is defined

// GNU C based compilers
//  __GNUC__   is defined

// Embarcadero C++Builder
//  __BORLANDC__ is defined



//
// CPU differences
//---------------------------------------

// AS_USE_DOUBLE_AS_FLOAT
// If there is no 64 bit floating point type, then this constant can be defined
// to treat double like normal floats.

// AS_X86
// Use assembler code for the x86 CPU family

// AS_SH4
// Use assembler code for the SH4 CPU family

// AS_MIPS
// Use assembler code for the MIPS CPU family

// AS_PPC
// Use assembler code for the 32bit PowerPC CPU family

// AS_PPC_64
// Use assembler code for the 64bit PowerPC CPU family

// AS_XENON
// Use assembler code for the Xenon (XBOX360) CPU family

// AS_ARM
// Use assembler code for the ARM CPU family

// AS_X64_GCC
// Use GCC assembler code for the X64 AMD/Intel CPU family

// AS_X64_MSVC
// Use MSVC assembler code for the X64 AMD/Intel CPU family

// AS_64BIT_PTR
// Define this to make the engine store all pointers in 64bit words.

// AS_BIG_ENDIAN
// Define this for CPUs that use big endian memory layout, e.g. PPC



//
// Target systems
//--------------------------------
// This group shows a few of the flags used to identify different target systems.
// Sometimes there are differences on different target systems, while both CPU and
// compiler is the same for both, when this is so these flags are used to produce the
// right code.

// AS_WIN       - Microsoft Windows
// AS_LINUX     - Linux
// AS_MAC       - Apple Macintosh
// AS_BSD       - BSD based OS (FreeBSD, DragonFly, OpenBSD, etc)
// AS_XBOX      - Microsoft XBox
// AS_XBOX360   - Microsoft XBox 360
// AS_PSP       - Sony Playstation Portable
// AS_PS2       - Sony Playstation 2
// AS_PS3       - Sony Playstation 3
// AS_DC        - Sega Dreamcast
// AS_GC        - Nintendo GameCube
// AS_WII       - Nintendo Wii
// AS_WIIU      - Nintendo Wii U
// AS_IPHONE    - Apple IPhone
// AS_ANDROID   - Android
// AS_HAIKU     - Haiku
// AS_ILLUMOS   - Illumos like (OpenSolaris, OpenIndiana, NCP, etc)
// AS_MARMALADE - Marmalade cross platform SDK (a layer on top of the OS)




//
// Calling conventions
//-----------------------------------------

// GNU_STYLE_VIRTUAL_METHOD
// This constant should be defined if method pointers store index for virtual
// functions in the same location as the function pointer. In such cases the method
// is identified as virtual if the least significant bit is set.

// MULTI_BASE_OFFSET(x)
// This macro is used to retrieve the offset added to the object pointer in order to
// implicitly cast the object to the base object. x is the method pointer received by
// the register function.

// HAVE_VIRTUAL_BASE_OFFSET
// Define this constant if the compiler stores the virtual base offset in the method
// pointers. If it is not stored in the pointers then AngelScript have no way of
// identifying a method as coming from a class with virtual inheritance.

// VIRTUAL_BASE_OFFSET(x)
// This macro is used to retrieve the offset added to the object pointer in order to
// find the virtual base object. x is the method pointer received by the register
// function;

// COMPLEX_RETURN_MASK
// This constant shows what attributes determine if an object is returned in memory
// or in the registers as normal structures

// COMPLEX_MASK
// This constant shows what attributes determine if an object is implicitly passed
// by reference or not, even if the argument is declared by value

// THISCALL_RETURN_SIMPLE_IN_MEMORY
// CDECL_RETURN_SIMPLE_IN_MEMORY
// STDCALL_RETURN_SIMPLE_IN_MEMORY
// When these constants are defined then the corresponding calling convention always
// return classes/structs in memory regardless of size or complexity.

// THISCALL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE
// STDCALL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE
// CDECL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE
// Specifies the minimum size in dwords a class/struct needs to be to be passed in memory

// CALLEE_POPS_HIDDEN_RETURN_POINTER
// This constant should be defined if the callee pops the hidden return pointer,
// used when returning an object in memory.

// THISCALL_CALLEE_POPS_HIDDEN_RETURN_POINTER
// This constant should be defined if the callee pops the hidden return pointer
// for thiscall functions; used when returning an object in memory.

// THISCALL_PASS_OBJECT_POINTER_ON_THE_STACK
// With this constant defined AngelScript will pass the object pointer on the stack

// THISCALL_CALLEE_POPS_ARGUMENTS
// If the callee pops arguments for class methods then define this constant

// COMPLEX_OBJS_PASSED_BY_REF
// Some compilers always pass certain objects by reference. GNUC for example does
// this if the the class has a defined destructor.

// AS_LARGE_OBJS_PASSED_BY_REF
// If this is defined large objects are passed by reference, whether they are complex or not

// AS_LARGE_OBJ_MIN_SIZE
// This is the size of objects determined as large ones

// AS_CALLEE_DESTROY_OBJ_BY_VAL
// When an object is passed by value the called function is the one responsible
// for calling the destructor before returning.

// HAS_128_BIT_PRIMITIVES
// 64bit processors often support 128bit primitives. These may require special
// treatment when passed in function arguments or returned by functions.

// SPLIT_OBJS_BY_MEMBER_TYPES
// On some platforms objects with primitive members are split over different
// register types when passed by value to functions.





//
// Detect compiler
//------------------------------------------------


#define VALUE_OF_BOOLEAN_TRUE  1
#define STDCALL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE 0
#define CDECL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE 0
#define THISCALL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE 0
#define THISCALL_CALLEE_POPS_HIDDEN_RETURN_POINTER


// Embarcadero C++Builder
#if defined(__BORLANDC__)
 #ifndef _Windows
  #error "Configuration doesn't yet support BCC for Linux or Mac OS."
 #endif
 #if defined(_M_X64)
  #error "Configuration doesn't yet support BCC for AMD64."
 #endif

	#define MULTI_BASE_OFFSET(x) (*((asDWORD*)(&x)+1))
	#define HAVE_VIRTUAL_BASE_OFFSET
	#define VIRTUAL_BASE_OFFSET(x) (*((asDWORD*)(&x)+2))
	#define THISCALL_RETURN_SIMPLE_IN_MEMORY
	#define CDECL_RETURN_SIMPLE_IN_MEMORY
	#define STDCALL_RETURN_SIMPLE_IN_MEMORY
	#undef STDCALL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE
	#undef CDECL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE
	#undef THISCALL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE
	#define STDCALL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE 2
	#define CDECL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE 2
	#define THISCALL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE 2

	#define THISCALL_PASS_OBJECT_POINTER_ON_THE_STACK
	#define COMPLEX_MASK (asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_DESTRUCTOR)
	#define COMPLEX_RETURN_MASK (asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_DESTRUCTOR)
	#define STDCALL __stdcall
	#define AS_SIZEOF_BOOL 1
	#define AS_WINDOWS_THREADS
	#undef THISCALL_CALLEE_POPS_HIDDEN_RETURN_POINTER

	#define AS_WIN
	#define AS_X86
	#define ASM_INTEL

	#define asVSNPRINTF(a, b, c, d) _vsnprintf(a, b, c, d)

	#define fmodf(a,b) fmod(a,b)

	#define UNREACHABLE_RETURN
#endif

// Microsoft Visual C++
#if defined(_MSC_VER) && !defined(__MWERKS__)

	#if _MSC_VER <= 1200 // MSVC6
		// Disable the useless warnings about truncated symbol names for template instances
		#pragma warning( disable : 4786 )
	#endif

	#ifdef _M_X64
		#define MULTI_BASE_OFFSET(x) (*((asDWORD*)(&x)+2))
		#define VIRTUAL_BASE_OFFSET(x) (*((asDWORD*)(&x)+4))
	#else
		#define MULTI_BASE_OFFSET(x) (*((asDWORD*)(&x)+1))
		#define VIRTUAL_BASE_OFFSET(x) (*((asDWORD*)(&x)+3))
	#endif
	#define HAVE_VIRTUAL_BASE_OFFSET
	#define THISCALL_RETURN_SIMPLE_IN_MEMORY
	#define THISCALL_PASS_OBJECT_POINTER_IN_ECX

	// http://www.madewithmarmalade.com/
	#if defined(__S3E__)
		#ifndef AS_MARMALADE
			// From now on we'll use the below define
			#define AS_MARMALADE
		#endif

		// Marmalade doesn't use the Windows libraries
		#define asVSNPRINTF(a, b, c, d) vsnprintf(a, b, c, d)

		// Marmalade doesn't seem to have proper support for
		// atomic instructions or read/write locks, so we turn off
		// multithread support
		//#define AS_POSIX_THREADS
		#define AS_NO_THREADS
		#define AS_NO_ATOMIC

		// Marmalade has it's own way of identifying the CPU target
		// Note, when building for ARM, the gnuc compiler will always
		// be used so we don't need to check for it here
		#if defined(I3D_ARCH_X86)
			#define AS_X86
		#endif
	#else
		#if _MSC_VER < 1500  // MSVC++ 9 (aka MSVC++ .NET 2008)
			#define asVSNPRINTF(a, b, c, d) _vsnprintf(a, b, c, d)
		#else
			#define asVSNPRINTF(a, b, c, d) vsnprintf_s(a, b, _TRUNCATE, c, d)
		#endif

		#define AS_WINDOWS_THREADS
	#endif

	#define THISCALL_CALLEE_POPS_ARGUMENTS
	#define STDCALL __stdcall
	#define AS_SIZEOF_BOOL 1

	#define ASM_INTEL  // Intel style for inline assembly on microsoft compilers

	#if defined(WIN32) || defined(_WIN32) || defined(_WIN64)
		#define AS_WIN
	#endif

	#if _XBOX_VER >= 200
		// 360 uses a Xenon processor (which is a modified 64bit PPC)
		#define AS_XBOX360
		#define AS_XENON
		#define AS_BIG_ENDIAN
	#else
		#if defined(_XBOX) || (defined(_M_IX86) && !defined(__LP64__))
			#define AS_X86
		#elif defined(_M_X64)
			#define AS_X64_MSVC
			#define AS_CALLEE_DESTROY_OBJ_BY_VAL
			#define AS_LARGE_OBJS_PASSED_BY_REF
			#define AS_LARGE_OBJ_MIN_SIZE 3
			#define COMPLEX_OBJS_PASSED_BY_REF
			#define COMPLEX_RETURN_MASK (asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_ASSIGNMENT | asOBJ_APP_CLASS_COPY_CONSTRUCTOR)
			#define COMPLEX_MASK (asOBJ_APP_CLASS_COPY_CONSTRUCTOR)
		#endif
	#endif

	#ifdef _ARM_
		#define AS_ARM
		#define AS_CALLEE_DESTROY_OBJ_BY_VAL
		#define CDECL_RETURN_SIMPLE_IN_MEMORY
		#define STDCALL_RETURN_SIMPLE_IN_MEMORY
		#define COMPLEX_OBJS_PASSED_BY_REF
		#define COMPLEX_MASK asOBJ_APP_CLASS_ASSIGNMENT
		#define COMPLEX_RETURN_MASK asOBJ_APP_CLASS_ASSIGNMENT
	#endif

	#ifndef COMPLEX_MASK
		#define COMPLEX_MASK (asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_ASSIGNMENT)
	#endif

	#ifndef COMPLEX_RETURN_MASK
		#define COMPLEX_RETURN_MASK (asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_ASSIGNMENT)
	#endif

	#define UNREACHABLE_RETURN
#endif

// Metrowerks CodeWarrior (experimental, let me know if something isn't working)
#if defined(__MWERKS__) && !defined(EPPC) // JWC -- If Wii DO NOT use this even when using Metrowerks Compiler. Even though they are called Freescale...
	#define MULTI_BASE_OFFSET(x) (*((asDWORD*)(&x)+1))
	#define HAVE_VIRTUAL_BASE_OFFSET
	#define VIRTUAL_BASE_OFFSET(x) (*((asDWORD*)(&x)+3))
	#define THISCALL_RETURN_SIMPLE_IN_MEMORY
	#define THISCALL_PASS_OBJECT_POINTER_IN_ECX
	#define asVSNPRINTF(a, b, c, d) _vsnprintf(a, b, c, d)
	#define THISCALL_CALLEE_POPS_ARGUMENTS
	#define COMPLEX_MASK (asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_ASSIGNMENT)
	#define COMPLEX_RETURN_MASK (asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_ASSIGNMENT)
	#define AS_SIZEOF_BOOL 1
	#define AS_WINDOWS_THREADS
	#define STDCALL __stdcall

	// Support native calling conventions on x86, but not 64bit yet
	#if defined(_M_IX86) && !defined(__LP64__)
		#define AS_X86
		#define ASM_INTEL  // Intel style for inline assembly
	#endif

	#define UNREACHABLE_RETURN
#endif

// SN Systems ProDG
#if defined(__SNC__) || defined(SNSYS)
	#define GNU_STYLE_VIRTUAL_METHOD
	#define MULTI_BASE_OFFSET(x) (*((asDWORD*)(&x)+1))
	#define CALLEE_POPS_HIDDEN_RETURN_POINTER
	#define COMPLEX_OBJS_PASSED_BY_REF
	#define ASM_AT_N_T  // AT&T style inline assembly
	#define COMPLEX_MASK (asOBJ_APP_CLASS_DESTRUCTOR)
	#define COMPLEX_RETURN_MASK (asOBJ_APP_CLASS_DESTRUCTOR)
	#define AS_SIZEOF_BOOL 1
	#define asVSNPRINTF(a, b, c, d) vsnprintf(a, b, c, d)

	// SN doesnt seem to like STDCALL.
	// Maybe it can work with some fiddling, but I can't imagine linking to
	// any STDCALL functions with a console anyway...
	#define STDCALL

	// Linux specific
	#ifdef __linux__
		#define THISCALL_RETURN_SIMPLE_IN_MEMORY
		#define CDECL_RETURN_SIMPLE_IN_MEMORY
		#define STDCALL_RETURN_SIMPLE_IN_MEMORY
	#endif

	// Support native calling conventions on x86, but not 64bit yet
	#if (defined(i386) || defined(__i386) || defined(__i386__)) && !defined(__LP64__)
		#define AS_X86
	// PS3
	#elif (defined(__PPC__) || defined(__ppc__)) && defined(__PPU__)
		// Support native calling conventions on PS3
		#define AS_PS3
		#define AS_PPC_64
	// PSP
	#elif defined(__psp__)
		#define AS_NO_MEMORY_H
		#define AS_MIPS
		#define AS_PSP
	#endif

	#define UNREACHABLE_RETURN
#endif

// GNU C (and MinGW or Cygwin on Windows)
// Use the following command to determine predefined macros: echo . | mingw32-g++ -dM -E -
#if (defined(__GNUC__) && !defined(__SNC__)) || defined(EPPC) || defined(__CYGWIN__) // JWC -- use this instead for Wii
	#define GNU_STYLE_VIRTUAL_METHOD
#if !defined( __amd64__ )
	#define MULTI_BASE_OFFSET(x) (*((asDWORD*)(&x)+1))
#else
	#define MULTI_BASE_OFFSET(x) (*((asQWORD*)(&x)+1))
#endif
	#define asVSNPRINTF(a, b, c, d) vsnprintf(a, b, c, d)
	#define CALLEE_POPS_HIDDEN_RETURN_POINTER
	#define COMPLEX_OBJS_PASSED_BY_REF
	#define COMPLEX_MASK (asOBJ_APP_CLASS_DESTRUCTOR)
	#define COMPLEX_RETURN_MASK (asOBJ_APP_CLASS_DESTRUCTOR)
	#define AS_NO_MEMORY_H
	#define AS_SIZEOF_BOOL 1
	#define STDCALL __attribute__((stdcall))
	#define ASM_AT_N_T

	// WII U
	#if defined(__ghs__)
		#define AS_WIIU

		// Native calling conventions are not yet supported
		#define AS_MAX_PORTABILITY

	// Marmalade is a cross platform SDK. It uses g++ to compile for iOS and Android
	#elif defined(__S3E__)
		#ifndef AS_MARMALADE
			// From now on we'll use the below define
			#define AS_MARMALADE
		#endif

		// STDCALL is not available on Marmalade when compiled for iOS or Android
		#undef STDCALL
		#define STDCALL

		// Marmalade doesn't seem to have proper support for
		// atomic instructions or read/write locks
		#define AS_NO_THREADS
		#define AS_NO_ATOMIC

		// Identify for which CPU the library is being built
		#if defined(I3D_ARCH_X86)
			#define AS_X86
		#elif defined(I3D_ARCH_ARM)
			#define AS_ARM

			// Marmalade appear to use the same ABI as Android when built for ARM
			#define CDECL_RETURN_SIMPLE_IN_MEMORY
			#define STDCALL_RETURN_SIMPLE_IN_MEMORY
			#define THISCALL_RETURN_SIMPLE_IN_MEMORY

			#undef THISCALL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE
			#define THISCALL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE 2

			#undef CDECL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE
			#define CDECL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE 2

			#undef STDCALL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE
			#define STDCALL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE 2

			#undef GNU_STYLE_VIRTUAL_METHOD

			#undef COMPLEX_MASK
			#define COMPLEX_MASK (asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR)
			#undef COMPLEX_RETURN_MASK
			#define COMPLEX_RETURN_MASK (asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR)

			#define AS_CALLEE_DESTROY_OBJ_BY_VAL
		#endif

	// MacOSX and IPhone
	#elif defined(__APPLE__)

		#include <TargetConditionals.h>

		// Is this a Mac or an IPhone (or other iOS device)?
		#if defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE == 1
			#define AS_IPHONE
		#else
			#define AS_MAC
		#endif

		// The sizeof bool is different depending on the target CPU
		#undef AS_SIZEOF_BOOL
		#if defined(__ppc__)
			#define AS_SIZEOF_BOOL 4
			// STDCALL is not available on PPC
			#undef STDCALL
			#define STDCALL
		#else
			#define AS_SIZEOF_BOOL 1
		#endif

		#if (defined(i386) || defined(__i386) || defined(__i386__)) && !defined(__LP64__)
			// Support native calling conventions on Mac OS X + Intel 32bit CPU
			#define AS_X86
			#define THISCALL_PASS_OBJECT_POINTER_ON_THE_STACK
			#undef COMPLEX_MASK
			#define COMPLEX_MASK (asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR)
			#undef COMPLEX_RETURN_MASK
			#define COMPLEX_RETURN_MASK (asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR)
		#elif defined(__LP64__) && !defined(__ppc__) && !defined(__PPC__)
			// http://developer.apple.com/library/mac/#documentation/DeveloperTools/Conceptual/LowLevelABI/140-x86-64_Function_Calling_Conventions/x86_64.html#//apple_ref/doc/uid/TP40005035-SW1
			#define AS_X64_GCC
			#define HAS_128_BIT_PRIMITIVES
			#define SPLIT_OBJS_BY_MEMBER_TYPES
			#undef COMPLEX_MASK
			#define COMPLEX_MASK (asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR)
			#undef COMPLEX_RETURN_MASK
			#define COMPLEX_RETURN_MASK (asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR)
			#define AS_LARGE_OBJS_PASSED_BY_REF
			#define AS_LARGE_OBJ_MIN_SIZE 5
			// STDCALL is not available on 64bit Mac
			#undef STDCALL
			#define STDCALL
		#elif (defined(__ppc__) || defined(__PPC__)) && !defined(__LP64__)
			// Support native calling conventions on Mac OS X + PPC 32bit CPU
			#define AS_PPC
			#define THISCALL_RETURN_SIMPLE_IN_MEMORY
			#define CDECL_RETURN_SIMPLE_IN_MEMORY
			#define STDCALL_RETURN_SIMPLE_IN_MEMORY
			#undef COMPLEX_MASK
			#define COMPLEX_MASK (asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR)
			#undef COMPLEX_RETURN_MASK
			#define COMPLEX_RETURN_MASK (asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR)
		#elif (defined(__ppc__) || defined(__PPC__)) && defined(__LP64__)
			#define AS_PPC_64
		#elif (defined(_ARM_) || defined(__arm__))
			// The IPhone use an ARM processor
			#define AS_ARM
			#define AS_CALLEE_DESTROY_OBJ_BY_VAL
			#define CDECL_RETURN_SIMPLE_IN_MEMORY
			#define STDCALL_RETURN_SIMPLE_IN_MEMORY
			#define THISCALL_RETURN_SIMPLE_IN_MEMORY

			#undef GNU_STYLE_VIRTUAL_METHOD

			#undef THISCALL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE
			#undef CDECL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE
			#undef STDCALL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE

			#define THISCALL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE 2
			#define CDECL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE 2
			#define STDCALL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE 2
			#define COMPLEX_OBJS_PASSED_BY_REF
			#undef COMPLEX_MASK
			#define COMPLEX_MASK (asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR)
			#undef COMPLEX_RETURN_MASK
			#define COMPLEX_RETURN_MASK (asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR)

			// STDCALL is not available on ARM
			#undef STDCALL
			#define STDCALL
		#else
			// Unknown CPU type
			#define AS_MAX_PORTABILITY
		#endif
		#define AS_POSIX_THREADS

	// Windows
	#elif defined(WIN32) || defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
		// On Windows the simple classes are returned in the EAX:EDX registers
		//#define THISCALL_RETURN_SIMPLE_IN_MEMORY
		//#define CDECL_RETURN_SIMPLE_IN_MEMORY
		//#define STDCALL_RETURN_SIMPLE_IN_MEMORY

		#undef COMPLEX_MASK
		#define COMPLEX_MASK (asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR)
		#undef COMPLEX_RETURN_MASK
		#define COMPLEX_RETURN_MASK (asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR)

		#if (defined(i386) || defined(__i386) || defined(__i386__)) && !defined(__LP64__)
			// Support native calling conventions on Intel 32bit CPU
			#define AS_X86

			// As of version 4.7 MinGW changed the ABI, presumably
			// to be better aligned with how MSVC works
			#if (__GNUC__ == 4 && __GNUC_MINOR__ >= 7) || __GNUC__ > 4
				#undef  CALLEE_POPS_HIDDEN_RETURN_POINTER
				#define THISCALL_CALLEE_POPS_ARGUMENTS
			#else
				// Earlier versions than 4.7
				#define THISCALL_PASS_OBJECT_POINTER_ON_THE_STACK
			#endif

		#elif defined(__x86_64__)
			#define AS_X64_MINGW
			#define AS_LARGE_OBJS_PASSED_BY_REF
			#define AS_LARGE_OBJ_MIN_SIZE 3
			#define COMPLEX_OBJS_PASSED_BY_REF
		#else
			#define AS_MAX_PORTABILITY
		#endif
		#define AS_WIN
		#define AS_WINDOWS_THREADS

	// Linux
	#elif defined(__linux__) && !defined(ANDROID) && !defined(__ANDROID__)

		#undef COMPLEX_MASK
		#define COMPLEX_MASK (asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR)
		#undef COMPLEX_RETURN_MASK
		#define COMPLEX_RETURN_MASK (asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR)

		#if (defined(i386) || defined(__i386) || defined(__i386__)) && !defined(__LP64__)
			#define THISCALL_RETURN_SIMPLE_IN_MEMORY
			#define CDECL_RETURN_SIMPLE_IN_MEMORY
			#define STDCALL_RETURN_SIMPLE_IN_MEMORY

			// Support native calling conventions on Intel 32bit CPU
			#define THISCALL_PASS_OBJECT_POINTER_ON_THE_STACK
			#define AS_X86
		#elif defined(__LP64__)
			#define AS_X64_GCC
			#define HAS_128_BIT_PRIMITIVES
			#define SPLIT_OBJS_BY_MEMBER_TYPES
			#define AS_LARGE_OBJS_PASSED_BY_REF
			#define AS_LARGE_OBJ_MIN_SIZE 5
			// STDCALL is not available on 64bit Linux
			#undef STDCALL
			#define STDCALL
		#elif defined(__ARMEL__) || defined(__arm__)
			#define AS_ARM
			#define AS_NO_ATOMIC

			#define CDECL_RETURN_SIMPLE_IN_MEMORY
			#define STDCALL_RETURN_SIMPLE_IN_MEMORY
			#define THISCALL_RETURN_SIMPLE_IN_MEMORY

			#undef THISCALL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE
			#undef CDECL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE
			#undef STDCALL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE

			#define THISCALL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE 2
			#define CDECL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE 2
			#define STDCALL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE 2
		#elif defined(__mips__)
			#define AS_MIPS
			#define AS_BIG_ENDIAN
			#define AS_USE_DOUBLE_AS_FLOAT

			// Native calling conventions for Linux/Mips do not work yet.
			#define AS_MAX_PORTABILITY
		#else
			#define AS_MAX_PORTABILITY
		#endif
		#define AS_LINUX
		#define AS_POSIX_THREADS

		#if !( ( (__GNUC__ == 4) && (__GNUC_MINOR__ >= 1) || __GNUC__ > 4) )
			// Only with GCC 4.1 was the atomic instructions available
			#define AS_NO_ATOMIC
		#endif

	// Free BSD
	#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__)
		#define AS_BSD
		#if (defined(i386) || defined(__i386) || defined(__i386__)) && !defined(__LP64__)
			#undef COMPLEX_MASK
			#define COMPLEX_MASK (asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR)
			#undef COMPLEX_RETURN_MASK
			#define COMPLEX_RETURN_MASK (asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR)
			#define THISCALL_PASS_OBJECT_POINTER_ON_THE_STACK
			#define AS_X86
		#elif defined(__LP64__)
			#define AS_X64_GCC
			#define HAS_128_BIT_PRIMITIVES
			#define SPLIT_OBJS_BY_MEMBER_TYPES
			#undef COMPLEX_MASK
			#define COMPLEX_MASK (asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR)
			#undef COMPLEX_RETURN_MASK
			#define COMPLEX_RETURN_MASK (asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR)
			#define AS_LARGE_OBJS_PASSED_BY_REF
			#define AS_LARGE_OBJ_MIN_SIZE 5
			#undef STDCALL
			#define STDCALL
		#else
			#define AS_MAX_PORTABILITY
		#endif
		#define AS_POSIX_THREADS
		#if !( ( (__GNUC__ == 4) && (__GNUC_MINOR__ >= 1) || __GNUC__ > 4) )
			// Only with GCC 4.1 was the atomic instructions available
			#define AS_NO_ATOMIC
		#endif

	// PSP and PS2
	#elif defined(__PSP__) || defined(__psp__) || defined(_EE_) || defined(_PSP) || defined(_PS2)
		// Support native calling conventions on MIPS architecture
		#if (defined(_MIPS_ARCH) || defined(_mips) || defined(__MIPSEL__)) && !defined(__LP64__)
			#define AS_MIPS
		#else
			#define AS_MAX_PORTABILITY
		#endif

	// PS3
	#elif (defined(__PPC__) || defined(__ppc__)) && defined(__PPU__)
		// Support native calling conventions on PS3
		#define AS_PS3
		#define AS_PPC_64
		#define SPLIT_OBJS_BY_MEMBER_TYPES
		#define THISCALL_RETURN_SIMPLE_IN_MEMORY
		#define CDECL_RETURN_SIMPLE_IN_MEMORY
		#define STDCALL_RETURN_SIMPLE_IN_MEMORY
		// PS3 doesn't have STDCALL
		#undef STDCALL
		#define STDCALL

	// Dreamcast
	#elif __SH4_SINGLE_ONLY__
		// Support native calling conventions on Dreamcast
		#define AS_DC
		#define AS_SH4

	// Wii JWC - Close to PS3 just no PPC_64 and AS_PS3
	#elif defined(EPPC)
		#define AS_WII
		#define THISCALL_RETURN_SIMPLE_IN_MEMORY
		#define CDECL_RETURN_SIMPLE_IN_MEMORY
		#define STDCALL_RETURN_SIMPLE_IN_MEMORY
		#undef STDCALL
		#define STDCALL

	// Android
	#elif defined(ANDROID) || defined(__ANDROID__)
		#define AS_ANDROID
		#define AS_NO_ATOMIC

		#define CDECL_RETURN_SIMPLE_IN_MEMORY
		#define STDCALL_RETURN_SIMPLE_IN_MEMORY
		#define THISCALL_RETURN_SIMPLE_IN_MEMORY

		#undef THISCALL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE
		#undef CDECL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE
		#undef STDCALL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE

		#define THISCALL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE 2
		#define CDECL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE 2
		#define STDCALL_RETURN_SIMPLE_IN_MEMORY_MIN_SIZE 2

		#if (defined(_ARM_) || defined(__arm__))
			// The stdcall calling convention is not used on the arm cpu
			#undef STDCALL
			#define STDCALL

			#undef GNU_STYLE_VIRTUAL_METHOD

			#undef COMPLEX_MASK
			#define COMPLEX_MASK (asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR)
			#undef COMPLEX_RETURN_MASK
			#define COMPLEX_RETURN_MASK (asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR)

			#define AS_ARM
			#define AS_CALLEE_DESTROY_OBJ_BY_VAL
		#endif

	// Haiku OS
	#elif __HAIKU__
		#define AS_HAIKU
		// Only x86-32 is currently supported by Haiku, but they do plan to support
		// x86-64 and PowerPC in the future, so should go ahead and check the platform
		// for future compatibility
		#if (defined(i386) || defined(__i386) || defined(__i386__)) && !defined(__LP64__)
			#define AS_X86
			#define THISCALL_PASS_OBJECT_POINTER_ON_THE_STACK
			#define THISCALL_RETURN_SIMPLE_IN_MEMORY
			#define CDECL_RETURN_SIMPLE_IN_MEMORY
			#define STDCALL_RETURN_SIMPLE_IN_MEMORY
		#else
			#define AS_MAX_PORTABILITY
		#endif

		#define AS_POSIX_THREADS
		#if !( ( (__GNUC__ == 4) && (__GNUC_MINOR__ >= 1) || __GNUC__ > 4) )
			// Only with GCC 4.1 was the atomic instructions available
			#define AS_NO_ATOMIC
		#endif

	// Illumos
	#elif defined(__sun)
		#if (defined(i386) || defined(__i386) || defined(__i386__)) && !defined(__LP64__)
			#define THISCALL_RETURN_SIMPLE_IN_MEMORY
			#define CDECL_RETURN_SIMPLE_IN_MEMORY
			#define STDCALL_RETURN_SIMPLE_IN_MEMORY

			// Support native calling conventions on Intel 32bit CPU
			#define THISCALL_PASS_OBJECT_POINTER_ON_THE_STACK
			#define AS_X86
		#elif defined(__LP64__)
			#define AS_X64_GCC
			#define HAS_128_BIT_PRIMITIVES
			#define SPLIT_OBJS_BY_MEMBER_TYPES
			// STDCALL is not available on 64bit Linux
			#undef STDCALL
			#define STDCALL
		#else
			#define AS_MAX_PORTABILITY
		#endif
		#define AS_ILLUMOS
		#define AS_POSIX_THREADS

		#if !( ( (__GNUC__ == 4) && (__GNUC_MINOR__ >= 1) || __GNUC__ > 4) )
			// Only with GCC 4.1 was the atomic instructions available
			#define AS_NO_ATOMIC
		#endif
	#endif

	#define UNREACHABLE_RETURN
#endif


//
// Detect target hardware
//------------------------------------------------

// X86, Intel, AMD, etc, i.e. most PCs
#if defined(__i386__) || defined(_M_IX86)
	// Nothing special here
#endif

// MIPS architecture (generally PS2 and PSP consoles, potentially supports N64 as well)
#if defined(_MIPS_ARCH) || defined(_mips) || defined(__MIPSEL__) || defined(__PSP__) || defined(__psp__) || defined(_EE_) || defined(_PSP) || defined(_PS2)
	#define AS_USE_DOUBLE_AS_FLOAT	// use 32bit floats instead of doubles
#endif

// PowerPC, e.g. Mac, GameCube, PS3, XBox 360, Wii
#if defined(__PPC__) || defined(__ppc__) || defined(_PPC_) || defined(EPPC)
	#define AS_BIG_ENDIAN

	// Gamecube
	#if defined(_GC)
		#define AS_USE_DOUBLE_AS_FLOAT
	#endif
#endif

// Dreamcast console
#ifdef __SH4_SINGLE_ONLY__
	#define AS_USE_DOUBLE_AS_FLOAT	// use 32bit floats instead of doubles
#endif

// If there are no current support for native calling
// conventions, then compile with AS_MAX_PORTABILITY
#if (!defined(AS_X86) && !defined(AS_SH4) && !defined(AS_MIPS) && !defined(AS_PPC) && !defined(AS_PPC_64) && !defined(AS_XENON) && !defined(AS_X64_GCC) && !defined(AS_X64_MSVC) && !defined(AS_ARM) && !defined(AS_X64_MINGW))
	#ifndef AS_MAX_PORTABILITY
		#define AS_MAX_PORTABILITY
	#endif
#endif

// If the platform doesn't support atomic instructions we can't allow
// multithreading as the reference counters won't be threadsafe
#if defined(AS_NO_ATOMIC) && !defined(AS_NO_THREADS)
	#define AS_NO_THREADS
#endif

// If the form of threads to use hasn't been chosen
// then the library will be compiled without support
// for multithreading
#if !defined(AS_POSIX_THREADS) && !defined(AS_WINDOWS_THREADS)
	#define AS_NO_THREADS
#endif


// The assert macro
#if defined(ANDROID)
	#if defined(AS_DEBUG)
		#include <android/log.h>
		#include <stdlib.h>
		#define asASSERT(x) \
			do { \
			    if (!(x)) { \
			        __android_log_print(ANDROID_LOG_ERROR, "AngelScript", "Assert failed at %s:%d - %s", __FILE__, __LINE__, #x); \
			        exit(1); \
			    } \
			} while (0)
	#else
		#define asASSERT(x)
	#endif
#else
	#include <assert.h>
	#define asASSERT(x) assert(x)
#endif



//
// Internal defines (do not change these)
//----------------------------------------------------------------

#define ARG_W(b)     ((asWORD*)&b)
#define ARG_DW(b)    ((asDWORD*)&b)
#define ARG_QW(b)    ((asQWORD*)&b)
#define ARG_PTR(b)   ((asPWORD*)&b)
#define BCARG_W(b)   ((asWORD*)&(b)[1])
#define BCARG_DW(b)  ((asDWORD*)&(b)[1])
#define BCARG_QW(b)  ((asQWORD*)&(b)[1])
#define BCARG_PTR(b) ((asPWORD*)&(b)[1])

// This macro is used to avoid warnings about unused variables.
// Usually where the variables are only used in debug mode.
#define UNUSED_VAR(x) (void)(x)

#include "angelscript.h"
#include "as_memory.h"

#ifdef AS_USE_NAMESPACE
using namespace AngelScript;
#endif

#endif
