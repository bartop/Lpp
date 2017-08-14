
#include "IntegerSum.hpp"
#include "IntegerOperations.hpp"

namespace Lpp{

IntegerSum::IntegerSum(Pointer<Integer> _lhs, Pointer<Integer> _rhs)
	: m_lhs(_lhs), m_rhs(_rhs)
{}

IntegerExchangeFormat IntegerSum::integerValue() const {
	return add(m_lhs->integerValue(), m_rhs->integerValue());
}

std::unique_ptr<IntegerSum> sum(
	Pointer<Integer> _lhs,
	Pointer<Integer> _rhs
){
	return std::make_unique<IntegerSum>(_lhs, _rhs);
}

}
