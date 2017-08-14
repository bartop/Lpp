#pragma once

#include "Integer.hpp"

namespace Lpp{

class RealNumber;

class IntegerFromReal final : public Integer {
public:
	IntegerFromReal(Pointer<RealNumber> _real);

	IntegerExchangeFormat integerValue() const final override;

private:
	const Pointer<RealNumber> m_real;
};

std::unique_ptr<IntegerFromReal> toInteger(
	Pointer<RealNumber> _real
);

}
