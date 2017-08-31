
#include "IntegerFromReal.hpp"
#include "RealNumber.hpp"
#include "IntegerOperations.hpp"

namespace Lpp{

IntegerFromReal::IntegerFromReal(Shared<RealNumber> _real)
	: m_real(_real)
{}

IntegerExchangeFormat IntegerFromReal::integerValue() const {
	const auto realVal = m_real->realValue();
	return integerDivide(realVal.numerator, realVal.denominator).first;
}

Unique<IntegerFromReal> toInteger(
	Shared<RealNumber> _real
){
	return std::make_unique<IntegerFromReal>(_real);
}

}
