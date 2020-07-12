// Copyright 2015, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_ALGORITHMS_YIELD_HPP
#define MAX_ALGORITHMS_YIELD_HPP

#include <max/Compiling/Configuration/Compiler.hpp>

#ifdef MAX_COMPILER_VC
	#ifdef MAX_IA64
		#include <intrin.h>
		#define MAX_YIELD __yield()
	#else
		// This is only supported on SSE machines
		// But earlier machines generate a nop which means we don't need to test for SSE support
		#include <xmmintrin.h>
		#define MAX_YEILD _mm_pause()
	#endif
#else
	#define MAX_YIELD
#endif

#endif // #ifndef MAX_ALGORITHMS_YIELD_HPP
