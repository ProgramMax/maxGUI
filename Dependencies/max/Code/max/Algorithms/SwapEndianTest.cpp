// Copyright 2020, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "SwapEndianTest.hpp"
#include <max/Algorithms/SwapEndian.hpp>
#include <max/Testing/TestSuite.hpp>
#include <max/Testing/CoutResultPolicy.hpp>
#include <utility>

namespace maxAutomatedTests
{
	namespace Algorithms
	{

		void RunSwapEndianTestSuite()
		{
			static_assert( max::Algorithms::SwapEndianConstexpr( uint64_t{ 0x1234567890abcdef } ) == uint64_t{ 0xefcdab9078563412 }, "max::Algorithms::SwapEndianConstexpr( uint64_t ) isn't swapping endian correctly." );
			static_assert( max::Algorithms::SwapEndianConstexpr( uint32_t{ 0x12345678         } ) == uint32_t{ 0x78563412         }, "max::Algorithms::SwapEndianConstexpr( uint32_t ) isn't swapping endian correctly." );
			static_assert( max::Algorithms::SwapEndianConstexpr( uint16_t{ 0x1234             } ) == uint16_t{ 0x3412             }, "max::Algorithms::SwapEndianConstexpr( uint16_t ) isn't swapping endian correctly." );
			static_assert( max::Algorithms::SwapEndianConstexpr(  int64_t{ 0x1234567890abcd00 } ) ==  int64_t{ 0x00cdab9078563412 }, "max::Algorithms::SwapEndianConstexpr( int64_t ) isn't swapping endian correctly."  );
			static_assert( max::Algorithms::SwapEndianConstexpr(  int32_t{ 0x12345678         } ) ==  int32_t{ 0x78563412         }, "max::Algorithms::SwapEndianConstexpr( int32_t ) isn't swapping endian correctly."  );
			static_assert( max::Algorithms::SwapEndianConstexpr(  int16_t{ 0x1234             } ) ==  int16_t{ 0x3412             }, "max::Algorithms::SwapEndianConstexpr( int16_t ) isn't swapping endian correctly."  );

			max::Testing::CoutResultPolicy ResultPolicy;
			auto SwapEndianTestSuite = max::Testing::TestSuite< max::Testing::CoutResultPolicy >{ "max::Algorithms::SwapEndian test suite", std::move( ResultPolicy ) };

			SwapEndianTestSuite.AddTest(max::Testing::Test< max::Testing::CoutResultPolicy >{ "SwapEndian", []( max::Testing::Test< max::Testing::CoutResultPolicy >& CurrentTest, max::Testing::CoutResultPolicy const& ResultPolicy ) {
				uint64_t Unsigned64BitValue = UINT64_C( 0x1234567890abcdef );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::SwapEndian( Unsigned64BitValue ) == uint64_t{ 0xefcdab9078563412 } );

				uint32_t Unsigned32BitValue = UINT32_C( 0x12345678 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::SwapEndian( Unsigned32BitValue ) == uint32_t{ 0x78563412 } );

				uint16_t Unsigned16BitValue = UINT16_C( 0x1234 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::SwapEndian( Unsigned16BitValue ) == uint16_t{ 0x3412 } );

				int64_t Signed64BitValue = INT64_C( 0x1234567890abcdef );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::SwapEndian( Signed64BitValue ) == static_cast< int64_t >( 0xefcdab9078563412 ) );

				int32_t Signed32BitValue = INT32_C( 0x12345678 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::SwapEndian( Signed32BitValue ) == int32_t{ 0x78563412 } );

				int16_t Signed16BitValue = UINT16_C( 0x1234 );
				CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::SwapEndian( Signed16BitValue ) == int16_t{ 0x3412 } );
				}
			});

			// TODO: Add LittleEndianToHost test
			// TODO: Add BigEndianToHost test
			// TODO: Add HostToLittleEndian test
			// TODO: Add HostToBigEndian test
			// TODO: Add CombinePieces test

			SwapEndianTestSuite.RunTests();
		}

	} // namespace Algorithms
} // namespace maxAutomatedTests
