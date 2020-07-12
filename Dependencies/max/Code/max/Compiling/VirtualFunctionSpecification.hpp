// Copyright 2015, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_COMPILING_VIRTUALFUNCTIONSPECIFICATION_HPP
#define MAX_COMPILING_VIRTUALFUNCTIONSPECIFICATION_HPP

#if defined( MAX_CPP11_OVERRIDE_SUPPORTED )
	#define MAX_OVERRIDE( DECLARATOR ) DECLARATOR override
#else
	#define MAX_OVERRIDE( DECLARATOR ) virtual DECLARATOR
#endif

#if defined( MAX_CPP11_FINAL_SUPPORTED )
	#define MAX_FINAL( DECLARATOR ) DECLARATOR final
#else
	#define MAX_FINAL( DECLARATOR ) virtual DECLARATOR
#endif

#endif // #ifndef MAX_COMPILING_VIRTUALFUNCTIONSPECIFICATION_HPP
