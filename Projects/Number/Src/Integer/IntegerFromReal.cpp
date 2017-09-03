
#include "IntegerFromReal.hpp"
#include "IntegerOperations.hpp"
#include "Integer.hpp"

#include "../Real/RealNumber.hpp"

namespace Lpp{

namespace{

class IntegerFromReal final : public Integer {
public:
	IntegerFromReal(const Shared<const RealNumber> &_real);

	IntegerExchangeFormat integerValue() const final override;

private:
	const Shared<const RealNumber> m_real;
};

IntegerFromReal::IntegerFromReal(const Shared<const RealNumber> &_real)
	: m_real(_real)
{}

IntegerExchangeFormat IntegerFromReal::integerValue() const {
	const auto realVal = m_real->realValue();
	return integerDivide(realVal.numerator, realVal.denominator).first;
}

}

Unique<const Integer> toInteger(
	const Shared<const RealNumber> &_real
){
	return makeUnique<IntegerFromReal>(_real);
}

}
