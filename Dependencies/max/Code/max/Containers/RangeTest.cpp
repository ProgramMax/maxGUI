// Copyright 2016, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "RangeTest.hpp"
#include <max/Containers/Range.hpp>
#include <max/Testing/TestSuite.hpp>
#include <max/Testing/CoutResultPolicy.hpp>
#include <utility>

namespace maxAutomatedTests
{
namespace Containers
{

	void RunRangeTestSuite()
	{
		static_assert( max::Containers::Range< int >{ 0, 1 }.Maximum == 1, "max::Containers::Range ctor should be constexpr" );

		max::Testing::CoutResultPolicy ResultPolicy;
		auto RangeTestSuite = max::Testing::TestSuite< max::Testing::CoutResultPolicy >{ "max::Containers::Range test suite", std::move( ResultPolicy ) };

		RangeTestSuite.AddTest( max::Testing::Test< max::Testing::CoutResultPolicy >{ "constructor sets minimum and maximum correctly", []( max::Testing::Test< max::Testing::CoutResultPolicy > & CurrentTest, max::Testing::CoutResultPolicy const & ResultPolicy ) {
			auto testRange = max::Containers::Range< int >{ 42, 100 };
			CurrentTest.MAX_TESTING_ASSERT( testRange.Minimum == 42  );
			CurrentTest.MAX_TESTING_ASSERT( testRange.Maximum == 100 );
		}
		} );

		RangeTestSuite.AddTest( max::Testing::Test< max::Testing::CoutResultPolicy >{ "constructor accepts same values", []( max::Testing::Test< max::Testing::CoutResultPolicy > & CurrentTest, max::Testing::CoutResultPolicy const & ResultPolicy ) {
			auto testRange = max::Containers::Range< int >{ 42, 42 };
			CurrentTest.MAX_TESTING_ASSERT( testRange.Minimum == 42 );
			CurrentTest.MAX_TESTING_ASSERT( testRange.Maximum == 42 );
		}
		} );

		RangeTestSuite.AddTest( max::Testing::Test< max::Testing::CoutResultPolicy >{ "MakeRange with minimum first", []( max::Testing::Test< max::Testing::CoutResultPolicy > & CurrentTest, max::Testing::CoutResultPolicy const & ResultPolicy ) {
			auto testRange = max::Containers::MakeRange( 1, 42 );
			CurrentTest.MAX_TESTING_ASSERT( testRange.Minimum == 1  );
			CurrentTest.MAX_TESTING_ASSERT( testRange.Maximum == 42 );
		}
		} );

		RangeTestSuite.AddTest( max::Testing::Test< max::Testing::CoutResultPolicy >{ "MakeRange with maximum first", []( max::Testing::Test< max::Testing::CoutResultPolicy > & CurrentTest, max::Testing::CoutResultPolicy const & ResultPolicy ) {
 			auto testRange = max::Containers::MakeRange( 100, 42 );
			CurrentTest.MAX_TESTING_ASSERT( testRange.Minimum == 42  );
			CurrentTest.MAX_TESTING_ASSERT( testRange.Maximum == 100 );
		}
		} );

		RangeTestSuite.RunTests();
	}

} // namespace Containers
} // namespace maxAutomatedTests
