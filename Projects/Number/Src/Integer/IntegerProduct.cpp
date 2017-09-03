
#include "IntegerProduct.hpp"
#include "Integer.hpp"
#include "IntegerOperations.hpp"

namespace Lpp{

namespace{

class IntegerProduct final : public Integer {
public:
	IntegerProduct(
		const Shared<const Integer> &_lhs,
		const Shared<const Integer> &_rhs
	);

	IntegerExchangeFormat integerValue() const final override;

private:
	const Shared<const Integer> m_lhs;
	const Shared<const Integer> m_rhs;
};

IntegerProduct::IntegerProduct(
	const Shared<const Integer> &_lhs,
	const Shared<const Integer> &_rhs
)
	: m_lhs(_lhs), m_rhs(_rhs)
{}

IntegerExchangeFormat IntegerProduct::integerValue() const {
	return multiply(m_lhs->integerValue(), m_rhs->integerValue());
}

}

Unique<const Integer> integerProduct(
	const Shared<const Integer> &_lhs,
	const Shared<const Integer> &_rhs
){
	return makeUnique<IntegerProduct>(_lhs, _rhs);
}

}
