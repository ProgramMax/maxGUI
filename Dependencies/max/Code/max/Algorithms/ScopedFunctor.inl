// Copyright 2015, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

namespace max
{
namespace Algorithms
{

	template< typename FunctorType >
	ScopedFunctor< FunctorType > MakeScopedFunctor( const FunctorType & Functor ) MAX_DOES_NOT_THROW
	{
		return ScopedFunctor< FunctorType >( Functor );
	}

	template< typename FunctorType >
	ScopedFunctor< FunctorType > MakeScopedFunctor( FunctorType && Functor ) MAX_DOES_NOT_THROW
	{
		return ScopedFunctor< FunctorType >( std::move( Functor ) );
	}

	template< typename FunctorType >
	ScopedFunctor< FunctorType >::ScopedFunctor( const FunctorType & Functor ) MAX_DOES_NOT_THROW
		: Functor( Functor )
	{
	}

	template< typename FunctorType >
	ScopedFunctor< FunctorType >::ScopedFunctor( FunctorType && Functor ) MAX_DOES_NOT_THROW
		: Functor( std::move( Functor ) )
	{
	}

	template< typename FunctorType >
	ScopedFunctor< FunctorType >::~ScopedFunctor() MAX_DOES_NOT_THROW
	{
		Functor();
	}

} // namespace Algorithms
} // namespace max
