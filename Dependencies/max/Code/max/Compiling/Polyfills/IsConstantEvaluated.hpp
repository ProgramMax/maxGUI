// Copyright 2020, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_COMPILING_POLYFILLS_ISCONSTANTEVALUATED_HPP
#define MAX_COMPILING_POLYFILLS_ISCONSTANTEVALUATED_HPP

#include <max/Compiling/CurrentVersionNamespace.hpp>
#include <max/Compiling/AliasingOptimizations.hpp>
#include <max/Compiling/ThrowSpecification.hpp>

namespace max
{
	MAX_CURRENT_VERSION_NAMESPACE_BEGIN(v0)
	{
		namespace Compiling
		{
			namespace Polyfills
			{

				MAX_PURE_DECLARATION( constexpr inline bool polyfill_is_constant_evaluated() MAX_DOES_NOT_THROW );

			} // namespace Polyfills
		} // namespace Algorithms
	} // MAX_CURRENT_VERSION_NAMESPACE_BEGIN( v0 )
	MAX_CURRENT_VERSION_NAMESPACE_END(v0)
} // namespace max

#include <max/Compiling/Polyfills/IsConstantEvaluated.inl>

#endif // #ifndef MAX_ALGORITHMS_BITSCAN_HPP