
#include "Sum.hpp"
#include "Number.hpp"
#include "NumberOperations.hpp"

namespace Lpp{

namespace{

class NumberSum final : public Number {
public:
	NumberSum(
		const Shared<const Number> &_lhs,
		const Shared<const Number> &_rhs
	);

	NumberExchangeFormat numberValue() const final override;

private:
	const Shared<const Number> m_lhs;
	const Shared<const Number> m_rhs;
};

NumberSum::NumberSum(
	const Shared<const Number> &_lhs,
	const Shared<const Number> &_rhs
)
	: m_lhs(_lhs), m_rhs(_rhs)
{}

NumberExchangeFormat NumberSum::numberValue() const {
	return add(m_lhs->numberValue(), m_rhs->numberValue());
}

}

Unique<const Number> realSum(
	const Shared<const Number> &_lhs,
	const Shared<const Number> &_rhs
){
	return makeUnique<NumberSum>(_lhs, _rhs);
}

}
