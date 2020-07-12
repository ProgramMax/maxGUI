// Copyright 2020, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "CountZeroesTest.hpp"
#include <max/Algorithms/CountZeroes.hpp>
#include <max/Testing/TestSuite.hpp>
#include <max/Testing/CoutResultPolicy.hpp>
#include <utility>

namespace maxAutomatedTests
{
	namespace Algorithms
	{

		void RunCountZeroesTestSuite()
		{
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001 } ) ==  0, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010 } ) ==  1, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100 } ) ==  2, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000 } ) ==  3, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000 } ) ==  4, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000 } ) ==  5, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000 } ) ==  6, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000 } ) ==  7, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000 } ) ==  8, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000 } ) ==  9, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000 } ) == 10, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000 } ) == 11, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000 } ) == 12, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000 } ) == 13, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000 } ) == 14, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000 } ) == 15, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000 } ) == 16, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000 } ) == 17, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000 } ) == 18, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000 } ) == 19, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000 } ) == 20, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000 } ) == 21, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000 } ) == 22, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000 } ) == 23, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000 } ) == 24, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000 } ) == 25, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000 } ) == 26, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000 } ) == 27, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000 } ) == 28, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000 } ) == 29, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000 } ) == 30, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000 } ) == 31, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 32, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 33, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 34, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 35, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 36, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 37, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 38, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 39, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 40, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 41, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 42, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 43, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 44, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 45, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 46, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 47, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 48, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 49, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 50, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 51, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 52, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 53, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 54, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 55, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 56, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 57, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 58, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 59, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 60, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 61, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 62, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 63, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );

			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1111'1111'1100'0000 } ) ==  6, "max::Algorithms::CountTrailingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );


			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001 } ) ==  0, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010 } ) ==  1, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100 } ) ==  2, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000 } ) ==  3, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000 } ) ==  4, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000 } ) ==  5, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000 } ) ==  6, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000 } ) ==  7, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000 } ) ==  8, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000 } ) ==  9, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000 } ) == 10, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000 } ) == 11, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000 } ) == 12, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000 } ) == 13, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000 } ) == 14, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000 } ) == 15, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000 } ) == 16, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000 } ) == 17, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000 } ) == 18, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000 } ) == 19, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000 } ) == 20, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000 } ) == 21, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000 } ) == 22, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000 } ) == 23, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000 } ) == 24, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000 } ) == 25, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000 } ) == 26, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000 } ) == 27, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000 } ) == 28, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000 } ) == 29, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000 } ) == 30, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000 } ) == 31, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 32, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 33, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 34, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 35, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 36, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 37, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 38, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 39, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 40, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 41, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 42, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 43, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 44, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 45, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 46, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 47, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 48, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 49, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 50, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 51, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 52, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 53, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 54, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 55, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 56, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 57, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 58, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 59, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 60, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 61, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 62, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( static_cast< int64_t >( uint64_t{ 0b1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ) == 63, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );

			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1111'1111'1100'0000 } ) ==  6, "max::Algorithms::CountTrailingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );


			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0000'0001 } ) ==  0, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0000'0010 } ) ==  1, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 1 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0000'0100 } ) ==  2, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 2 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0000'1000 } ) ==  3, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 3 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0001'0000 } ) ==  4, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 4 set."  ); //-V112
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0010'0000 } ) ==  5, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 5 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0100'0000 } ) ==  6, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 6 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0000'0000'1000'0000 } ) ==  7, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 7 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0000'0001'0000'0000 } ) ==  8, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 8 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0000'0010'0000'0000 } ) ==  9, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 9 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0000'0100'0000'0000 } ) == 10, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 10 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0000'1000'0000'0000 } ) == 11, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 11 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0001'0000'0000'0000 } ) == 12, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 12 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0010'0000'0000'0000 } ) == 13, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 13 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0100'0000'0000'0000 } ) == 14, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 14 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'1000'0000'0000'0000 } ) == 15, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 15 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0001'0000'0000'0000'0000 } ) == 16, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 16 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0010'0000'0000'0000'0000 } ) == 17, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 17 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0100'0000'0000'0000'0000 } ) == 18, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 18 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'1000'0000'0000'0000'0000 } ) == 19, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 19 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'0001'0000'0000'0000'0000'0000 } ) == 20, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 20 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'0010'0000'0000'0000'0000'0000 } ) == 21, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 21 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'0100'0000'0000'0000'0000'0000 } ) == 22, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 22 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'1000'0000'0000'0000'0000'0000 } ) == 23, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 23 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0001'0000'0000'0000'0000'0000'0000 } ) == 24, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 24 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0010'0000'0000'0000'0000'0000'0000 } ) == 25, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 25 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0100'0000'0000'0000'0000'0000'0000 } ) == 26, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 26 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'1000'0000'0000'0000'0000'0000'0000 } ) == 27, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 27 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0001'0000'0000'0000'0000'0000'0000'0000 } ) == 28, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 28 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0010'0000'0000'0000'0000'0000'0000'0000 } ) == 29, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 29 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0100'0000'0000'0000'0000'0000'0000'0000 } ) == 30, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 30 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( static_cast< int32_t >( uint32_t{ 0b1000'0000'0000'0000'0000'0000'0000'0000 } ) ) == 31, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 31 set." );

			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'1111'1111'1111'1000 } ) ==  3, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) should report the last significant set bit.");


			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0000'0000'0000'0001 } ) ==  0, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0000'0000'0000'0010 } ) ==  1, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 1 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0000'0000'0000'0100 } ) ==  2, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 2 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0000'0000'0000'1000 } ) ==  3, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 3 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0000'0000'0001'0000 } ) ==  4, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 4 set."  ); //-V112
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0000'0000'0010'0000 } ) ==  5, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 5 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0000'0000'0100'0000 } ) ==  6, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 6 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0000'0000'1000'0000 } ) ==  7, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 7 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0000'0001'0000'0000 } ) ==  8, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 8 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0000'0010'0000'0000 } ) ==  9, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 9 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0000'0100'0000'0000 } ) == 10, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 10 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0000'1000'0000'0000 } ) == 11, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 11 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0001'0000'0000'0000 } ) == 12, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 12 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0010'0000'0000'0000 } ) == 13, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 13 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0100'0000'0000'0000 } ) == 14, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 14 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'1000'0000'0000'0000 } ) == 15, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 15 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0001'0000'0000'0000'0000 } ) == 16, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 16 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0010'0000'0000'0000'0000 } ) == 17, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 17 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0100'0000'0000'0000'0000 } ) == 18, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 18 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0000'0000'1000'0000'0000'0000'0000 } ) == 19, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 19 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0000'0001'0000'0000'0000'0000'0000 } ) == 20, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 20 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0000'0010'0000'0000'0000'0000'0000 } ) == 21, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 21 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0000'0100'0000'0000'0000'0000'0000 } ) == 22, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 22 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0000'1000'0000'0000'0000'0000'0000 } ) == 23, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 23 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0001'0000'0000'0000'0000'0000'0000 } ) == 24, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 24 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0010'0000'0000'0000'0000'0000'0000 } ) == 25, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 25 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'0100'0000'0000'0000'0000'0000'0000 } ) == 26, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 26 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0000'1000'0000'0000'0000'0000'0000'0000 } ) == 27, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 27 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0001'0000'0000'0000'0000'0000'0000'0000 } ) == 28, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 28 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0010'0000'0000'0000'0000'0000'0000'0000 } ) == 29, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 29 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int32_t{ 0b0100'0000'0000'0000'0000'0000'0000'0000 } ) == 30, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 30 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( static_cast< int32_t >( uint32_t{ 0b1000'0000'0000'0000'0000'0000'0000'0000 } ) ) == 31, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) not reporting bit 31 set." );

			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( static_cast< int32_t >( uint32_t{ 0b0000'0000'0000'0000'1111'1111'1111'1000 } ) ) == 3, "max::Algorithms::CountTrailingZeroesConstexpr( uint32_t ) should report the last significant set bit.");


			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint16_t{ 0b0000'0000'0000'0001 } ) ==  0, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint16_t{ 0b0000'0000'0000'0010 } ) ==  1, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 1 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint16_t{ 0b0000'0000'0000'0100 } ) ==  2, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 2 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint16_t{ 0b0000'0000'0000'1000 } ) ==  3, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 3 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint16_t{ 0b0000'0000'0001'0000 } ) ==  4, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 4 set."  ); //-V112
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint16_t{ 0b0000'0000'0010'0000 } ) ==  5, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 5 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint16_t{ 0b0000'0000'0100'0000 } ) ==  6, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 6 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint16_t{ 0b0000'0000'1000'0000 } ) ==  7, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 7 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint16_t{ 0b0000'0001'0000'0000 } ) ==  8, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 8 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint16_t{ 0b0000'0010'0000'0000 } ) ==  9, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 9 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint16_t{ 0b0000'0100'0000'0000 } ) == 10, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 10 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint16_t{ 0b0000'1000'0000'0000 } ) == 11, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 11 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint16_t{ 0b0001'0000'0000'0000 } ) == 12, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 12 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint16_t{ 0b0010'0000'0000'0000 } ) == 13, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 13 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint16_t{ 0b0100'0000'0000'0000 } ) == 14, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 14 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint16_t{ 0b1000'0000'0000'0000 } ) == 15, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 15 set." );

			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint16_t{ 0b1111'1111'1111'1000 } ) ==  3, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) should report the last significant set bit." );


			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int16_t{ 0b0000'0000'0000'0001 } ) ==  0, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int16_t{ 0b0000'0000'0000'0010 } ) ==  1, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 1 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int16_t{ 0b0000'0000'0000'0100 } ) ==  2, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 2 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int16_t{ 0b0000'0000'0000'1000 } ) ==  3, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 3 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int16_t{ 0b0000'0000'0001'0000 } ) ==  4, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 4 set."  ); //-V112
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int16_t{ 0b0000'0000'0010'0000 } ) ==  5, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 5 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int16_t{ 0b0000'0000'0100'0000 } ) ==  6, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 6 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int16_t{ 0b0000'0000'1000'0000 } ) ==  7, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 7 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int16_t{ 0b0000'0001'0000'0000 } ) ==  8, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 8 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int16_t{ 0b0000'0010'0000'0000 } ) ==  9, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 9 set."  );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int16_t{ 0b0000'0100'0000'0000 } ) == 10, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 10 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int16_t{ 0b0000'1000'0000'0000 } ) == 11, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 11 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int16_t{ 0b0001'0000'0000'0000 } ) == 12, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 12 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int16_t{ 0b0010'0000'0000'0000 } ) == 13, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 13 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int16_t{ 0b0100'0000'0000'0000 } ) == 14, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 14 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( static_cast< int16_t >( uint16_t{ 0b1000'0000'0000'0000 } ) ) == 15, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) not reporting bit 15 set." );

			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( static_cast< int16_t >( uint16_t{ 0b1111'1111'1111'1000 } ) ) ==  3, "max::Algorithms::CountTrailingZeroesConstexpr( uint16_t ) should report the last significant set bit." );


			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint8_t{ 0b0000'0001 } ) == 0, "max::Algorithms::CountTrailingZeroesConstexpr not reporting bit 0 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint8_t{ 0b0000'0010 } ) == 1, "max::Algorithms::CountTrailingZeroesConstexpr not reporting bit 1 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint8_t{ 0b0000'0100 } ) == 2, "max::Algorithms::CountTrailingZeroesConstexpr not reporting bit 2 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint8_t{ 0b0000'1000 } ) == 3, "max::Algorithms::CountTrailingZeroesConstexpr not reporting bit 3 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint8_t{ 0b0001'0000 } ) == 4, "max::Algorithms::CountTrailingZeroesConstexpr not reporting bit 4 set." ); //-V112
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint8_t{ 0b0010'0000 } ) == 5, "max::Algorithms::CountTrailingZeroesConstexpr not reporting bit 5 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint8_t{ 0b0100'0000 } ) == 6, "max::Algorithms::CountTrailingZeroesConstexpr not reporting bit 6 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint8_t{ 0b1000'0000 } ) == 7, "max::Algorithms::CountTrailingZeroesConstexpr not reporting bit 7 set." );

			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( uint8_t{ 0b1111'1000 } ) == 3, "max::Algorithms::CountTrailingZeroesConstexpr should report the least significant set bit." );


			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int8_t{ 0b0000'0001 } ) == 0, "max::Algorithms::CountTrailingZeroesConstexpr not reporting bit 0 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int8_t{ 0b0000'0010 } ) == 1, "max::Algorithms::CountTrailingZeroesConstexpr not reporting bit 1 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int8_t{ 0b0000'0100 } ) == 2, "max::Algorithms::CountTrailingZeroesConstexpr not reporting bit 2 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int8_t{ 0b0000'1000 } ) == 3, "max::Algorithms::CountTrailingZeroesConstexpr not reporting bit 3 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int8_t{ 0b0001'0000 } ) == 4, "max::Algorithms::CountTrailingZeroesConstexpr not reporting bit 4 set." ); //-V112
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int8_t{ 0b0010'0000 } ) == 5, "max::Algorithms::CountTrailingZeroesConstexpr not reporting bit 5 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( int8_t{ 0b0100'0000 } ) == 6, "max::Algorithms::CountTrailingZeroesConstexpr not reporting bit 6 set." );
			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( static_cast< int8_t >( uint8_t{ 0b1000'0000 } ) ) == 7, "max::Algorithms::CountTrailingZeroesConstexpr not reporting bit 7 set." );

			static_assert( max::Algorithms::CountTrailingZeroesConstexpr( static_cast< int8_t >( uint8_t{ 0b1111'1000 } ) ) == 3, "max::Algorithms::CountTrailingZeroesConstexpr should report the least significant set bit." );


			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001 } ) == 63, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010 } ) == 62, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 1 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100 } ) == 61, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 2 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000 } ) == 60, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 3 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000 } ) == 59, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 4 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000 } ) == 58, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 5 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000 } ) == 57, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 6 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000 } ) == 56, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 7 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000 } ) == 55, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 8 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000 } ) == 54, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 9 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000 } ) == 53, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 10 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000 } ) == 52, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 11 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000 } ) == 51, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 12 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000 } ) == 50, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 13 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000 } ) == 49, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 14 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000 } ) == 48, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 15 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000 } ) == 47, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 16 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000 } ) == 46, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 17 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000 } ) == 45, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 18 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000 } ) == 44, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 19 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000 } ) == 43, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 20 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000 } ) == 42, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 21 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000 } ) == 41, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 22 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000 } ) == 40, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 23 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000 } ) == 39, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 24 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000 } ) == 38, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 25 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000 } ) == 37, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 26 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000 } ) == 36, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 27 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000 } ) == 35, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 28 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000 } ) == 34, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 29 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000 } ) == 33, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 30 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000 } ) == 32, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 31 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 31, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 32 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 30, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 33 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 29, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 34 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 28, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 35 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 27, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 36 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 26, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 37 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 25, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 38 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 24, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 39 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 23, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 40 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 22, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 41 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 21, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 42 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 20, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 43 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 19, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 44 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 18, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 45 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 17, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 46 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 16, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 47 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 15, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 48 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 14, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 49 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 13, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 50 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 12, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 51 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 11, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 52 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 10, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 53 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  9, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 54 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  8, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 55 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  7, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 56 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  6, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 57 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  5, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 58 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  4, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 59 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  3, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 60 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  2, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 61 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  1, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 62 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  0, "max::Algorithms::CountLeadingZeroesConstexpr( uint64_t ) not reporting bit 63 set." );

			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1111'1111'1100'0000 } ) == 48, "max::Algorithms::CountLeadingZeroesConstexpr should report the most significant set bit."  );


			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001 } ) == 63, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010 } ) == 62, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 1 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100 } ) == 61, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 2 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000 } ) == 60, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 3 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000 } ) == 59, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 4 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000 } ) == 58, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 5 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000 } ) == 57, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 6 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000 } ) == 56, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 7 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000 } ) == 55, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 8 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000 } ) == 54, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 9 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000 } ) == 53, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 10 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000 } ) == 52, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 11 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000 } ) == 51, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 12 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000 } ) == 50, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 13 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000 } ) == 49, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 14 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000 } ) == 48, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 15 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000 } ) == 47, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 16 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000 } ) == 46, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 17 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000 } ) == 45, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 18 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000 } ) == 44, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 19 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000 } ) == 43, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 20 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000 } ) == 42, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 21 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000 } ) == 41, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 22 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000 } ) == 40, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 23 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000 } ) == 39, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 24 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000 } ) == 38, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 25 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000 } ) == 37, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 26 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000 } ) == 36, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 27 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000 } ) == 35, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 28 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000 } ) == 34, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 29 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000 } ) == 33, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 30 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000 } ) == 32, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 31 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 31, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 32 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 30, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 33 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 29, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 34 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 28, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 35 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 27, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 36 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 26, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 37 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 25, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 38 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 24, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 39 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 23, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 40 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 22, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 41 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 21, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 42 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 20, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 43 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 19, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 44 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 18, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 45 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 17, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 46 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 16, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 47 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 15, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 48 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 14, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 49 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 13, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 50 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 12, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 51 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 11, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 52 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 10, "max::Algorithms::CountLeadinggZeroesConstexpr( int64_t ) not reporting bit 53 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  9, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 54 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  8, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 55 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  7, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 56 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  6, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 57 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  5, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 58 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  4, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 59 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  3, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 60 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  2, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 61 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  1, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 62 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( static_cast< int64_t >( uint64_t{ 0b1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ) == 0, "max::Algorithms::CountLeadingZeroesConstexpr( int64_t ) not reporting bit 63 set." );

			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1111'1111'1100'0000 } ) ==  48, "max::Algorithms::CountLeadingZeroesConstexpr should report the most significant set bit." );


			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0000'0001 } ) == 31, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0000'0010 } ) == 30, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 1 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0000'0100 } ) == 29, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 2 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0000'1000 } ) == 28, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 3 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0001'0000 } ) == 27, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 4 set."  ); //-V112
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0010'0000 } ) == 26, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 5 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0100'0000 } ) == 25, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 6 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0000'0000'1000'0000 } ) == 24, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 7 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0000'0001'0000'0000 } ) == 23, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 8 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0000'0010'0000'0000 } ) == 22, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 9 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0000'0100'0000'0000 } ) == 21, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 10 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0000'1000'0000'0000 } ) == 20, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 11 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0001'0000'0000'0000 } ) == 19, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 12 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0010'0000'0000'0000 } ) == 18, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 13 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'0100'0000'0000'0000 } ) == 17, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 14 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'1000'0000'0000'0000 } ) == 16, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 15 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0001'0000'0000'0000'0000 } ) == 15, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 16 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0010'0000'0000'0000'0000 } ) == 14, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 17 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0100'0000'0000'0000'0000 } ) == 13, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 18 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'1000'0000'0000'0000'0000 } ) == 12, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 19 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'0001'0000'0000'0000'0000'0000 } ) == 11, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 20 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'0010'0000'0000'0000'0000'0000 } ) == 10, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 21 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'0100'0000'0000'0000'0000'0000 } ) ==  9, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 22 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'1000'0000'0000'0000'0000'0000 } ) ==  8, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 23 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0001'0000'0000'0000'0000'0000'0000 } ) ==  7, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 24 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0010'0000'0000'0000'0000'0000'0000 } ) ==  6, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 25 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0100'0000'0000'0000'0000'0000'0000 } ) ==  5, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 26 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'1000'0000'0000'0000'0000'0000'0000 } ) ==  4, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 27 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0001'0000'0000'0000'0000'0000'0000'0000 } ) ==  3, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 28 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0010'0000'0000'0000'0000'0000'0000'0000 } ) ==  2, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 29 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0100'0000'0000'0000'0000'0000'0000'0000 } ) ==  1, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 30 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( static_cast< int32_t >( uint32_t{ 0b1000'0000'0000'0000'0000'0000'0000'0000 } ) ) == 0, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 31 set." );

			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint32_t{ 0b0000'0000'0000'0000'1111'1111'1111'1000 } ) == 16,  "max::Algorithms::CountLeadingZeroesConstexpr should report the most significant set bit.");


			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0000'0000'0000'0001 } ) == 31, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0000'0000'0000'0010 } ) == 30, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 1 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0000'0000'0000'0100 } ) == 29, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 2 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0000'0000'0000'1000 } ) == 28, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 3 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0000'0000'0001'0000 } ) == 27, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 4 set."  ); //-V112
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0000'0000'0010'0000 } ) == 26, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 5 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0000'0000'0100'0000 } ) == 25, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 6 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0000'0000'1000'0000 } ) == 24, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 7 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0000'0001'0000'0000 } ) == 23, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 8 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0000'0010'0000'0000 } ) == 22, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 9 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0000'0100'0000'0000 } ) == 21, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 10 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0000'1000'0000'0000 } ) == 20, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 11 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0001'0000'0000'0000 } ) == 19, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 12 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0010'0000'0000'0000 } ) == 18, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 13 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'0100'0000'0000'0000 } ) == 17, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 14 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0000'1000'0000'0000'0000 } ) == 16, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 15 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0001'0000'0000'0000'0000 } ) == 15, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 16 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0010'0000'0000'0000'0000 } ) == 14, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 17 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0000'0000'0100'0000'0000'0000'0000 } ) == 13, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 18 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0000'0000'1000'0000'0000'0000'0000 } ) == 12, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 19 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0000'0001'0000'0000'0000'0000'0000 } ) == 11, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 20 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0000'0010'0000'0000'0000'0000'0000 } ) == 10, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 21 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0000'0100'0000'0000'0000'0000'0000 } ) ==  9, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 22 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0000'1000'0000'0000'0000'0000'0000 } ) ==  8, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 23 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0001'0000'0000'0000'0000'0000'0000 } ) ==  7, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 24 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0010'0000'0000'0000'0000'0000'0000 } ) ==  6, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 25 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'0100'0000'0000'0000'0000'0000'0000 } ) ==  5, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 26 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0000'1000'0000'0000'0000'0000'0000'0000 } ) ==  4, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 27 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0001'0000'0000'0000'0000'0000'0000'0000 } ) ==  3, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 28 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0010'0000'0000'0000'0000'0000'0000'0000 } ) ==  2, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 29 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int32_t{ 0b0100'0000'0000'0000'0000'0000'0000'0000 } ) ==  1, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 30 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( static_cast< int32_t >( uint32_t{ 0b1000'0000'0000'0000'0000'0000'0000'0000 } ) ) == 0, "max::Algorithms::CountLeadingZeroesConstexpr( uint32_t ) not reporting bit 31 set." );

			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( static_cast< int32_t >( uint32_t{ 0b0000'0000'0000'0000'1111'1111'1111'1000 } ) ) == 16,  "max::Algorithms::CountLeadingZeroesConstexpr should report the most significant set bit.");


			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint16_t{ 0b0000'0000'0000'0001 } ) == 15, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint16_t{ 0b0000'0000'0000'0010 } ) == 14, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 1 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint16_t{ 0b0000'0000'0000'0100 } ) == 13, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 2 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint16_t{ 0b0000'0000'0000'1000 } ) == 12, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 3 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint16_t{ 0b0000'0000'0001'0000 } ) == 11, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 4 set."  ); //-V112
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint16_t{ 0b0000'0000'0010'0000 } ) == 10, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 5 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint16_t{ 0b0000'0000'0100'0000 } ) ==  9, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 6 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint16_t{ 0b0000'0000'1000'0000 } ) ==  8, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 7 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint16_t{ 0b0000'0001'0000'0000 } ) ==  7, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 8 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint16_t{ 0b0000'0010'0000'0000 } ) ==  6, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 9 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint16_t{ 0b0000'0100'0000'0000 } ) ==  5, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 10 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint16_t{ 0b0000'1000'0000'0000 } ) ==  4, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 11 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint16_t{ 0b0001'0000'0000'0000 } ) ==  3, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 12 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint16_t{ 0b0010'0000'0000'0000 } ) ==  2, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 13 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint16_t{ 0b0100'0000'0000'0000 } ) ==  1, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 14 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint16_t{ 0b1000'0000'0000'0000 } ) ==  0, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 15 set." );

			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint16_t{ 0b0000'0000'1111'1000 } ) == 8, "max::Algorithms::CountLeadingZeroesConstexpr should report the most significant set bit." );


			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int16_t{ 0b0000'0000'0000'0001 } ) == 15, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 0 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int16_t{ 0b0000'0000'0000'0010 } ) == 14, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 1 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int16_t{ 0b0000'0000'0000'0100 } ) == 13, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 2 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int16_t{ 0b0000'0000'0000'1000 } ) == 12, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 3 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int16_t{ 0b0000'0000'0001'0000 } ) == 11, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 4 set."  ); //-V112
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int16_t{ 0b0000'0000'0010'0000 } ) == 10, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 5 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int16_t{ 0b0000'0000'0100'0000 } ) ==  9, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 6 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int16_t{ 0b0000'0000'1000'0000 } ) ==  8, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 7 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int16_t{ 0b0000'0001'0000'0000 } ) ==  7, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 8 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int16_t{ 0b0000'0010'0000'0000 } ) ==  6, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 9 set."  );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int16_t{ 0b0000'0100'0000'0000 } ) ==  5, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 10 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int16_t{ 0b0000'1000'0000'0000 } ) ==  4, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 11 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int16_t{ 0b0001'0000'0000'0000 } ) ==  3, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 12 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int16_t{ 0b0010'0000'0000'0000 } ) ==  2, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 13 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int16_t{ 0b0100'0000'0000'0000 } ) ==  1, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 14 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( static_cast< int16_t >( uint16_t{ 0b1000'0000'0000'0000 } ) ) == 0, "max::Algorithms::CountLeadingZeroesConstexpr( uint16_t ) not reporting bit 15 set." );

			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( static_cast< int16_t >( uint16_t{ 0b0011'1111'1111'1000 } ) ) == 2, "max::Algorithms::CountLeadingZeroesConstexpr should report the most significant set bit." );


			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint8_t{ 0b0000'0001 } ) == 7, "max::Algorithms::CountLeadingZeroesConstexpr not reporting bit 0 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint8_t{ 0b0000'0010 } ) == 6, "max::Algorithms::CountLeadingZeroesConstexpr not reporting bit 1 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint8_t{ 0b0000'0100 } ) == 5, "max::Algorithms::CountLeadingZeroesConstexpr not reporting bit 2 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint8_t{ 0b0000'1000 } ) == 4, "max::Algorithms::CountLeadingZeroesConstexpr not reporting bit 3 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint8_t{ 0b0001'0000 } ) == 3, "max::Algorithms::CountLeadingZeroesConstexpr not reporting bit 4 set." ); //-V112
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint8_t{ 0b0010'0000 } ) == 2, "max::Algorithms::CountLeadingZeroesConstexpr not reporting bit 5 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint8_t{ 0b0100'0000 } ) == 1, "max::Algorithms::CountLeadingZeroesConstexpr not reporting bit 6 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint8_t{ 0b1000'0000 } ) == 0, "max::Algorithms::CountLeadingZeroesConstexpr not reporting bit 7 set." );

			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( uint8_t{ 0b0011'1000 } ) == 2, "max::Algorithms::CountLeadingZeroesConstexpr should report the most significant set bit." );


			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int8_t{ 0b0000'0001 } ) == 7, "max::Algorithms::CountLeadingZeroesConstexpr not reporting bit 0 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int8_t{ 0b0000'0010 } ) == 6, "max::Algorithms::CountLeadingZeroesConstexpr not reporting bit 1 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int8_t{ 0b0000'0100 } ) == 5, "max::Algorithms::CountLeadingZeroesConstexpr not reporting bit 2 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int8_t{ 0b0000'1000 } ) == 4, "max::Algorithms::CountLeadingZeroesConstexpr not reporting bit 3 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int8_t{ 0b0001'0000 } ) == 3, "max::Algorithms::CountLeadingZeroesConstexpr not reporting bit 4 set." ); //-V112
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int8_t{ 0b0010'0000 } ) == 2, "max::Algorithms::CountLeadingZeroesConstexpr not reporting bit 5 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( int8_t{ 0b0100'0000 } ) == 1, "max::Algorithms::CountLeadingZeroesConstexpr not reporting bit 6 set." );
			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( static_cast< int8_t >( uint8_t{ 0b1000'0000 } ) ) == 0, "max::Algorithms::CountLeadingZeroesConstexpr not reporting bit 7 set." );

			static_assert( max::Algorithms::CountLeadingZeroesConstexpr( static_cast< int8_t >( uint8_t{ 0b0011'1000 } ) ) == 2, "max::Algorithms::CountLeadingZeroesConstexpr should report the most significant set bit." );


			max::Testing::CoutResultPolicy ResultPolicy;
			auto BitScanTestSuite = max::Testing::TestSuite< max::Testing::CoutResultPolicy >{ "max::Algorithms::CountZeroes test suite", std::move( ResultPolicy ) };

			BitScanTestSuite.AddTest( max::Testing::Test< max::Testing::CoutResultPolicy >{ "CountTrailingZeroesConstexpr( uint64_t )", []( max::Testing::Test< max::Testing::CoutResultPolicy >& CurrentTest, max::Testing::CoutResultPolicy const& ResultPolicy ) {
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001 } ) ==  0 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010 } ) ==  1 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100 } ) ==  2 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000 } ) ==  3 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000 } ) ==  4 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000 } ) ==  5 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000 } ) ==  6 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000 } ) ==  7 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000 } ) ==  8 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000 } ) ==  9 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000 } ) == 10 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000 } ) == 11 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000 } ) == 12 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000 } ) == 13 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000 } ) == 14 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000 } ) == 15 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000 } ) == 16 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000 } ) == 17 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000 } ) == 18 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000 } ) == 19 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000 } ) == 20 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000 } ) == 21 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000 } ) == 22 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000 } ) == 23 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000 } ) == 24 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000 } ) == 25 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000 } ) == 26 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000 } ) == 27 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000 } ) == 28 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000 } ) == 29 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000 } ) == 30 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000 } ) == 31 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 32 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 33 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 34 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 35 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 36 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 37 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 38 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 39 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 40 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 41 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 42 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 43 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 44 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 45 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 46 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 47 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 48 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 49 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 50 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 51 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 52 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 53 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 54 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 55 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 56 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 57 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 58 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 59 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 60 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 61 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 62 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 63 );

				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1111'1111'1100'0000 } ) == 6 );
				}
			});

			BitScanTestSuite.AddTest( max::Testing::Test< max::Testing::CoutResultPolicy >{ "CountTrailingZeroesConstexpr( int64_t )", []( max::Testing::Test< max::Testing::CoutResultPolicy >& CurrentTest, max::Testing::CoutResultPolicy const& ResultPolicy ) {
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001 } ) ==  0 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010 } ) ==  1 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100 } ) ==  2 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000 } ) ==  3 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000 } ) ==  4 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000 } ) ==  5 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000 } ) ==  6 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000 } ) ==  7 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000 } ) ==  8 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000 } ) ==  9 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000 } ) == 10 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000 } ) == 11 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000 } ) == 12 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000 } ) == 13 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000 } ) == 14 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000 } ) == 15 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000 } ) == 16 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000 } ) == 17 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000 } ) == 18 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000 } ) == 19 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000 } ) == 20 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000 } ) == 21 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000 } ) == 22 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000 } ) == 23 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000 } ) == 24 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000 } ) == 25 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000 } ) == 26 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000 } ) == 27 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000 } ) == 28 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000 } ) == 29 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000 } ) == 30 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000 } ) == 31 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 32 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 33 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 34 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 35 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 36 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 37 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 38 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 39 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 40 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 41 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 42 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 43 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 44 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 45 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 46 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 47 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 48 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 49 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 50 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 51 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 52 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 53 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 54 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 55 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 56 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 57 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 58 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 59 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 60 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 61 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 62 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( static_cast< int64_t >( uint64_t{ 0b1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ) == 63 );

				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1111'1111'1100'0000 } ) == 6 );

				}
			});


			BitScanTestSuite.AddTest( max::Testing::Test< max::Testing::CoutResultPolicy >{ "CountTrailingZeroesConstexpr( uint32_t )", []( max::Testing::Test< max::Testing::CoutResultPolicy >& CurrentTest, max::Testing::CoutResultPolicy const& ResultPolicy ) {
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0000'0001 } ) ==  0 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0000'0010 } ) ==  1 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0000'0100 } ) ==  2 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0000'1000 } ) ==  3 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0001'0000 } ) ==  4 ); //-V112
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0010'0000 } ) ==  5 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0100'0000 } ) ==  6 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'0000'0000'0000'0000'1000'0000 } ) ==  7 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'0000'0000'0000'0001'0000'0000 } ) ==  8 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'0000'0000'0000'0010'0000'0000 } ) ==  9 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'0000'0000'0000'0100'0000'0000 } ) == 10 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'0000'0000'0000'1000'0000'0000 } ) == 11 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'0000'0000'0001'0000'0000'0000 } ) == 12 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'0000'0000'0010'0000'0000'0000 } ) == 13 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'0000'0000'0100'0000'0000'0000 } ) == 14 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'0000'0000'1000'0000'0000'0000 } ) == 15 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'0000'0001'0000'0000'0000'0000 } ) == 16 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'0000'0010'0000'0000'0000'0000 } ) == 17 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'0000'0100'0000'0000'0000'0000 } ) == 18 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'0000'1000'0000'0000'0000'0000 } ) == 19 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'0001'0000'0000'0000'0000'0000 } ) == 20 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'0010'0000'0000'0000'0000'0000 } ) == 21 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'0100'0000'0000'0000'0000'0000 } ) == 22 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'1000'0000'0000'0000'0000'0000 } ) == 23 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0001'0000'0000'0000'0000'0000'0000 } ) == 24 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0010'0000'0000'0000'0000'0000'0000 } ) == 25 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0100'0000'0000'0000'0000'0000'0000 } ) == 26 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'1000'0000'0000'0000'0000'0000'0000 } ) == 27 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0001'0000'0000'0000'0000'0000'0000'0000 } ) == 28 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0010'0000'0000'0000'0000'0000'0000'0000 } ) == 29 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0100'0000'0000'0000'0000'0000'0000'0000 } ) == 30 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b1000'0000'0000'0000'0000'0000'0000'0000 } ) == 31 );

				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint32_t{ 0b0000'0000'0000'0000'1111'1111'1111'1000 } ) ==  3 );
				}
			});

			BitScanTestSuite.AddTest( max::Testing::Test< max::Testing::CoutResultPolicy >{ "CountTrailingZeroesConstexpr( int32_t )", []( max::Testing::Test< max::Testing::CoutResultPolicy >& CurrentTest, max::Testing::CoutResultPolicy const& ResultPolicy ) {
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'0000'0000'0000'0000'0000'0001 } ) == 0  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'0000'0000'0000'0000'0000'0010 } ) == 1  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'0000'0000'0000'0000'0000'0100 } ) == 2  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'0000'0000'0000'0000'0000'1000 } ) == 3  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'0000'0000'0000'0000'0001'0000 } ) == 4  ); //-V112
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'0000'0000'0000'0000'0010'0000 } ) == 5  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'0000'0000'0000'0000'0100'0000 } ) == 6  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'0000'0000'0000'0000'1000'0000 } ) == 7  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'0000'0000'0000'0001'0000'0000 } ) == 8  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'0000'0000'0000'0010'0000'0000 } ) == 9  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'0000'0000'0000'0100'0000'0000 } ) == 10 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'0000'0000'0000'1000'0000'0000 } ) == 11 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'0000'0000'0001'0000'0000'0000 } ) == 12 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'0000'0000'0010'0000'0000'0000 } ) == 13 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'0000'0000'0100'0000'0000'0000 } ) == 14 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'0000'0000'1000'0000'0000'0000 } ) == 15 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'0000'0001'0000'0000'0000'0000 } ) == 16 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'0000'0010'0000'0000'0000'0000 } ) == 17 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'0000'0100'0000'0000'0000'0000 } ) == 18 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'0000'1000'0000'0000'0000'0000 } ) == 19 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'0001'0000'0000'0000'0000'0000 } ) == 20 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'0010'0000'0000'0000'0000'0000 } ) == 21 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'0100'0000'0000'0000'0000'0000 } ) == 22 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'1000'0000'0000'0000'0000'0000 } ) == 23 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0001'0000'0000'0000'0000'0000'0000 } ) == 24 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0010'0000'0000'0000'0000'0000'0000 } ) == 25 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0100'0000'0000'0000'0000'0000'0000 } ) == 26 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'1000'0000'0000'0000'0000'0000'0000 } ) == 27 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0001'0000'0000'0000'0000'0000'0000'0000 } ) == 28 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0010'0000'0000'0000'0000'0000'0000'0000 } ) == 29 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0100'0000'0000'0000'0000'0000'0000'0000 } ) == 30 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( static_cast< int32_t >( uint32_t{ 0b1000'0000'0000'0000'0000'0000'0000'0000 } ) ) == 31 );

				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int32_t{ 0b0000'0000'0000'0000'1111'1111'1111'1000 } ) == 3 );
				}
			});

			BitScanTestSuite.AddTest( max::Testing::Test< max::Testing::CoutResultPolicy >{ "CountTrailingZeroesConstexpr( uint16_t )", []( max::Testing::Test< max::Testing::CoutResultPolicy >& CurrentTest, max::Testing::CoutResultPolicy const& ResultPolicy ) {
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint16_t{ 0b0000'0000'0000'0001 } ) == 0  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint16_t{ 0b0000'0000'0000'0010 } ) == 1  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint16_t{ 0b0000'0000'0000'0100 } ) == 2  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint16_t{ 0b0000'0000'0000'1000 } ) == 3  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint16_t{ 0b0000'0000'0001'0000 } ) == 4  ); //-V112
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint16_t{ 0b0000'0000'0010'0000 } ) == 5  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint16_t{ 0b0000'0000'0100'0000 } ) == 6  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint16_t{ 0b0000'0000'1000'0000 } ) == 7  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint16_t{ 0b0000'0001'0000'0000 } ) == 8  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint16_t{ 0b0000'0010'0000'0000 } ) == 9  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint16_t{ 0b0000'0100'0000'0000 } ) == 10 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint16_t{ 0b0000'1000'0000'0000 } ) == 11 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint16_t{ 0b0001'0000'0000'0000 } ) == 12 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint16_t{ 0b0010'0000'0000'0000 } ) == 13 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint16_t{ 0b0100'0000'0000'0000 } ) == 14 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint16_t{ 0b1000'0000'0000'0000 } ) == 15 );

				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint16_t{ 0b1111'1111'1111'1000 } ) == 3 );
				}
			});

			BitScanTestSuite.AddTest( max::Testing::Test< max::Testing::CoutResultPolicy >{ "CountTrailingZeroesConstexpr( int16_t )", []( max::Testing::Test< max::Testing::CoutResultPolicy >& CurrentTest, max::Testing::CoutResultPolicy const& ResultPolicy ) {
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int16_t{ 0b0000'0000'0000'0001 } ) == 0  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int16_t{ 0b0000'0000'0000'0010 } ) == 1  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int16_t{ 0b0000'0000'0000'0100 } ) == 2  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int16_t{ 0b0000'0000'0000'1000 } ) == 3  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int16_t{ 0b0000'0000'0001'0000 } ) == 4  ); //-V112
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int16_t{ 0b0000'0000'0010'0000 } ) == 5  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int16_t{ 0b0000'0000'0100'0000 } ) == 6  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int16_t{ 0b0000'0000'1000'0000 } ) == 7  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int16_t{ 0b0000'0001'0000'0000 } ) == 8  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int16_t{ 0b0000'0010'0000'0000 } ) == 9  );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int16_t{ 0b0000'0100'0000'0000 } ) == 10 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int16_t{ 0b0000'1000'0000'0000 } ) == 11 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int16_t{ 0b0001'0000'0000'0000 } ) == 12 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int16_t{ 0b0010'0000'0000'0000 } ) == 13 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int16_t{ 0b0100'0000'0000'0000 } ) == 14 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( static_cast< int16_t >( uint16_t{ 0b1000'0000'0000'0000 } ) ) == 15 );

				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( static_cast< int16_t >( uint16_t{ 0b1111'1111'1111'1000 } ) ) == 3 );
				}
			});

			BitScanTestSuite.AddTest( max::Testing::Test< max::Testing::CoutResultPolicy >{ "CountTrailingZeroesConstexpr( uint8_t )", []( max::Testing::Test< max::Testing::CoutResultPolicy >& CurrentTest, max::Testing::CoutResultPolicy const& ResultPolicy ) {
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint8_t{ 0b0000'0001 } ) == 0 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint8_t{ 0b0000'0010 } ) == 1 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint8_t{ 0b0000'0100 } ) == 2 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint8_t{ 0b0000'1000 } ) == 3 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint8_t{ 0b0001'0000 } ) == 4 ); //-V112
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint8_t{ 0b0010'0000 } ) == 5 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint8_t{ 0b0100'0000 } ) == 6 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint8_t{ 0b1000'0000 } ) == 7 );

				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( uint8_t{ 0b1111'1000 } ) == 3 );
				}
			});

			BitScanTestSuite.AddTest( max::Testing::Test< max::Testing::CoutResultPolicy >{ "CountTrailingZeroesConstexpr( int8_t )", []( max::Testing::Test< max::Testing::CoutResultPolicy >& CurrentTest, max::Testing::CoutResultPolicy const& ResultPolicy ) {
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int8_t{ 0b0000'0001 } ) == 0 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int8_t{ 0b0000'0010 } ) == 1 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int8_t{ 0b0000'0100 } ) == 2 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int8_t{ 0b0000'1000 } ) == 3 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int8_t{ 0b0001'0000 } ) == 4 ); //-V112
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int8_t{ 0b0010'0000 } ) == 5 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( int8_t{ 0b0100'0000 } ) == 6 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( static_cast< int8_t >( uint8_t{ 0b1000'0000 } ) ) == 7 );

				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountTrailingZeroes( static_cast< int8_t >( uint8_t{ 0b1111'1000 } ) ) == 3 );
				}
			});


			BitScanTestSuite.AddTest( max::Testing::Test< max::Testing::CoutResultPolicy >{ "CountLeadingZeroesConstexpr( uint64_t )", []( max::Testing::Test< max::Testing::CoutResultPolicy >& CurrentTest, max::Testing::CoutResultPolicy const& ResultPolicy ) {
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001 } ) == 63 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010 } ) == 62 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100 } ) == 61 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000 } ) == 60 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000 } ) == 59 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000 } ) == 58 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000 } ) == 57 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000 } ) == 56 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000 } ) == 55 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000 } ) == 54 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000 } ) == 53 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000 } ) == 52 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000 } ) == 51 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000 } ) == 50 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000 } ) == 49 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000 } ) == 48 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000 } ) == 47 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000 } ) == 46 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000 } ) == 45 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000 } ) == 44 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000 } ) == 43 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000 } ) == 42 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000 } ) == 41 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000 } ) == 40 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000 } ) == 39 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000 } ) == 38 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000 } ) == 37 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000 } ) == 36 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000 } ) == 35 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000 } ) == 34 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000 } ) == 33 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000 } ) == 32 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 31 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 30 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 29 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 28 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 27 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 26 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 25 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 24 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 23 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 22 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 21 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 20 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 19 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 18 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 17 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 16 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 15 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 14 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 13 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 12 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 11 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 10 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  9 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  8 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  7 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  6 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  5 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  4 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  3 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  2 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  1 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  0 );

				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1111'1111'1100'0000 } ) == 48 );
				}
			});

			BitScanTestSuite.AddTest( max::Testing::Test< max::Testing::CoutResultPolicy >{ "CountLeadingZeroesConstexpr( int64_t )", []( max::Testing::Test< max::Testing::CoutResultPolicy >& CurrentTest, max::Testing::CoutResultPolicy const& ResultPolicy ) {
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001 } ) == 63 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010 } ) == 62 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100 } ) == 61 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000 } ) == 60 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000 } ) == 59 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000 } ) == 58 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000 } ) == 57 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000 } ) == 56 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000 } ) == 55 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000 } ) == 54 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000 } ) == 53 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000 } ) == 52 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000 } ) == 51 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000 } ) == 50 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000 } ) == 49 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000 } ) == 48 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000 } ) == 47 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000 } ) == 46 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000 } ) == 45 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000 } ) == 44 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000 } ) == 43 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000 } ) == 42 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000 } ) == 41 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000 } ) == 40 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000 } ) == 39 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000 } ) == 38 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000 } ) == 37 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000 } ) == 36 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000 } ) == 35 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000 } ) == 34 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000 } ) == 33 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000 } ) == 32 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 31 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 30 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 29 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 28 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 27 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 26 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 25 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 24 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 23 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 22 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 21 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 20 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 19 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 18 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 17 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 16 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 15 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 14 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 13 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 12 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 11 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) == 10 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  9 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  8 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  7 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  6 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  5 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  4 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  3 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  2 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ==  1 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( static_cast< int64_t >( uint64_t{ 0b1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 } ) ) == 0 );

				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int64_t{ 0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'1111'1111'1100'0000 } ) == 48 );

				}
			});


			BitScanTestSuite.AddTest( max::Testing::Test< max::Testing::CoutResultPolicy >{ "CountLeadingZeroesConstexpr( uint32_t )", []( max::Testing::Test< max::Testing::CoutResultPolicy >& CurrentTest, max::Testing::CoutResultPolicy const& ResultPolicy ) {
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0000'0001 } ) == 31 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0000'0010 } ) == 30 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0000'0100 } ) == 29 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0000'1000 } ) == 28 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0001'0000 } ) == 27 ); //-V112
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0010'0000 } ) == 26 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'0000'0000'0000'0000'0100'0000 } ) == 25 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'0000'0000'0000'0000'1000'0000 } ) == 24 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'0000'0000'0000'0001'0000'0000 } ) == 23 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'0000'0000'0000'0010'0000'0000 } ) == 22 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'0000'0000'0000'0100'0000'0000 } ) == 21 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'0000'0000'0000'1000'0000'0000 } ) == 20 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'0000'0000'0001'0000'0000'0000 } ) == 19 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'0000'0000'0010'0000'0000'0000 } ) == 18 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'0000'0000'0100'0000'0000'0000 } ) == 17 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'0000'0000'1000'0000'0000'0000 } ) == 16 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'0000'0001'0000'0000'0000'0000 } ) == 15 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'0000'0010'0000'0000'0000'0000 } ) == 14 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'0000'0100'0000'0000'0000'0000 } ) == 13 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'0000'1000'0000'0000'0000'0000 } ) == 12 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'0001'0000'0000'0000'0000'0000 } ) == 11 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'0010'0000'0000'0000'0000'0000 } ) == 10 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'0100'0000'0000'0000'0000'0000 } ) ==  9 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'1000'0000'0000'0000'0000'0000 } ) ==  8 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0001'0000'0000'0000'0000'0000'0000 } ) ==  7 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0010'0000'0000'0000'0000'0000'0000 } ) ==  6 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0100'0000'0000'0000'0000'0000'0000 } ) ==  5 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'1000'0000'0000'0000'0000'0000'0000 } ) ==  4 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0001'0000'0000'0000'0000'0000'0000'0000 } ) ==  3 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0010'0000'0000'0000'0000'0000'0000'0000 } ) ==  2 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0100'0000'0000'0000'0000'0000'0000'0000 } ) ==  1 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b1000'0000'0000'0000'0000'0000'0000'0000 } ) ==  0 );

				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint32_t{ 0b0000'0000'0000'0000'1111'1111'1111'1000 } ) == 16 );
				}
			});

			BitScanTestSuite.AddTest( max::Testing::Test< max::Testing::CoutResultPolicy >{ "CountLeadingZeroesConstexpr( int32_t )", []( max::Testing::Test< max::Testing::CoutResultPolicy >& CurrentTest, max::Testing::CoutResultPolicy const& ResultPolicy ) {
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'0000'0000'0000'0000'0000'0001 } ) == 31 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'0000'0000'0000'0000'0000'0010 } ) == 30 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'0000'0000'0000'0000'0000'0100 } ) == 29 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'0000'0000'0000'0000'0000'1000 } ) == 28 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'0000'0000'0000'0000'0001'0000 } ) == 27 ); //-V112
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'0000'0000'0000'0000'0010'0000 } ) == 26 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'0000'0000'0000'0000'0100'0000 } ) == 25 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'0000'0000'0000'0000'1000'0000 } ) == 24 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'0000'0000'0000'0001'0000'0000 } ) == 23 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'0000'0000'0000'0010'0000'0000 } ) == 22 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'0000'0000'0000'0100'0000'0000 } ) == 21 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'0000'0000'0000'1000'0000'0000 } ) == 20 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'0000'0000'0001'0000'0000'0000 } ) == 19 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'0000'0000'0010'0000'0000'0000 } ) == 18 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'0000'0000'0100'0000'0000'0000 } ) == 17 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'0000'0000'1000'0000'0000'0000 } ) == 16 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'0000'0001'0000'0000'0000'0000 } ) == 15 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'0000'0010'0000'0000'0000'0000 } ) == 14 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'0000'0100'0000'0000'0000'0000 } ) == 13 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'0000'1000'0000'0000'0000'0000 } ) == 12 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'0001'0000'0000'0000'0000'0000 } ) == 11 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'0010'0000'0000'0000'0000'0000 } ) == 10 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'0100'0000'0000'0000'0000'0000 } ) ==  9 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'1000'0000'0000'0000'0000'0000 } ) ==  8 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0001'0000'0000'0000'0000'0000'0000 } ) ==  7 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0010'0000'0000'0000'0000'0000'0000 } ) ==  6 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0100'0000'0000'0000'0000'0000'0000 } ) ==  5 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'1000'0000'0000'0000'0000'0000'0000 } ) ==  4 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0001'0000'0000'0000'0000'0000'0000'0000 } ) ==  3 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0010'0000'0000'0000'0000'0000'0000'0000 } ) ==  2 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0100'0000'0000'0000'0000'0000'0000'0000 } ) ==  1 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( static_cast< int32_t >( uint32_t{ 0b1000'0000'0000'0000'0000'0000'0000'0000 } ) ) == 0 );

				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int32_t{ 0b0000'0000'0000'0000'1111'1111'1111'1000 } ) == 16 );
				}
			});

			BitScanTestSuite.AddTest( max::Testing::Test< max::Testing::CoutResultPolicy >{ "CountLeadingZeroesConstexpr( uint16_t )", []( max::Testing::Test< max::Testing::CoutResultPolicy >& CurrentTest, max::Testing::CoutResultPolicy const& ResultPolicy ) {
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint16_t{ 0b0000'0000'0000'0001 } ) == 15 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint16_t{ 0b0000'0000'0000'0010 } ) == 14 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint16_t{ 0b0000'0000'0000'0100 } ) == 13 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint16_t{ 0b0000'0000'0000'1000 } ) == 12 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint16_t{ 0b0000'0000'0001'0000 } ) == 11 ); //-V112
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint16_t{ 0b0000'0000'0010'0000 } ) == 10 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint16_t{ 0b0000'0000'0100'0000 } ) ==  9 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint16_t{ 0b0000'0000'1000'0000 } ) ==  8 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint16_t{ 0b0000'0001'0000'0000 } ) ==  7 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint16_t{ 0b0000'0010'0000'0000 } ) ==  6 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint16_t{ 0b0000'0100'0000'0000 } ) ==  5 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint16_t{ 0b0000'1000'0000'0000 } ) ==  4 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint16_t{ 0b0001'0000'0000'0000 } ) ==  3 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint16_t{ 0b0010'0000'0000'0000 } ) ==  2 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint16_t{ 0b0100'0000'0000'0000 } ) ==  1 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint16_t{ 0b1000'0000'0000'0000 } ) ==  0 );

				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint16_t{ 0b0000'0000'1111'1000 } ) == 8 );
				}
			});

			BitScanTestSuite.AddTest( max::Testing::Test< max::Testing::CoutResultPolicy >{ "CountLeadingZeroesConstexpr( int16_t )", []( max::Testing::Test< max::Testing::CoutResultPolicy >& CurrentTest, max::Testing::CoutResultPolicy const& ResultPolicy ) {
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int16_t{ 0b0000'0000'0000'0001 } ) == 15 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int16_t{ 0b0000'0000'0000'0010 } ) == 14 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int16_t{ 0b0000'0000'0000'0100 } ) == 13 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int16_t{ 0b0000'0000'0000'1000 } ) == 12 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int16_t{ 0b0000'0000'0001'0000 } ) == 11 ); //-V112
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int16_t{ 0b0000'0000'0010'0000 } ) == 10 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int16_t{ 0b0000'0000'0100'0000 } ) ==  9 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int16_t{ 0b0000'0000'1000'0000 } ) ==  8 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int16_t{ 0b0000'0001'0000'0000 } ) ==  7 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int16_t{ 0b0000'0010'0000'0000 } ) ==  6 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int16_t{ 0b0000'0100'0000'0000 } ) ==  5 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int16_t{ 0b0000'1000'0000'0000 } ) ==  4 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int16_t{ 0b0001'0000'0000'0000 } ) ==  3 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int16_t{ 0b0010'0000'0000'0000 } ) ==  2 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int16_t{ 0b0100'0000'0000'0000 } ) ==  1 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( static_cast< int16_t >( uint16_t{ 0b1000'0000'0000'0000 } ) ) == 0 );

				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( static_cast< int16_t >( uint16_t{ 0b0000'0000'1111'1000 } ) ) == 8 );
				}
			});

			BitScanTestSuite.AddTest( max::Testing::Test< max::Testing::CoutResultPolicy >{ "CountLeadingZeroesConstexpr( uint8_t )", []( max::Testing::Test< max::Testing::CoutResultPolicy >& CurrentTest, max::Testing::CoutResultPolicy const& ResultPolicy ) {
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint8_t{ 0b0000'0001 } ) == 7 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint8_t{ 0b0000'0010 } ) == 6 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint8_t{ 0b0000'0100 } ) == 5 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint8_t{ 0b0000'1000 } ) == 4 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint8_t{ 0b0001'0000 } ) == 3 ); //-V112
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint8_t{ 0b0010'0000 } ) == 2 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint8_t{ 0b0100'0000 } ) == 1 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint8_t{ 0b1000'0000 } ) == 0 );

				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( uint8_t{ 0b0011'1000 } ) == 2 );
				}
			});

			BitScanTestSuite.AddTest( max::Testing::Test< max::Testing::CoutResultPolicy >{ "CountLeadingZeroesConstexpr( int8_t )", []( max::Testing::Test< max::Testing::CoutResultPolicy >& CurrentTest, max::Testing::CoutResultPolicy const& ResultPolicy ) {
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int8_t{ 0b0000'0001 } ) == 7 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int8_t{ 0b0000'0010 } ) == 6 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int8_t{ 0b0000'0100 } ) == 5 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int8_t{ 0b0000'1000 } ) == 4 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int8_t{ 0b0001'0000 } ) == 3 ); //-V112
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int8_t{ 0b0010'0000 } ) == 2 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( int8_t{ 0b0100'0000 } ) == 1 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( static_cast< int8_t >( uint8_t{ 0b1000'0000 } ) ) == 0 );

				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::CountLeadingZeroes( static_cast< int8_t >( uint8_t{ 0b0011'1000 } ) ) == 2 );
				}
			});

			BitScanTestSuite.RunTests();
		}

	} // namespace Algorithms
} // namespace maxAutomatedTests
