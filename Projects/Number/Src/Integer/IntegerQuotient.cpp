
#include "IntegerQuotient.hpp"
#include "Integer.hpp"
#include "IntegerOperations.hpp"

namespace Lpp{

namespace{

class IntegerQuotient final : public Integer {
public:
	IntegerQuotient(
		const Shared<const Integer> &_lhs,
		const Shared<const Integer> &_rhs
	);

	IntegerExchangeFormat integerValue() const final override;

private:
	const Shared<const Integer> m_lhs;
	const Shared<const Integer> m_rhs;
};

IntegerQuotient::IntegerQuotient(
	const Shared<const Integer> &_lhs,
	const Shared<const Integer> &_rhs
)
	: m_lhs(_lhs), m_rhs(_rhs)
{}

IntegerExchangeFormat IntegerQuotient::integerValue() const {
	return integerDivide(m_lhs->integerValue(), m_rhs->integerValue()).first;
}

}

Unique<const Integer> integerQuotient(
	const Shared<const Integer> &_lhs,
	const Shared<const Integer> &_rhs
){
	return makeUnique<IntegerQuotient>(_lhs, _rhs);
}

}
