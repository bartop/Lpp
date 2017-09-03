
#pragma once

#include "Boolean.hpp"

#include "Generic/Src/ValueObject.hpp"

#include <type_traits>

namespace Lpp{

template<typename T>
class EqualityComparisonResult final : public Boolean{
public:
	EqualityComparisonResult(
		const Shared<const T> &_left,
		const Shared<const T> &_right
	);

	bool value() const final override;

private:
	const Shared<const T> m_left;
	const Shared<const T> m_right;
};

template<typename T>
EqualityComparisonResult<T>::EqualityComparisonResult (
	const Shared<const T> &_left,
	const Shared<const T> &_right
) : m_left(_left), m_right(_right){
}

template<typename T>
bool EqualityComparisonResult<T>::value() const {
	return m_left->equals(m_right);
}

template<typename T>
Unique<const Boolean> compareForEquality(
	const Shared<const T> &_left,
	const Shared<const T> &_right
){
	return makeUnique<EqualityComparisonResult<T>>(
		_left,
		_right
	);
}

template<typename T>
Unique<const Boolean> compareForEquality(
	Unique<const T> _left,
	Unique<const T> _right
){
	return makeUnique<EqualityComparisonResult<T>>(
		static_cast<Shared<const T>>(std::move(_left)),
		static_cast<Shared<const T>>(std::move(_right))
	);
}

}
