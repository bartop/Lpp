
#include "Quotient.hpp"
#include "Number.hpp"
#include "NumberOperations.hpp"

namespace Lpp{

namespace{

class NumberQuotient final : public Number {
public:
	NumberQuotient(
		const Shared<const Number> &_lhs,
		const Shared<const Number> &_rhs
	);

	NumberExchangeFormat numberValue() const final override;

private:
	const Shared<const Number> m_lhs;
	const Shared<const Number> m_rhs;
};

NumberQuotient::NumberQuotient(
	const Shared<const Number> &_lhs,
	const Shared<const Number> &_rhs
)
	: m_lhs(_lhs), m_rhs(_rhs)
{}

NumberExchangeFormat NumberQuotient::numberValue() const {
	return divide(m_lhs->numberValue(), m_rhs->numberValue());
}

}

Unique<const Number> quotient(
	const Shared<const Number> &_lhs,
	const Shared<const Number> &_rhs
){
	return makeUnique<NumberQuotient>(_lhs, _rhs);
}

}
