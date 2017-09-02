
#pragma once

#include "IntegerExchangeFormat.hpp"

#include "../Real/RealNumber.hpp"

namespace Lpp{

struct Integer : public RealNumber {
public:
	RealNumberExchangeFormat realValue() const final override;
	virtual IntegerExchangeFormat integerValue() const = 0;
};

}
