// Copyright 2015, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

namespace max
{
namespace Algorithms
{

	template< typename FunctorType >
	ScopedFunctor< FunctorType > MakeScopedFunctor( const FunctorType & Functor ) noexcept
	{
		return ScopedFunctor< FunctorType >( Functor );
	}

	template< typename FunctorType >
	ScopedFunctor< FunctorType > MakeScopedFunctor( FunctorType && Functor ) noexcept
	{
		return ScopedFunctor< FunctorType >( std::move( Functor ) );
	}

	template< typename FunctorType >
	ScopedFunctor< FunctorType >::ScopedFunctor( const FunctorType & Functor ) noexcept
		: Functor( Functor )
	{
	}

	template< typename FunctorType >
	ScopedFunctor< FunctorType >::ScopedFunctor( FunctorType && Functor ) noexcept
		: Functor( std::move( Functor ) )
	{
	}

	template< typename FunctorType >
	ScopedFunctor< FunctorType >::~ScopedFunctor() noexcept
	{
		Functor();
	}

} // namespace Algorithms
} // namespace max
