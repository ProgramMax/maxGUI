// Copyright 2016, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "IsBetweenTest.hpp"
#include <max/Algorithms/IsBetween.hpp>
#include <max/Testing/TestSuite.hpp>
#include <max/Testing/CoutResultPolicy.hpp>
#include <utility>

namespace maxAutomatedTests
{
namespace Algorithms
{

	void RunIsBetweenTestSuite()
	{
		max::Testing::CoutResultPolicy ResultPolicy;
		auto IsBetweenTestSuite = max::Testing::TestSuite< max::Testing::CoutResultPolicy >{ "max::Algorithms::IsBetween test suite", std::move( ResultPolicy ) };
		
		IsBetweenTestSuite.AddTest( max::Testing::Test< max::Testing::CoutResultPolicy >{ "inside range", []( max::Testing::Test< max::Testing::CoutResultPolicy > & CurrentTest, max::Testing::CoutResultPolicy const & ResultPolicy ) {
			CurrentTest.MAX_TESTING_ASSERT( max::Algorithms::IsBetween( 10, { 1, 100 } ) );
		}
		} );

		IsBetweenTestSuite.AddTest( max::Testing::Test< max::Testing::CoutResultPolicy >{ "before range", []( max::Testing::Test< max::Testing::CoutResultPolicy > & CurrentTest, max::Testing::CoutResultPolicy const & ResultPolicy ) {
			CurrentTest.MAX_TESTING_ASSERT( ! max::Algorithms::IsBetween( 0, { 1, 100 } ) );
		}
		} );

		IsBetweenTestSuite.AddTest( max::Testing::Test< max::Testing::CoutResultPolicy >{ "after range", []( max::Testing::Test< max::Testing::CoutResultPolicy > & CurrentTest, max::Testing::CoutResultPolicy const & ResultPolicy ) {
			CurrentTest.MAX_TESTING_ASSERT( ! max::Algorithms::IsBetween( 200, { 1, 100 } ) );
		}
		} );

		IsBetweenTestSuite.AddTest( max::Testing::Test< max::Testing::CoutResultPolicy >{ "minimum and maximum switched", []( max::Testing::Test< max::Testing::CoutResultPolicy > & CurrentTest, max::Testing::CoutResultPolicy const & ResultPolicy ) {
			CurrentTest.MAX_TESTING_ASSERT( ! max::Algorithms::IsBetween( 10, { 100, 1 } ) );
		}
		} );

		IsBetweenTestSuite.RunTests();
	}

} // namespace Algorithms
} // namespace maxAutomatedTests
