
#include "Product.hpp"
#include "Number.hpp"
#include "NumberOperations.hpp"

namespace Lpp{

namespace{

class NumberProduct final : public Number {
public:
	NumberProduct(
		const Shared<const Number> &_lhs,
		const Shared<const Number> &_rhs
	);

	NumberExchangeFormat numberValue() const final override;

private:
	const Shared<const Number> m_lhs;
	const Shared<const Number> m_rhs;
};

NumberProduct::NumberProduct(
	const Shared<const Number> &_lhs,
	const Shared<const Number> &_rhs
)
	: m_lhs(_lhs), m_rhs(_rhs)
{}

NumberExchangeFormat NumberProduct::numberValue() const {
	return multiply(m_lhs->numberValue(), m_rhs->numberValue());
}

}

Unique<const Number> product(
	const Shared<const Number> &_lhs,
	const Shared<const Number> &_rhs
){
	return makeUnique<NumberProduct>(_lhs, _rhs);
}

}
