
#include "Integer.hpp"
#include "IntegerSum.hpp"
#include "IntegerOperations.hpp"

namespace Lpp{

namespace{

class IntegerSum final : public Integer {
public:
	IntegerSum(Shared<Integer> _lhs, Shared<Integer> _rhs);

	IntegerExchangeFormat integerValue() const final override;

private:
	const Shared<Integer> m_lhs;
	const Shared<Integer> m_rhs;
};

IntegerSum::IntegerSum(Shared<Integer> _lhs, Shared<Integer> _rhs)
	: m_lhs(_lhs), m_rhs(_rhs)
{}

IntegerExchangeFormat IntegerSum::integerValue() const {
	return add(m_lhs->integerValue(), m_rhs->integerValue());
}

}

Unique<Integer> integerSum(
	Shared<Integer> _lhs,
	Shared<Integer> _rhs
){
	return makeUnique<IntegerSum>(_lhs, _rhs);
}

}
