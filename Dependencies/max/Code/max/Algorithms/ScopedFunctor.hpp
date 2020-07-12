// Copyright 2015, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_ALGORITHMS_SCOPEDFUNCTOR_HPP
#define MAX_ALGORITHMS_SCOPEDFUNCTOR_HPP

#include <functional>
#include <max/Compiling/ThrowSpecification.hpp>

namespace max
{
namespace Algorithms
{

	template< typename FunctorType >
	class ScopedFunctor;

	template< typename FunctorType >
	ScopedFunctor< FunctorType > MakeScopedFunctor( const FunctorType & Functor ) MAX_DOES_NOT_THROW;

	template< typename FunctorType >
	ScopedFunctor< FunctorType > MakeScopedFunctor( FunctorType && Functor ) MAX_DOES_NOT_THROW;

	template< typename FunctorType >
	class ScopedFunctor
	{
	public:

		explicit ScopedFunctor( const FunctorType & Functor ) MAX_DOES_NOT_THROW;
		explicit ScopedFunctor( FunctorType && Functor ) MAX_DOES_NOT_THROW;
		~ScopedFunctor() MAX_DOES_NOT_THROW;

	private:

		const FunctorType Functor;

	}; // class ScopedFunctor

} // namespace Algorithms
} // namespace max

#include <max/Algorithms/ScopedFunctor.inl>

#endif // #ifndef MAX_ALGORITMS_SCOPEDFUNCTOR_HPP
