// Copyright 2015, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_ALGORITHMS_OPTIMIZINGASSERT_HPP
#define MAX_ALGORITHMS_OPTIMIZINGASSERT_HPP

#include <max/Compiling/Assume.hpp>

#ifdef DEBUG
	#define MAX_OPTIMIZING_ASSERT( Expression ) (( Expression ) || assert( __FILE__, __LINE__ )
#else
	#define MAX_OPTIMIZING_ASSERT( Expression ) MAX_ASSUME( Expression )
#endif

#endif // #ifndef MAX_ALGORITHMS_OPTIMIZINGASSERT_HPP
