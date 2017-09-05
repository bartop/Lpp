
#pragma once

#include <memory>

#include "Config/Src/config.hpp"

namespace Lpp{

template<typename T>
struct ValueObject{
	virtual bool equals(const Shared<const T> &_valueObject) const = 0;
	bool differs(const Shared<const T> &_valueObject) const;

protected:
	virtual ~ValueObject() noexcept = default;
};

template<typename T>
bool ValueObject<T>::differs(
	const Shared<const T> &_valueObject
) const {
	return !this->equals(_valueObject);
}

}
