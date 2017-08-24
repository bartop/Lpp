
#pragma once

#include "../../Generic/Src/ValueObject.hpp"
#include "Boolean.hpp"
#include <memory>
#include <type_traits>

namespace Lpp{

template<typename T>
class EqualityComparisonResult final : public Boolean{
public:
	EqualityComparisonResult(
		Pointer<const T> _left,
		Pointer<const T> _right
	);

	bool value() const final override;

private:
	const Pointer<const T> m_left;
	const Pointer<const T> m_right;
};

template<typename T>
EqualityComparisonResult<T>::EqualityComparisonResult (
	Pointer<const T> _left,
	Pointer<const T> _right
) : m_left(_left), m_right(_right){
}

template<typename T>
bool EqualityComparisonResult<T>::value() const{
	return m_left->equals(m_right);
}

template<typename T>
std::unique_ptr<const Boolean> compareForEquality(
	Pointer<T> _left,
	Pointer<T> _right
){
	return std::make_unique<const EqualityComparisonResult<T>>(
		_left,
		_right
	);
}

template<typename T>
std::unique_ptr<const Boolean> compareForEquality(
	std::unique_ptr<const T> _left,
	std::unique_ptr<const T> _right
){
	return std::make_unique<const EqualityComparisonResult<T>>(
		Pointer<const T>(std::move(_left)),
		Pointer<const T>(std::move(_right))
	);
}

}
