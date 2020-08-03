// Copyright 2017, Chris Blume. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_COMPILING_LOOP_HPP
#define MAX_COMPILING_LOOP_HPP

namespace max
{
namespace Compiling
{

	template< typename LoopBody, typename FinalIterationBody, size_t IterationsLeft >
	class Loop
	{
	public:

		MAX_SEMI_PURE_DECLARATION( static constexpr void Run() noexcept );

	}; // class Loop

	template< typename LoopBody, typename FinalIterationBody >
	class Loop< LoopBody, FinalIterationBody, 0 >
	{
	public:

		MAX_SEMI_PURE_DECLARATION( static constexpr void Run() noexcept );

	};

} // namespace Compiling
} // namespace max

#include <max/Compiling/Loop.inl>

#endif // #ifndef MAX_COMPILING_LOOP_HPP