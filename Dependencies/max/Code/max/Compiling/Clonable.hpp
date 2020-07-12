// Copyright 2019, The max Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAX_COMPILING_CLONABLE_HPP
#define MAX_COMPILING_CLONABLE_HPP

#include <max/Compiling/CurrentVersionNamespace.hpp>
#include <max/Compiling/ThrowSpecification.hpp>
#include <memory>

namespace max
{
MAX_CURRENT_VERSION_NAMESPACE_BEGIN(v0)
{
namespace Compiling
{

	template <typename Base>
	class ClonableConcept {
	public:
		virtual ~ClonableConcept();
		virtual std::shared_ptr<Base> clone_impl(Base const* clonable) const = 0;
	};

	template <typename Base, typename Derived>
	class ClonableModel : public ClonableConcept<Base> {
	public:
		~ClonableModel() override;
		std::shared_ptr<Base> clone_impl(Base const* clonable) const override;
	};

} // namespace Compiling
} // MAX_CURRENT_VERSION_NAMESPACE_BEGIN( v0 )
MAX_CURRENT_VERSION_NAMESPACE_END(v0)
} // namespace max

#include <max/Compiling/Clonable.inl>

#endif // #ifndef MAX_COMPILING_CLONABLE_HPP