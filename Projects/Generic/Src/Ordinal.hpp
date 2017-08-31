
#pragma once

#include "ValueObject.hpp"

namespace Lpp{

enum class ResultOfComparison{
	LeftSideGreater = 1,
	Equal = 0,
	RightSideGreater = -1
};

template<typename T>
struct Ordinal : public ValueObject<T> {

	bool equals(std::shared_ptr<const T> _valueObject) const final override;

	virtual ResultOfComparison compare(std::shared_ptr<const T> _valueObject) const = 0;

	virtual ~Ordinal() noexcept = default;
};

template<typename T>
inline bool Ordinal<T>::equals(std::shared_ptr<const T> _valueObject) const{
	return compare(_valueObject) == ResultOfComparison::Equal;
}

}
