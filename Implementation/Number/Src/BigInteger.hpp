
#pragma once

#include "Integer.hpp"

namespace Lpp{

class BigInteger final : public Integer {
public:
	BigInteger(const std::vector<unsigned> &_longInt);

	IntegerExchangeFormat integerValue() const final override;

private:
	const std::vector<unsigned> m_longInteger;
};

}
