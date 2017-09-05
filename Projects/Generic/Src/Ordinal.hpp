
#pragma once

#include "ValueObject.hpp"

#include "Config/Src/config.hpp"

namespace Lpp{

enum class ResultOfComparison{
	LeftSideGreater = 1,
	Equal = 0,
	RightSideGreater = -1
};

template<typename T>
struct Ordinal : public ValueObject<T> {

	bool equals(const Shared<const T> &_valueObject) const final override;

	virtual ResultOfComparison compare(const Shared<const T> &_valueObject) const = 0;

protected:
	virtual ~Ordinal() noexcept = default;
};

template<typename T>
inline
bool Ordinal<T>::equals(const Shared<const T> &_valueObject) const{
	return compare(_valueObject) == ResultOfComparison::Equal;
}

}
