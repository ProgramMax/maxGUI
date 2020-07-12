// Copyright 2019, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

namespace max
{
namespace v0
{
namespace Compiling
{

	template <typename Base>
	ClonableConcept<Base>::~ClonableConcept() = default;

	template <typename Base, typename Derived>
	ClonableModel<Base, Derived>::~ClonableModel() = default;

	template <typename Base, typename Derived>
	std::shared_ptr<Base> ClonableModel<Base, Derived>::clone_impl(Base const* clonable) const {
		return std::make_shared<Derived>(static_cast<const Derived&>(*clonable));
	}

	template <typename Derived>
	class make_clonable_tag {};

} // namespace Compiling
} // namespace v0
} // namespace max
