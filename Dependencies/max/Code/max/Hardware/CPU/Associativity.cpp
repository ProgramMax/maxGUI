// Copyright 2016, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <max/Hardware/CPU/Associativity.hpp>

namespace max
{
namespace CPU
{

	Associativity::Associativity( const Associativity::UnknownAssociativity ) noexcept
		: Unknown( true  )
		, Fully(   false )
		, Ways(    0     )
	{
	}

	Associativity::Associativity( const Associativity::FullyAssociative ) noexcept
		: Unknown( false )
		, Fully(   true  )
		, Ways(    0     )
	{
	}

	Associativity::Associativity( const uint32_t WaysOfAssociativity ) noexcept
		: Unknown( false               )
		, Fully(   false               )
		, Ways(    WaysOfAssociativity )
	{
	}

	bool Associativity::IsUnknown() const noexcept
	{
		return Unknown;
	}

	bool Associativity::IsFullyAssociative() const noexcept
	{
		return Fully;
	}
	
	uint32_t Associativity::WaysOfAssociativity() const noexcept
	{
		return Ways;
	}

	void Associativity::SetUnknown() noexcept
	{
		Unknown = true;
		Fully   = false;
		Ways    = 0;
	}

	void Associativity::SetFullyAssociative() noexcept
	{
		Unknown = false;
		Fully   = true;
		Ways    = 0;
	}
	
	void Associativity::SetWaysOfAssociativity( const uint32_t WaysOfAssociativity ) noexcept
	{
		Unknown = false;
		Fully   = false;
		Ways    = WaysOfAssociativity;
	}

} // namespace CPU
} // namespace max
