// Copyright 2016, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_CPU_ASSOCIATIVITY_HPP
#define MAX_CPU_ASSOCIATIVITY_HPP

#include <cstdint>

namespace max
{
namespace CPU
{

	// A set can be fully associative or have N-many ways of associativity.
	// This class holds the associativity information while protecting from bad state.
	class Associativity
	{
	public:

		struct UnknownAssociativity {};
		struct FullyAssociative {};

		explicit Associativity( const UnknownAssociativity )         noexcept;
		explicit Associativity( const FullyAssociative )             noexcept;
		explicit Associativity( const uint32_t WaysOfAssociativity ) noexcept;
		Associativity()                                              noexcept = delete;
		Associativity( const Associativity & rhs )                   noexcept = default;
		Associativity( Associativity && rhs )                        noexcept = default;
		~Associativity()                                             noexcept = default;

		Associativity & operator =( const Associativity & rhs ) noexcept = default;
		Associativity & operator =( Associativity && rhs )      noexcept = default;

		bool IsUnknown()               const noexcept;
		bool IsFullyAssociative()      const noexcept;
		uint32_t WaysOfAssociativity() const noexcept;

		void SetUnknown()                                                 noexcept;
		void SetFullyAssociative()                                        noexcept;
		void SetWaysOfAssociativity( const uint32_t WaysOfAssociativity ) noexcept;

	private:

		bool     Unknown;
		bool     Fully;
		uint32_t Ways;

	};

} // namespace CPU
} // namespace max

#endif // MAX_CPU_ASSOCIATIVITY_HPP
