
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
		Shared<const T> _left,
		Shared<const T> _right
	);

	bool value() const final override;

private:
	const Shared<const T> m_left;
	const Shared<const T> m_right;
};

template<typename T>
EqualityComparisonResult<T>::EqualityComparisonResult (
	Shared<const T> _left,
	Shared<const T> _right
) : m_left(_left), m_right(_right){
}

template<typename T>
bool EqualityComparisonResult<T>::value() const{
	return m_left->equals(m_right);
}

template<typename T>
Unique<const Boolean> compareForEquality(
	Shared<T> _left,
	Shared<T> _right
){
	return std::make_unique<const EqualityComparisonResult<T>>(
		_left,
		_right
	);
}

template<typename T>
Unique<const Boolean> compareForEquality(
	Unique<const T> _left,
	Unique<const T> _right
){
	return std::make_unique<const EqualityComparisonResult<T>>(
		Shared<const T>(std::move(_left)),
		Shared<const T>(std::move(_right))
	);
}

}
