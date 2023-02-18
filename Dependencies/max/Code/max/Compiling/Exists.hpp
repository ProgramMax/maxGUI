// Copyright 2023, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_COMPILING_EXISTS_HPP
#define MAX_COMPILING_EXISTS_HPP

#include <type_traits>

namespace max
{
	namespace Compiling
	{

		template <class T, template <class...> class Test>
		struct Exists
		{
			template<class U>
			static std::true_type Check(Test<U>*);

			template<class U>
			static std::false_type Check(...);

			static constexpr bool value = decltype(Check<T>(0))::value;
		};

		// Usage:
		// template<class U, class = decltype(U::MemberFunctionNameHere())>
		// struct MemberFunctionNameHereTest{};
		// if constexpr (max::Compiling::Exists<ClassHere, MemberFunctionNameHereTest>::value) { ... }

	} // namespace Compiling
} // namespace max

#endif // #ifndef MAX_COMPILING_EXISTS_HPP