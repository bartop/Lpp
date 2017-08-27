
#pragma once

#include "Integer.hpp"

namespace Lpp{

class BigInteger final : public Integer {
public:
	BigInteger(const std::deque<unsigned> &_longInt);

	IntegerExchangeFormat integerValue() const final override;

private:
	const std::deque<unsigned> m_longInteger;
};

}
