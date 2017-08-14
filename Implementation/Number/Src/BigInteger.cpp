
#include "BigInteger.hpp"
#include "IntegerExchangeFormat.hpp"

namespace Lpp{

BigInteger::BigInteger(const std::vector<unsigned> &_longInt)
	: m_longInteger(_longInt)
{}

IntegerExchangeFormat BigInteger::integerValue() const{
	return IntegerExchangeFormat(m_longInteger);
}

}
