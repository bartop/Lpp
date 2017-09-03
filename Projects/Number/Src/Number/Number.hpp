
#pragma once

#include "NumberExchangeFormat.hpp"

#include "Generic/Src/ValueObject.hpp"

#include "Config/Src/config.hpp"

namespace Lpp{

struct Number : public ValueObject<Number> {
	virtual NumberExchangeFormat numberValue() const = 0;
	bool equals(const Shared<const Number> &_number) const final override;
};

}
