#pragma once

#include "Integer.hpp"

namespace Lpp{

class RealNumber;

class IntegerFromReal final : public Integer {
public:
	IntegerFromReal(Shared<RealNumber> _real);

	IntegerExchangeFormat integerValue() const final override;

private:
	const Shared<RealNumber> m_real;
};

Unique<IntegerFromReal> toInteger(
	Shared<RealNumber> _real
);

}
