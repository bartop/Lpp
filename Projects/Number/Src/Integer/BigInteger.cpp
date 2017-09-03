
#include "BigInteger.hpp"
#include "Integer.hpp"
#include "IntegerExchangeFormat.hpp"

namespace Lpp{

namespace{

class BigInteger final : public Integer {
public:
	BigInteger(const std::deque<unsigned> &_longInt);

	IntegerExchangeFormat integerValue() const final override;

private:
	const std::deque<unsigned> m_longInteger;
};

BigInteger::BigInteger(const std::deque<unsigned> &_longInt)
	: m_longInteger(_longInt)
{}

IntegerExchangeFormat BigInteger::integerValue() const{
	return IntegerExchangeFormat(m_longInteger);
}

}

Unique<const Integer> bigInteger(
	const std::deque<unsigned> &_bigInteger
){
	return makeUnique<BigInteger>(_bigInteger);
}

}
