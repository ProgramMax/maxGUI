// Copyright 2015, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_COMPILING_ASSUME_HPP
#define MAX_COMPILING_ASSUME_HPP

#include <max/Compiling/Configuration/Compiler.hpp>

#ifdef MAX_COMPILER_VC
	#define MAX_ASSUME( Expression ) __assume( Expression )
#else
	#define MAX_ASSUME( Expression )
#endif

#endif // #ifndef MAX_COMPILING_ASSUME_HPP
