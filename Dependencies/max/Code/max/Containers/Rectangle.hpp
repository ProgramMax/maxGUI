// Copyright 2021, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_CONTAINERS_RECTANGLE_HPP
#define MAX_CONTAINERS_RECTANGLE_HPP

#include <max/Compiling/CurrentVersionNamespace.hpp>
#include <max/Compiling/AliasingOptimizations.hpp>
#include <max/Containers/Point.hpp>
#include <initializer_list>
#include <array>

namespace max
{
MAX_CURRENT_VERSION_NAMESPACE_BEGIN( v0 )
{
namespace Containers
{

	template< typename PointOrdinateType, typename LengthType >
	class Rectangle
	{
	public:

		Rectangle() noexcept = default;
		Rectangle( CartesianPoint< PointOrdinateType, 2 > TopLeft, LengthType Width, LengthType Height ) noexcept;

		CartesianPoint< PointOrdinateType, 2 > TopLeft;
		LengthType Width;
		LengthType Height;

	};

} // namespace Containers
} // MAX_CURRENT_VERSION_NAMESPACE_BEGIN( v0 )
MAX_CURRENT_VERSION_NAMESPACE_END( v0 )
} // namespace max

#include "Rectangle.inl"

#endif // #ifndef MAX_CONTAINERS_RECTANGLE_HPP
