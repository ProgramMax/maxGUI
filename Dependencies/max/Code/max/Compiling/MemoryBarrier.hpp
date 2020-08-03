// Copyright 2015, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_COMPILING_MEMORYBARRIER_HPP
#define MAX_COMPILING_MEMORYBARRIER_HPP

#ifdef MAX_COMPILER_VC
	#include <intrin.h>
	
	#pragma intrinsic( _ReadBarrier )
	#pragma intrinsic( _WriteBarrier )
	#pragma intrinsic( _ReadWriteBarrier )

	#define FlushReads _ReadBarrier()
	#ifdef MAX_INSTRUCTION_SET_X86_64
		#define FlushWrites __faststorefence()
	#else
		#ifdef MAX_SSE_SUPPORTED
			#include <mmintrin.h>
			#define FlushWrites	do { _WriteBarrier(); __mm_sfence(); } while( false )
		#else
			#define FlushWrites _WriteBarrier()
		#endif
	#endif
	#define FlushReadsAndWrites _ReadWriteBarrier()
#endif

#ifdef MAX_COMPILER_GCC
	#error "GCC memory barriers not fully supported yet."
	#define FlushReads
	#ifdef MAX_SSE_SUPPORTED
		#define FlushWrites	__builtin_ia32_sfence()
	#else
		#define FlushWrites
	#endif
	#define FlushReadsAndWrites
#endif

#endif // #ifndef MAX_COMPILING_MEMORYBARRIER_HPP
