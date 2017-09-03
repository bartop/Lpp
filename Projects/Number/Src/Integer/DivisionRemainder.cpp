
#include "DivisionRemainder.hpp"
#include "Integer.hpp"
#include "IntegerOperations.hpp"

namespace Lpp{

namespace{

class Remainder final : public Integer {
public:
	Remainder(
		const Shared<const Integer> &_lhs,
		const Shared<const Integer> &_rhs
	);

	IntegerExchangeFormat integerValue() const final override;

private:
	const Shared<const Integer> m_lhs;
	const Shared<const Integer> m_rhs;
};

Remainder::Remainder(
	const Shared<const Integer> &_lhs,
	const Shared<const Integer> &_rhs
)
	: m_lhs(_lhs), m_rhs(_rhs)
{}

IntegerExchangeFormat Remainder::integerValue() const {
	return integerDivide(m_lhs->integerValue(), m_rhs->integerValue()).second;
}

}

Unique<const Integer> divisionRemainder(
	const Shared<const Integer> &_lhs,
	const Shared<const Integer> &_rhs
){
	return makeUnique<Remainder>(_lhs, _rhs);
}

}
