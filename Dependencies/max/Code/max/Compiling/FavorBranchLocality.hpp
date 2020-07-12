// Copyright 2015, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_COMPILING_FAVOR_BRANCH_LOCALITY_HPP
#define MAX_COMPILING_FAVOR_BRANCH_LOCALITY_HPP

// Usage:
// if( MAX_FAVOR_TRUE_CASE( x == 0 ) )
// if( MAX_FAVOR_FALSE_CASE( x == 0 ) )

#include <max/Compiling/Configuration/Compiler.hpp>

#ifdef MAX_COMPILER_GCC
	#define MAX_FAVOR_BRANCH_LOCALITY( Expression, ExpectedValue ) __builtin_expect( Expression, ExpectedValue )
#else
	#define MAX_FAVOR_BRANCH_LOCALITY( Expression, ExpectedValue ) Expression
#endif

#define MAX_FAVOR_TRUE_CASE( Expression ) MAX_FAVOR_BRANCH_LOCALITY( Expression, true )
#define MAX_FAVOR_FALSE_CASE( Expression ) MAX_FAVOR_BRANCH_LOCALITY( Expression, false )

#endif // #ifndef MAX_COMPILING_FAVOR_BRANCH_LOCALITY_HPP
