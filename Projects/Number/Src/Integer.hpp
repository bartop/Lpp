
#pragma once

#include "RealNumber.hpp"
#include "IntegerExchangeFormat.hpp"

namespace Lpp{

struct Integer : public RealNumber {
public:
	RealNumberExchangeFormat realValue() const final override;
	virtual IntegerExchangeFormat integerValue() const = 0;
};

}
