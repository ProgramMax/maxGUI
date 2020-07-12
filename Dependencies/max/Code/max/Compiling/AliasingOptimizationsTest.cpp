// Copyright 2016, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "AliasingOptimizationsTest.hpp"
#include <max/Compiling/AliasingOptimizations.hpp>
#include <max/Testing/TestSuite.hpp>
#include <iostream>

namespace maxManualTests
{
namespace Compiling
{

	namespace {


		// In a pure function, we cannot dereference parameters.
		// However, we can still read the value of the pointer itself.
		bool UnpureFunction( int * Address1, int * Address2 )
		{
			return Address1 == Address2;
		}

		MAX_PURE_DEFINITION( bool PureFunction( int * Address1, int * Address2 ) )
		{
			return Address1 == Address2;
		}


		// In a pure-with-globals function, we cannot dereference parameters.
		// But in this case we can access globals as well.
		static int Global = 5;

		bool UnpureWithGlobals( int * Address1, int * Address2 )
		{
			return Address1 == Address2 && Global == 0;
		}

		MAX_PURE_WITH_GLOBALS_DEFINITION( bool PureWithGlobals( int * Address1, int * Address2 ) ) //-V524
		{
			return Address1 == Address2 && Global == 0;
		}


		// In a semipure function, we can follow first-level indirections
		// but not second-level indirections.
		struct Address
		{
			explicit Address( int * Addr )
				: Address_( Addr )
			{
			}

			bool operator ==( const Address& rhs ) const
			{
				return Address_ == rhs.Address_;
			}

			int * Address_ = nullptr;
		};

		struct AddressesHolder
		{
			explicit AddressesHolder( int * Address1, int * Address2 )
				: Address1( Address1 )
				, Address2( Address2 )
			{
			}

			Address Address1;
			Address Address2;
		};

		bool NotSemipure( AddressesHolder * Addresses )
		{
			return Addresses->Address1.Address_ == Addresses->Address2.Address_ && Global == 0;
		}

		MAX_SEMI_PURE_DEFINITION( bool Semipure( AddressesHolder * Addresses ) )
		{
			return Addresses->Address1 == Addresses->Address2;
		}


		// A restricted pointer parameter does not overlap any other pointed-to memory.
		bool NotRestrictedPointerParameter( int * Address1, int * Address2 )
		{
			return Address1 == Address2;
		}

		bool RestrictedPointerParameter( MAX_RESTRICTED_POINTER( int * ) Address1, MAX_RESTRICTED_POINTER( int * ) Address2 )
		{
			return Address1 == Address2;
		}

	} // anonymous namespace

/*
* [MAX_RESTRICTED_POINTER](MAX_RESTRICTED_POINTER.md)
* [MAX_RESTRICTED_REFERENCE](MAX_RESTRICTED_REFERENCE.md)
* [MAX_RETURNS_RESTRICTED_POINTER](MAX_RETURNS_RESTRICTED_POINTER.md)
*/


	void RunAliasingOptimizationsTestSuite()
	{
		int * Address1 = new int( 5 );
		int * Address2 = new int( 6 );

		bool Repeated = false;
		char Overlap = 'a';
		while (Overlap != 'y' && Overlap != 'Y' && Overlap != 'n' && Overlap != 'N')
		{
			if (Repeated)
				std::cout << "Invalid input. You must enter y or n\n";

			std::cout << "Should the addresses overlap? (y/n)" << std::endl;
			std::cin >> Overlap;
			if( Overlap == 'y' || Overlap == 'Y')
			{
				delete Address2;
				Address2 = Address1;
			}
			Repeated = true;
		}

		std::cout << UnpureFunction( Address1, Address2 ) << '\n';
		std::cout << PureFunction(   Address1, Address2 ) << '\n';

		std::cout << "Enter a value to go in the global variable\n";
		std::cin >> Global;

		std::cout << UnpureWithGlobals( Address1, Address2 ) << '\n';
		std::cout << PureWithGlobals(   Address1, Address2 ) << '\n';

		AddressesHolder AddressPair( Address1, Address2 );
		std::cout << NotSemipure( & AddressPair ) << '\n';
		std::cout << Semipure( & AddressPair ) << '\n';

		std::cout << NotRestrictedPointerParameter( Address1, Address2 ) << '\n';
		std::cout << RestrictedPointerParameter( Address1, Address2 ) << '\n';

		delete Address1;
		if( Overlap != 'y' && Overlap != 'Y')
		{
			delete Address2;
		}
	}

} // namespace Compiling
} // namespace maxManualTests
