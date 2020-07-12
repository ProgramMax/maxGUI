// Copyright 2015, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_COMPILING_THROWSPECIFICATION_HPP
#define MAX_COMPILING_THROWSPECIFICATION_HPP

#include <max/Compiling/Configuration.hpp>

#if defined(MAX_EXCEPTIONS_SUPPORTED)
	#if defined(MAX_NOEXCEPT_SUPPORTED)
		#define MAX_DOES_NOT_THROW noexcept
	#else
		#define MAX_DOES_NOT_THROW throw()
	#endif
#else
	#define MAX_DOES_NOT_THROW
#endif

#endif // #ifndef MAX_COMPILING_THROWSPECIFICATION_HPP
