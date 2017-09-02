
#include "BasicInt.hpp"
#include "IntegerExchangeFormat.hpp"
#include "Integer.hpp"

namespace Lpp{

namespace
{

class BasicInt final : public Integer {
public:
	BasicInt(int _int);

	IntegerExchangeFormat integerValue() const final override;

private:
	const int m_int;
};


BasicInt::BasicInt(int _int) : m_int(_int){}

IntegerExchangeFormat BasicInt::integerValue() const{
	return IntegerExchangeFormat({ static_cast<unsigned>(m_int) });
}

}

Unique<Integer> basicInt(int _int){
	return makeUnique<BasicInt>(_int);
}

}
