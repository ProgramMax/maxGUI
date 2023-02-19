// Copyright 2018, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <utility>

namespace max
{
namespace v0
{
namespace Containers
{

	template< typename PointOrdinateType, typename LengthType >
	Rectangle< PointOrdinateType, LengthType >::Rectangle( CartesianPoint< PointOrdinateType, 2 > TopLeft, LengthType Width, LengthType Height ) noexcept
		: TopLeft(std::move(TopLeft))
		, Width(std::move(Width))
		, Height(std::move(Height))
	{}

} // namespace Containers
} // namespace v0
} // namespace max
