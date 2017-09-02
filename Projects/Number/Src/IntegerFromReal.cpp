
#include "IntegerFromReal.hpp"
#include "RealNumber.hpp"
#include "IntegerOperations.hpp"
#include "Integer.hpp"

namespace Lpp{

namespace{

class IntegerFromReal final : public Integer {
public:
	IntegerFromReal(Shared<RealNumber> _real);

	IntegerExchangeFormat integerValue() const final override;

private:
	const Shared<RealNumber> m_real;
};

IntegerFromReal::IntegerFromReal(Shared<RealNumber> _real)
	: m_real(_real)
{}

IntegerExchangeFormat IntegerFromReal::integerValue() const {
	const auto realVal = m_real->realValue();
	return integerDivide(realVal.numerator, realVal.denominator).first;
}

}

Unique<Integer> toInteger(
	Shared<RealNumber> _real
){
	return std::make_unique<IntegerFromReal>(_real);
}

}
