// Copyright 2020, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <max/Compiling/Configuration.hpp>

#if defined( MAX_IS_CONSTANT_EVALUATED_SUPPORTED )
#include <type_traits>
#endif

namespace max
{
	namespace v0
	{
		namespace Compiling
		{
			namespace Polyfills
			{

				MAX_PURE_DEFINITION( constexpr inline bool IsConstantEvaluated() MAX_DOES_NOT_THROW )
				{
					#if defined( MAX_IS_CONSTANT_EVALUATED_SUPPORTED )
						return std::is_constant_evaluated();
					#else
						return false;
					#endif
				}

			} // namespace Polyfills
		} // namespace Algorithms
	} // namespace v0
} // namespace max