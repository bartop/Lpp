
#pragma once

#include "ValueObject.hpp"
#include "Boolean.hpp"
#include <memory>

namespace Lpp{

template<typename T>
std::unique_ptr<Boolean> compareForEquality(
		Pointer<const ValueObject<T>> _left,
		Pointer<const ValueObject<T>> _right);

template<typename T>
class EqualityComparisonResult final : public Boolean{
public:
	ComparisonResult(
		Pointer<const ValueObject<T>> _left,
		Pointer<const ValueObject<T>> _right);

	bool value() const final override;

private:
	const Pointer<const ValueObject<T>> m_left;
	const Pointer<const ValueObject<T>> m_right;
};

template<typename T>
ComparisonResult<T>::ComparisonResult(
	Pointer<const ValueObject<T>> _left,
	Pointer<const ValueObject<T>> _right) : m_left(_left), m_right(_right){
}

template<typename T>
bool ComparisonResult<T>::value() const{
	return m_left->equals(std::static_pointer_cast<T>(m_right));
}

template<typename T>
std::unique_ptr<Boolean> compareForEquality(
		Pointer<const ValueObject<T>> _left,
		Pointer<const ValueObject<T>> _right){
	return std::make_unique<EqualityComparisonResult<T>>(_left, _right);
}
}
