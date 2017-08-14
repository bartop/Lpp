
#pragma once

#include <memory>

namespace Lpp{

template<typename T>
struct ValueObject{
	virtual bool equals(std::shared_ptr<const T> _valueObject) const = 0;
	bool differs(std::shared_ptr<const T> _valueObject) const;

	virtual ~ValueObject() noexcept = default;
};

template<typename T>
bool ValueObject<T>::differs(std::shared_ptr<const T> _valueObject) const{
	return !this->equals(_valueObject);
}

}
