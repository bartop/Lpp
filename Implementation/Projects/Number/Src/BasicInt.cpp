
#include "BasicInt.hpp"
#include "IntegerExchangeFormat.hpp"

namespace Lpp{
BasicInt::BasicInt(int _int) : m_int(_int){}

IntegerExchangeFormat BasicInt::integerValue() const{
	return IntegerExchangeFormat({ static_cast<unsigned>(m_int) });
}

}
