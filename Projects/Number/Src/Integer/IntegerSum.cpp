
#include "IntegerSum.hpp"
#include "Integer.hpp"
#include "IntegerOperations.hpp"

namespace Lpp{

namespace{

class IntegerSum final : public Integer {
public:
	IntegerSum(
		const Shared<const Integer> &_lhs,
		const Shared<const Integer> &_rhs
	);

	IntegerExchangeFormat integerValue() const final override;

private:
	const Shared<const Integer> m_lhs;
	const Shared<const Integer> m_rhs;
};

IntegerSum::IntegerSum(
	const Shared<const Integer> &_lhs,
	const Shared<const Integer> &_rhs
)
	: m_lhs(_lhs), m_rhs(_rhs)
{}

IntegerExchangeFormat IntegerSum::integerValue() const {
	return add(m_lhs->integerValue(), m_rhs->integerValue());
}

}

Unique<const Integer> integerSum(
	const Shared<const Integer> &_lhs,
	const Shared<const Integer> &_rhs
){
	return makeUnique<IntegerSum>(_lhs, _rhs);
}

}
