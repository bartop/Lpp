
#pragma once

#include "NumberExchangeFormat.hpp"
#include "../../Generic/Src/ValueObject.hpp"
#include "../../Config/Src/config.hpp"

#include <memory>

namespace Lpp{

struct Number : public ValueObject<Number> {
	virtual NumberExchangeFormat numberValue() const = 0;
	bool equals(std::shared_ptr<const Number> _number) const final override;
};

}
