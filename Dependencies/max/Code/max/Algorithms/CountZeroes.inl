// Copyright 2015, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <max/Compiling/Configuration.hpp>
#include <max/Compiling/Polyfills/IsConstantEvaluated.hpp>
#include <max/Compiling/Assume.hpp>


#if defined( MAX_COMPILER_VC )
#include <stdlib.h>
#include <intrin.h>
#endif
#include <iostream>

namespace max
{
	namespace v0
	{
		namespace Algorithms
		{

			namespace ImplementationDetails
			{

				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit0(  const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit1(  const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit2(  const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit3(  const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit4(  const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit5(  const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit6(  const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit7(  const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit8(  const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit9(  const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit10( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit11( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit12( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit13( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit14( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit15( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit16( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit17( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit18( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit19( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit20( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit21( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit22( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit23( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit24( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit25( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit26( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit27( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit28( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit29( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit30( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit31( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit32( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit33( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit34( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit35( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit36( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit37( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit38( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit39( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit40( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit41( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit42( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit43( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit44( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit45( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit46( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit47( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit48( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit49( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit50( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit51( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit52( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit53( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit54( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit55( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit56( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit57( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit58( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit59( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit60( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit61( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit62( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit63( const uint64_t Mask ) noexcept );

				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit0(  const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit1(  const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit2(  const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit3(  const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit4(  const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit5(  const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit6(  const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit7(  const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit8(  const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit9(  const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit10( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit11( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit12( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit13( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit14( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit15( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit16( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit17( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit18( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit19( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit20( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit21( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit22( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit23( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit24( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit25( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit26( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit27( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit28( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit29( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit30( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit31( const uint32_t Mask ) noexcept );

				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit0(  const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit1(  const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit2(  const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit3(  const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit4(  const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit5(  const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit6(  const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit7(  const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit8(  const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit9(  const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit10( const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit11( const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit12( const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit13( const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit14( const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit15( const uint16_t Mask ) noexcept );

				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit0( const uint8_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit1( const uint8_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit2( const uint8_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit3( const uint8_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit4( const uint8_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit5( const uint8_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit6( const uint8_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit7( const uint8_t Mask ) noexcept );


				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit0(  const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit1(  const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit2(  const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit3(  const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit4(  const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit5(  const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit6(  const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit7(  const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit8(  const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit9(  const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit10( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit11( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit12( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit13( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit14( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit15( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit16( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit17( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit18( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit19( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit20( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit21( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit22( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit23( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit24( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit25( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit26( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit27( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit28( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit29( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit30( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit31( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit32( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit33( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit34( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit35( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit36( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit37( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit38( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit39( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit40( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit41( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit42( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit43( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit44( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit45( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit46( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit47( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit48( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit49( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit50( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit51( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit52( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit53( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit54( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit55( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit56( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit57( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit58( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit59( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit60( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit61( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit62( const uint64_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit63( const uint64_t Mask ) noexcept );

				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit0(  const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit1(  const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit2(  const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit3(  const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit4(  const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit5(  const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit6(  const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit7(  const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit8(  const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit9(  const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit10( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit11( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit12( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit13( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit14( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit15( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit16( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit17( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit18( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit19( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit20( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit21( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit22( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit23( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit24( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit25( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit26( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit27( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit28( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit29( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit30( const uint32_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit31( const uint32_t Mask ) noexcept );

				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit0(  const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit1(  const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit2(  const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit3(  const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit4(  const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit5(  const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit6(  const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit7(  const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit8(  const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit9(  const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit10( const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit11( const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit12( const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit13( const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit14( const uint16_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit15( const uint16_t Mask ) noexcept );

				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit0( const uint8_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit1( const uint8_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit2( const uint8_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit3( const uint8_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit4( const uint8_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit5( const uint8_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit6( const uint8_t Mask ) noexcept );
				MAX_PURE_DECLARATION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit7( const uint8_t Mask ) noexcept );

			} // namespace ImplementationDetails

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEXPR inline uint64_t CountTrailingZeroes( const uint64_t Value ) noexcept )
			{
				if( max::Compiling::Polyfills::IsConstantEvaluated() )
				{
					return CountTrailingZeroesCompileTime( Value );
				} else {
					#if defined( MAX_COMPILER_CLANG ) || defined( MAX_COMPILER_GCC )
						return static_cast< uint64_t >( __builtin_ctzll( Value ) );
					#elif defined( MAX_COMPILER_VC ) && defined( MAX_X86_64 )
						unsigned long Position = 0;
						_BitScanForward64( &Position, Value );
						return Position;
					#else
						return ImplementationDetails::CheckTrailingBit0( Value );
					#endif
				}
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEXPR inline uint32_t CountTrailingZeroes( const uint32_t Value ) noexcept )
			{
				if( max::Compiling::Polyfills::IsConstantEvaluated() )
				{
					return CountTrailingZeroesCompileTime( Value );
				} else {
					#if defined( MAX_COMPILER_CLANG ) || defined( MAX_COMPILER_GCC )
						return static_cast< uint32_t >( __builtin_ctz( Value ) );
					#elif defined( MAX_COMPILER_VC )
						unsigned long Position = 0;
						_BitScanForward( &Position, Value );
						return Position;
					#else
						return ImplementationDetails::ChecTrailingkBit0( Value );
					#endif
				}
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEXPR inline uint16_t CountTrailingZeroes( const uint16_t Value ) noexcept )
			{
				if( max::Compiling::Polyfills::IsConstantEvaluated() )
				{
					return CountTrailingZeroesCompileTime( Value );
				} else {
					#if defined( MAX_COMPILER_CLANG ) || defined( MAX_COMPILER_GCC )
						return static_cast< uint16_t >( __builtin_ctz( Value ) );
					#elif defined( MAX_COMPILER_VC )
						unsigned long Position = 0;
						_BitScanForward( &Position, static_cast< unsigned long >( Value ) );
						return static_cast< uint16_t >( Position );
					#else
						return ImplementationDetails::CheckTrailingBit0( Value );
					#endif
				}
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEXPR inline uint8_t CountTrailingZeroes( const uint8_t Value ) noexcept )
			{
				if( max::Compiling::Polyfills::IsConstantEvaluated() )
				{
					return CountTrailingZeroesCompileTime( Value );
				} else {
					#if defined( MAX_COMPILER_CLANG ) || defined( MAX_COMPILER_GCC )
						return static_cast< uint8_t >( __builtin_ctz( Value ) );
					#elif defined( MAX_COMPILER_VC )
						unsigned long Position = 0;
						_BitScanForward( &Position, static_cast< unsigned long >( Value ) );
							return static_cast< uint8_t >( Position );
					#else
						return ImplementationDetails::CheckTrailingBit0( Value );
					#endif
				}
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEXPR inline int64_t CountTrailingZeroes( const int64_t Value ) noexcept )
			{
				if( max::Compiling::Polyfills::IsConstantEvaluated() )
				{
					return CountTrailingZeroesCompileTime( Value );
				} else {
					#if defined( MAX_COMPILER_CLANG ) || defined( MAX_COMPILER_GCC )
						return __builtin_ctzll( static_cast< uint64_t >( Value ) );
					#elif defined( MAX_COMPILER_VC ) && defined( MAX_X86_64 )
						unsigned long Position = 0;
						_BitScanForward64( &Position, static_cast< uint64_t >( Value ) );
						return Position;
					#else
						return ImplementationDetails::CheckTrailingBit0( static_cast< const uint64_t >( Value ) );
					#endif
				}
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEXPR inline int32_t CountTrailingZeroes( const int32_t Value ) noexcept )
			{
				if( max::Compiling::Polyfills::IsConstantEvaluated() )
				{
					return CountTrailingZeroesCompileTime( Value );
				} else {
					#if defined( MAX_COMPILER_CLANG ) || defined( MAX_COMPILER_GCC )
						return __builtin_ctz( static_cast< uint32_t >( Value ) );
					#elif defined( MAX_COMPILER_VC )
						unsigned long Position = 0;
						_BitScanForward( &Position, static_cast< unsigned long >( Value ) );
						return Position;
					#else
						return ImplementationDetails::CheckTrailingBit0( static_cast< const uint32_t >( Value ) );
					#endif
				}
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEXPR inline int16_t CountTrailingZeroes( const int16_t Value ) noexcept )
			{
				if( max::Compiling::Polyfills::IsConstantEvaluated() )
				{
					return CountTrailingZeroesCompileTime( Value );
				} else {
					#if defined( MAX_COMPILER_CLANG ) || defined( MAX_COMPILER_GCC )
						return static_cast< int16_t >( __builtin_ctz( static_cast< uint16_t >( Value ) ) );
					#elif defined( MAX_COMPILER_VC )
						unsigned long Position = 0;
						_BitScanForward( &Position, static_cast< unsigned long >( Value ) );
						return static_cast< int16_t >( Position );
					#else
						return ImplementationDetails::CheckTrailingBit0( static_cast< const uint16_t >( Value ) );
					#endif
				}
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEXPR inline int8_t CountTrailingZeroes( const int8_t Value ) noexcept )
			{
				if( max::Compiling::Polyfills::IsConstantEvaluated() )
				{
					return CountTrailingZeroesCompileTime( Value );
				} else {
					#if defined( MAX_COMPILER_CLANG ) || defined( MAX_COMPILER_GCC )
						return static_cast< int8_t >( __builtin_ctz( static_cast< uint8_t >( Value ) ) );
					#elif defined( MAX_COMPILER_VC )
						unsigned long Position = 0;
						_BitScanForward( &Position, static_cast< unsigned long >( Value ) );
						return static_cast< int8_t >( Position );
					#else
						return ImplementationDetails::CheckTrailingBit0( static_cast< const uint8_t >( Value ) );
					#endif
				}
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEXPR inline uint64_t CountLeadingZeroes( const uint64_t Value ) noexcept )
			{
				if( max::Compiling::Polyfills::IsConstantEvaluated() )
				{
					return CountLeadingZeroesCompileTime( Value );
				} else {
					#if defined( MAX_COMPILER_CLANG ) || defined( MAX_COMPILER_GCC )
						return static_cast< uint64_t >( __builtin_clzll( Value ) );
					#elif defined( MAX_COMPILER_VC ) && defined( MAX_X86_64 )
						unsigned long Position = 0;
						_BitScanReverse64( &Position, Value );
						MAX_ASSUME( Position <= 63 );
						return  63 - static_cast< uint64_t >( Position );
					#else
						return ImplementationDetails::CheckLeadingBit63( Value );
					#endif
				}
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEXPR inline uint32_t CountLeadingZeroes( const uint32_t Value ) noexcept )
			{
				if( max::Compiling::Polyfills::IsConstantEvaluated() )
				{
					return CountLeadingZeroesCompileTime( Value );
				} else {
					#if defined( MAX_COMPILER_CLANG ) || defined( MAX_COMPILER_GCC )
						return static_cast< uint32_t >( __builtin_clz( Value ) );
					#elif defined( MAX_COMPILER_VC )
						unsigned long Position = 0;
						_BitScanReverse( &Position, Value );
						MAX_ASSUME( Position <= 31 );
						return 31 - Position;
					#else
						return ImplementationDetails::CheckLeadingBit31( Value );
					#endif
				}
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEXPR inline uint16_t CountLeadingZeroes( const uint16_t Value ) noexcept )
			{
				if( max::Compiling::Polyfills::IsConstantEvaluated() )
				{
					return CountLeadingZeroesCompileTime( Value );
				} else {
					#if defined( MAX_COMPILER_CLANG ) || defined( MAX_COMPILER_GCC )
						return static_cast< uint16_t >( __builtin_clz( Value ) - 16 );
					#elif defined( MAX_COMPILER_VC )
						unsigned long Position = 0;
						_BitScanReverse( &Position, static_cast< unsigned long >( Value ) );
						MAX_ASSUME( Position <= 15 );
						return 15 - static_cast< uint16_t >( Position );
					#else
						return ImplementationDetails::CheckLeadingBit15( Value );
					#endif
				}
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEXPR inline uint8_t CountLeadingZeroes( const uint8_t Value ) noexcept )
			{
				if( max::Compiling::Polyfills::IsConstantEvaluated() )
				{
					return CountLeadingZeroesCompileTime( Value );
				} else {
					#if defined( MAX_COMPILER_CLANG ) || defined( MAX_COMPILER_GCC )
						return static_cast< uint8_t >( __builtin_clz( Value ) - 24 );
					#elif defined( MAX_COMPILER_VC )
						unsigned long Position = 0;
						_BitScanReverse( &Position, static_cast< unsigned long >( Value ) );
						MAX_ASSUME( Position <= 7 );
						return 7 - static_cast< uint8_t >( Position );
					#else
						return ImplementationDetails::CheckLeadingBit7( Value );
					#endif
				}
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEXPR inline int64_t CountLeadingZeroes( const int64_t Value ) noexcept )
			{
				if( max::Compiling::Polyfills::IsConstantEvaluated() )
				{
					return CountLeadingZeroesCompileTime( Value );
				} else {
					#if defined( MAX_COMPILER_CLANG ) || defined( MAX_COMPILER_GCC )
						return __builtin_clzll( static_cast< uint64_t >( Value ) );
					#elif defined( MAX_COMPILER_VC ) && defined( MAX_X86_64 )
						unsigned long Position = 0;
						_BitScanReverse64( &Position, static_cast< uint64_t >( Value ) );
						MAX_ASSUME( Position < 64 );
						return 63 - static_cast< int64_t >( Position );
					#else
						return ImplementationDetails::CheckLeadingBit63( static_cast< const uint64_t >( Value ) );
					#endif
			}
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEXPR inline int32_t CountLeadingZeroes( const int32_t Value ) noexcept )
			{
				if( max::Compiling::Polyfills::IsConstantEvaluated() )
				{
					return CountLeadingZeroesCompileTime( Value );
				} else {
					#if defined( MAX_COMPILER_CLANG ) || defined( MAX_COMPILER_GCC )
						return __builtin_clz( static_cast< uint32_t >( Value ) );
					#elif defined( MAX_COMPILER_VC )
						unsigned long Position = 0;
						_BitScanReverse( &Position, static_cast< unsigned long >( Value ) );
						MAX_ASSUME( Position <= 31 );
						return 31 - Position;
					#else
						return ImplementationDetails::CheckLeadingBit31( static_cast< const uint32_t >( Value ) );
					#endif
				}
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEXPR inline int16_t CountLeadingZeroes( const int16_t Value ) noexcept )
			{
				if( max::Compiling::Polyfills::IsConstantEvaluated() )
				{
					return CountLeadingZeroesCompileTime( Value );
				} else {
					#if defined( MAX_COMPILER_CLANG ) || defined( MAX_COMPILER_GCC )
						return static_cast< int16_t >( __builtin_clz( static_cast< uint16_t >( Value ) ) - 16 );
					#elif defined( MAX_COMPILER_VC )
						unsigned long Position = 0;
						_BitScanReverse( &Position, static_cast< uint16_t >( Value ) );
						MAX_ASSUME( Position <= 15 );
						return 15 - static_cast< int16_t >( Position );
					#else
						return ImplementationDetails::CheckLeadingBit15( static_cast< const uint16_t >( Value ) );
					#endif
				}
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEXPR inline int8_t CountLeadingZeroes( const int8_t Value ) noexcept )
			{
				if( max::Compiling::Polyfills::IsConstantEvaluated() )
				{
					return CountLeadingZeroesCompileTime( Value );
				} else {
					#if defined( MAX_COMPILER_CLANG ) || defined( MAX_COMPILER_GCC )
						return static_cast< int8_t >( __builtin_clz( static_cast< uint8_t >( Value ) ) - 24 );
					#elif defined( MAX_COMPILER_VC )
						unsigned long Position = 0;
						_BitScanReverse( &Position, static_cast< uint8_t >( Value ) );
						MAX_ASSUME( Position <= 7 );
						return 7 - static_cast< int8_t >( Position );
					#else
						return ImplementationDetails::CheckLeadingBit7( static_cast< const uint8_t >( Value ) );
					#endif
				}
			}

			// These functions will continue a call chain until all bits are checked.
			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint64_t CountTrailingZeroesCompileTime( const uint64_t Value ) noexcept )
			{
				return ImplementationDetails::CheckTrailingBit0( Value );
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint32_t CountTrailingZeroesCompileTime( const uint32_t Value ) noexcept )
			{
				return ImplementationDetails::CheckTrailingBit0( Value );
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint16_t CountTrailingZeroesCompileTime( const uint16_t Value ) noexcept )
			{
				return ImplementationDetails::CheckTrailingBit0( Value );
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CountTrailingZeroesCompileTime( const uint8_t Value ) noexcept )
			{
				return ImplementationDetails::CheckTrailingBit0( Value );
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline int64_t CountTrailingZeroesCompileTime( const int64_t Value ) noexcept )
			{
				return ImplementationDetails::CheckTrailingBit0( static_cast< uint64_t >( Value ) );
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline int32_t CountTrailingZeroesCompileTime( const int32_t Value ) noexcept )
			{
				return ImplementationDetails::CheckTrailingBit0( static_cast< uint32_t >( Value ) );
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline int16_t CountTrailingZeroesCompileTime( const int16_t Value ) noexcept )
			{
				return ImplementationDetails::CheckTrailingBit0( static_cast< uint16_t >( Value ) );
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline int8_t CountTrailingZeroesCompileTime( const int8_t Value ) noexcept )
			{
				return static_cast< int8_t >( ImplementationDetails::CheckTrailingBit0( static_cast< uint8_t >( Value ) ) );
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint64_t CountLeadingZeroesCompileTime( const uint64_t Value ) noexcept )
			{
				return ImplementationDetails::CheckLeadingBit63( Value );
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint32_t CountLeadingZeroesCompileTime( const uint32_t Value ) noexcept )
			{
				return ImplementationDetails::CheckLeadingBit31( Value );
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint16_t CountLeadingZeroesCompileTime( const uint16_t Value ) noexcept )
			{
				return ImplementationDetails::CheckLeadingBit15( Value );
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CountLeadingZeroesCompileTime( const uint8_t Value ) noexcept )
			{
				return ImplementationDetails::CheckLeadingBit7( Value );
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline int64_t CountLeadingZeroesCompileTime( const int64_t Value ) noexcept )
			{
				return ImplementationDetails::CheckLeadingBit63( static_cast< uint64_t >( Value ) );
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline int32_t CountLeadingZeroesCompileTime( const int32_t Value ) noexcept )
			{
				return ImplementationDetails::CheckLeadingBit31( static_cast< uint32_t >( Value ) );
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline int16_t CountLeadingZeroesCompileTime( const int16_t Value ) noexcept )
			{
				return ImplementationDetails::CheckLeadingBit15( static_cast< uint16_t >( Value ) );
			}

			MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline int8_t CountLeadingZeroesCompileTime( const int8_t Value ) noexcept )
			{
				return static_cast< int8_t >( ImplementationDetails::CheckLeadingBit7( static_cast< uint8_t >( Value ) ) );
			}

			namespace ImplementationDetails
			{

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit0( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1 ) ? 0 : CheckTrailingBit1( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit1( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10 ) ? 1 : CheckTrailingBit2( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit2( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100 ) ? 2 : CheckTrailingBit3( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit3( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000 ) ? 3 : CheckTrailingBit4( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit4( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000 ) ? 4 : CheckTrailingBit5( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit5( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000 ) ? 5 : CheckTrailingBit6( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit6( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000 ) ? 6 : CheckTrailingBit7( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit7( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000 ) ? 7 : CheckTrailingBit8( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit8( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000 ) ? 8 : CheckTrailingBit9( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit9( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000 ) ? 9 : CheckTrailingBit10( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit10( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000 ) ? 10 : CheckTrailingBit11( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit11( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000 ) ? 11 : CheckTrailingBit12( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit12( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000 ) ? 12 : CheckTrailingBit13( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit13( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000 ) ? 13 : CheckTrailingBit14( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit14( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000 ) ? 14 : CheckTrailingBit15( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit15( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000 ) ? 15 : CheckTrailingBit16( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit16( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000 ) ? 16 : CheckTrailingBit17( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit17( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000 ) ? 17 : CheckTrailingBit18( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit18( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000 ) ? 18 : CheckTrailingBit19( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit19( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000 ) ? 19 : CheckTrailingBit20( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit20( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000 ) ? 20 : CheckTrailingBit21( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit21( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000 ) ? 21 : CheckTrailingBit22( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit22( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000 ) ? 22 : CheckTrailingBit23( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit23( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000 ) ? 23 : CheckTrailingBit24( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit24( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000'0000 ) ? 24 : CheckTrailingBit25( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit25( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000'0000 ) ? 25 : CheckTrailingBit26( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit26( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000'0000 ) ? 26 : CheckTrailingBit27( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit27( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000'0000 ) ? 27 : CheckTrailingBit28( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit28( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000'0000'0000 ) ? 28 : CheckTrailingBit29( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit29( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000'0000'0000 ) ? 29 : CheckTrailingBit30( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit30( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000'0000'0000 ) ? 30 : CheckTrailingBit31( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit31( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000'0000'0000 ) ? 31 : CheckTrailingBit32( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit32( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 32 : CheckTrailingBit33( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit33( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 33 : CheckTrailingBit34( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit34( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 34 : CheckTrailingBit35( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit35( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 35 : CheckTrailingBit36( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit36( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 36 : CheckTrailingBit37( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit37( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 37 : CheckTrailingBit38( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit38( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 38 : CheckTrailingBit39( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit39( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 39 : CheckTrailingBit40( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit40( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 40 : CheckTrailingBit41( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit41( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 41 : CheckTrailingBit42( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit42( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 42 : CheckTrailingBit43( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit43( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 43 : CheckTrailingBit44( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit44( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 44 : CheckTrailingBit45( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit45( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 45 : CheckTrailingBit46( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit46( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 46 : CheckTrailingBit47( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit47( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 47 : CheckTrailingBit48( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit48( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 48 : CheckTrailingBit49( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit49( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 49 : CheckTrailingBit50( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit50( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 50 : CheckTrailingBit51( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit51( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 51 : CheckTrailingBit52( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit52( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 52 : CheckTrailingBit53( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit53( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 53 : CheckTrailingBit54( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit54( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 54 : CheckTrailingBit55( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit55( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 55 : CheckTrailingBit56( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit56( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 56 : CheckTrailingBit57( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit57( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 57 : CheckTrailingBit58( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit58( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 58 : CheckTrailingBit59( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit59( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 59 : CheckTrailingBit60( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit60( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 60 : CheckTrailingBit61( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit61( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 61 : CheckTrailingBit62( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit62( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 62 : CheckTrailingBit63( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit63( const uint64_t /* Mask */ ) noexcept )
				{
					// If we got here, this bit must be set.
					// (Behavior is undefined if no bits are set.)
					return 63;
				}


				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit0( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1 ) ? 0 : CheckTrailingBit1( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit1( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b10 ) ? 1 : CheckTrailingBit2( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit2( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b100 ) ? 2 : CheckTrailingBit3( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit3( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1000 ) ? 3 : CheckTrailingBit4( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit4( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000 ) ? 4 : CheckTrailingBit5( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit5( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000 ) ? 5 : CheckTrailingBit6( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit6( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000 ) ? 6 : CheckTrailingBit7( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit7( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000 ) ? 7 : CheckTrailingBit8( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit8( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000 ) ? 8 : CheckTrailingBit9( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit9( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000 ) ? 9 : CheckTrailingBit10( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit10( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000 ) ? 10 : CheckTrailingBit11( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit11( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000 ) ? 11 : CheckTrailingBit12( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit12( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000 ) ? 12 : CheckTrailingBit13( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit13( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000 ) ? 13 : CheckTrailingBit14( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit14( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000 ) ? 14 : CheckTrailingBit15( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit15( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000 ) ? 15 : CheckTrailingBit16( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit16( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000 ) ? 16 : CheckTrailingBit17( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit17( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000 ) ? 17 : CheckTrailingBit18( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit18( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000 ) ? 18 : CheckTrailingBit19( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit19( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000 ) ? 19 : CheckTrailingBit20( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit20( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000 ) ? 20 : CheckTrailingBit21( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit21( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000 ) ? 21 : CheckTrailingBit22( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit22( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000 ) ? 22 : CheckTrailingBit23( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit23( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000 ) ? 23 : CheckTrailingBit24( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit24( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000'0000 ) ? 24 : CheckTrailingBit25( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit25( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000'0000 ) ? 25 : CheckTrailingBit26( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit26( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000'0000 ) ? 26 : CheckTrailingBit27( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit27( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000'0000 ) ? 27 : CheckTrailingBit28( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit28( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000'0000'0000 ) ? 28 : CheckTrailingBit29( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit29( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000'0000'0000 ) ? 29 : CheckTrailingBit30( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit30( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000'0000'0000 ) ? 30 : CheckTrailingBit31( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit31( const uint32_t /* Mask */ ) noexcept )
				{
					// If we got here, this bit must be set.
					// (Behavior is undefined if no bits are set.)
					return 31;
				}


				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit0( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b1 ) ? 0 : CheckTrailingBit1( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit1( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b10 ) ? 1 : CheckTrailingBit2( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit2( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b100 ) ? 2 : CheckTrailingBit3( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit3( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b1000 ) ? 3 : CheckTrailingBit4( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit4( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000 ) ? 4 : CheckTrailingBit5( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit5( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000 ) ? 5 : CheckTrailingBit6( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit6( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000 ) ? 6 : CheckTrailingBit7( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit7( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000 ) ? 7 : CheckTrailingBit8( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit8( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000 ) ? 8 : CheckTrailingBit9( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit9( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000 ) ? 9 : CheckTrailingBit10( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit10( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000 ) ? 10 : CheckTrailingBit11( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit11( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000 ) ? 11 : CheckTrailingBit12( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit12( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000 ) ? 12 : CheckTrailingBit13( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit13( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000 ) ? 13 : CheckTrailingBit14( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit14( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000 ) ? 14 : CheckTrailingBit15( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit15( const uint16_t /* Mask */ ) noexcept )
				{
					// If we got here, this bit must be set.
					// (Behavior is undefined if no bits are set.)
					return 15;
				}


				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit0( const uint8_t Mask ) noexcept )
				{
					return ( Mask & 0b1 ) ? 0 : CheckTrailingBit1( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit1( const uint8_t Mask ) noexcept )
				{
					return ( Mask & 0b10 ) ? 1 : CheckTrailingBit2( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit2( const uint8_t Mask ) noexcept )
				{
					return ( Mask & 0b100 ) ? 2 : CheckTrailingBit3( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit3( const uint8_t Mask ) noexcept )
				{
					return ( Mask & 0b1000 ) ? 3 : CheckTrailingBit4( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit4( const uint8_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000 ) ? 4 : CheckTrailingBit5( Mask ); //-V112
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit5( const uint8_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000 ) ? 5 : CheckTrailingBit6( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit6( const uint8_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000 ) ? 6 : CheckTrailingBit7( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckTrailingBit7( const uint8_t /* Mask */ ) noexcept )
				{
					// If we got here, this bit must be set.
					// (Behavior is undefined if no bits are set.)
					return 7;
				}


				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit0( const uint64_t /* Mask */ ) noexcept )
				{
					// If we got here, this bit must be set.
					// (Behavior is undefined if no bits are set.)
					return 63;
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit1( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10 ) ? 62 : CheckLeadingBit0( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit2( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100 ) ? 61 : CheckLeadingBit1( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit3( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000 ) ? 60 : CheckLeadingBit2( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit4( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000 ) ? 59 : CheckLeadingBit3( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit5( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000 ) ? 58 : CheckLeadingBit4( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit6( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000 ) ? 57 : CheckLeadingBit5( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit7( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000 ) ? 56 : CheckLeadingBit6( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit8( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000 ) ? 55 : CheckLeadingBit7( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit9( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000 ) ? 54 : CheckLeadingBit8( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit10( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000 ) ? 53 : CheckLeadingBit9( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit11( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000 ) ? 52 : CheckLeadingBit10( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit12( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000 ) ? 51 : CheckLeadingBit11( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit13( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000 ) ? 50 : CheckLeadingBit12( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit14( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000 ) ? 49 : CheckLeadingBit13( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit15( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000 ) ? 48 : CheckLeadingBit14( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit16( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000 ) ? 47 : CheckLeadingBit15( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit17( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000 ) ? 46 : CheckLeadingBit16( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit18( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000 ) ? 45 : CheckLeadingBit17( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit19( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000 ) ? 44 : CheckLeadingBit18( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit20( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000 ) ? 43 : CheckLeadingBit19( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit21( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000 ) ? 42 : CheckLeadingBit20( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit22( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000 ) ? 41 : CheckLeadingBit21( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit23( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000 ) ? 40 : CheckLeadingBit22( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit24( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000'0000 ) ? 39 : CheckLeadingBit23( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit25( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000'0000 ) ? 38 : CheckLeadingBit24( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit26( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000'0000 ) ? 37 : CheckLeadingBit25( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit27( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000'0000 ) ? 36 : CheckLeadingBit26( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit28( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000'0000'0000 ) ? 35 : CheckLeadingBit27( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit29( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000'0000'0000 ) ? 34 : CheckLeadingBit28( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit30( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000'0000'0000 ) ? 33 : CheckLeadingBit29( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit31( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000'0000'0000 ) ? 32 : CheckLeadingBit30( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit32( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 31 : CheckLeadingBit31( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit33( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 30 : CheckLeadingBit32( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit34( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 29 : CheckLeadingBit33( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit35( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 28 : CheckLeadingBit34( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit36( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 27 : CheckLeadingBit35( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit37( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 26 : CheckLeadingBit36( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit38( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 25 : CheckLeadingBit37( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit39( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 24 : CheckLeadingBit38( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit40( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 23 : CheckLeadingBit39( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit41( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 22 : CheckLeadingBit40( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit42( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 21 : CheckLeadingBit41( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit43( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 20 : CheckLeadingBit42( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit44( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 19 : CheckLeadingBit43( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit45( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 18 : CheckLeadingBit44( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit46( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 17 : CheckLeadingBit45( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit47( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 16 : CheckLeadingBit46( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit48( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 15 : CheckLeadingBit47( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit49( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 14 : CheckLeadingBit48( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit50( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 13 : CheckLeadingBit49( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit51( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 12 : CheckLeadingBit50( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit52( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 11 : CheckLeadingBit51( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit53( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 10 : CheckLeadingBit52( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit54( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 9 : CheckLeadingBit53( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit55( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 8 : CheckLeadingBit54( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit56( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 7 : CheckLeadingBit55( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit57( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 6 : CheckLeadingBit56( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit58( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 5 : CheckLeadingBit57( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit59( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 4 : CheckLeadingBit58( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit60( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 3 : CheckLeadingBit59( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit61( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 2 : CheckLeadingBit60( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit62( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 1 : CheckLeadingBit61( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit63( const uint64_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000 ) ? 0 : CheckLeadingBit62( Mask );
				}


				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit0( const uint32_t /* Mask */ ) noexcept )
				{
					// If we got here, this bit must be set.
					// (Behavior is undefined if no bits are set.)
					return 31;
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit1( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b10 ) ? 30 : CheckLeadingBit0( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit2( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b100 ) ? 29 : CheckLeadingBit1( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit3( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1000 ) ? 28 : CheckLeadingBit2( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit4( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000 ) ? 27 : CheckLeadingBit3( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit5( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000 ) ? 26 : CheckLeadingBit4( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit6( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000 ) ? 25 : CheckLeadingBit5( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit7( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000 ) ? 24 : CheckLeadingBit6( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit8( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000 ) ? 23 : CheckLeadingBit7( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit9( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000 ) ? 22 : CheckLeadingBit8( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit10( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000 ) ? 21 : CheckLeadingBit9( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit11( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000 ) ? 20 : CheckLeadingBit10( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit12( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000 ) ? 19 : CheckLeadingBit11( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit13( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000 ) ? 18 : CheckLeadingBit12( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit14( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000 ) ? 17 : CheckLeadingBit13( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit15( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000 ) ? 16 : CheckLeadingBit14( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit16( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000 ) ? 15 : CheckLeadingBit15( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit17( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000 ) ? 14 : CheckLeadingBit16( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit18( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000 ) ? 13 : CheckLeadingBit17( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit19( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000 ) ? 12 : CheckLeadingBit18( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit20( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000 ) ? 11 : CheckLeadingBit19( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit21( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000 ) ? 10 : CheckLeadingBit20( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit22( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000 ) ? 9 : CheckLeadingBit21( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit23( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000 ) ? 8 : CheckLeadingBit22( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit24( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000'0000 ) ? 7 : CheckLeadingBit23( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit25( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000'0000 ) ? 6 : CheckLeadingBit24( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit26( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000'0000 ) ? 5 : CheckLeadingBit25( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit27( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000'0000 ) ? 4 : CheckLeadingBit26( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit28( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000'0000'0000'0000'0000 ) ? 3 : CheckLeadingBit27( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit29( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000'0000'0000'0000'0000 ) ? 2 : CheckLeadingBit28( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit30( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000'0000'0000'0000'0000 ) ? 1 : CheckLeadingBit29( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit31( const uint32_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000'0000'0000'0000'0000 ) ? 0 : CheckLeadingBit30( Mask );
				}


				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit0( const uint16_t /* Mask */ ) noexcept )
				{
					// If we got here, this bit must be set.
					// (Behavior is undefined if no bits are set.)
					return 15;
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit1( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b10 ) ? 14 : CheckLeadingBit0( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit2( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b100 ) ? 13 : CheckLeadingBit1( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit3( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b1000 ) ? 12 : CheckLeadingBit2( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit4( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000 ) ? 11 : CheckLeadingBit3( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit5( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000 ) ? 10 : CheckLeadingBit4( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit6( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000 ) ? 9 : CheckLeadingBit5( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit7( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000 ) ? 8 : CheckLeadingBit6( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit8( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000 ) ? 7 : CheckLeadingBit7( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit9( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000 ) ? 6 : CheckLeadingBit8( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit10( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000 ) ? 5 : CheckLeadingBit9( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit11( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000 ) ? 4 : CheckLeadingBit10( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit12( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000'0000'0000 ) ? 3 : CheckLeadingBit11( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit13( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000'0000'0000 ) ? 2 : CheckLeadingBit12( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit14( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000'0000'0000 ) ? 1 : CheckLeadingBit13( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit15( const uint16_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000'0000'0000 ) ? 0 : CheckLeadingBit14( Mask );
				}


				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit0( const uint8_t /* Mask */ ) noexcept )
				{
					// If we got here, this bit must be set.
					// (Behavior is undefined if no bits are set.)
					return 7;
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit1( const uint8_t Mask ) noexcept )
				{
					return ( Mask & 0b10 ) ? 6 : CheckLeadingBit0( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit2( const uint8_t Mask ) noexcept )
				{
					return ( Mask & 0b100 ) ? 5 : CheckLeadingBit1( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit3( const uint8_t Mask ) noexcept )
				{
					return ( Mask & 0b1000 ) ? 4 : CheckLeadingBit2( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit4( const uint8_t Mask ) noexcept )
				{
					return ( Mask & 0b1'0000 ) ? 3 : CheckLeadingBit3( Mask ); //-V112
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit5( const uint8_t Mask ) noexcept )
				{
					return ( Mask & 0b10'0000 ) ? 2 : CheckLeadingBit4( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit6( const uint8_t Mask ) noexcept )
				{
					return ( Mask & 0b100'0000 ) ? 1 : CheckLeadingBit5( Mask );
				}

				MAX_PURE_DEFINITION( MAX_BITSCAN_CONSTEVAL inline uint8_t CheckLeadingBit7( const uint8_t Mask ) noexcept )
				{
					return ( Mask & 0b1000'0000 ) ? 0 : CheckLeadingBit6( Mask );
				}

			} // namespace ImplementationDetails

		} // namespace Algorithms
	} // namespace v0
} // namespace max
