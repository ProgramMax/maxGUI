// Copyright 2017, Chris Blume. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

namespace max
{
namespace Compiling
{
	
	template< typename LoopBody, typename FinalIterationBody, size_t IterationsLeft >
	MAX_SEMI_PURE_DEFINITION( void Loop::Run() MAX_DOES_NOT_THROW )
	{
		LoopBody();
		Loop< LoopBody, FinalIterationBody, IterationsLeft - 1 >::Run();
	}

	template< typename LoopBody, typename FinalIterationBody >
	MAX_SEMI_PURE_DEFINITION( void Loop< LoopBody, FinalIterationBody, 0 >::Run() MAX_DOES_NOT_THROW )
	{
		FinalIterationBody();
	}

} // namespace Compiling
} // namespace max