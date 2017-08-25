
#include "IntegerSum.hpp"
#include "IntegerOperations.hpp"

namespace Lpp{

IntegerSum::IntegerSum(Shared<Integer> _lhs, Shared<Integer> _rhs)
	: m_lhs(_lhs), m_rhs(_rhs)
{}

IntegerExchangeFormat IntegerSum::integerValue() const {
	return add(m_lhs->integerValue(), m_rhs->integerValue());
}

Unique<IntegerSum> sum(
	Shared<Integer> _lhs,
	Shared<Integer> _rhs
){
	return std::make_unique<IntegerSum>(_lhs, _rhs);
}

}
