#pragma once

#include "Integer.hpp"

namespace Lpp{

class IntegerSum final : public Integer {
public:
	IntegerSum(Pointer<Integer> _lhs, Pointer<Integer> _rhs);

	IntegerExchangeFormat integerValue() const final override;

private:
	const Pointer<Integer> m_lhs;
	const Pointer<Integer> m_rhs;
};

std::unique_ptr<IntegerSum> sum(
	Pointer<Integer> _lhs,
	Pointer<Integer> _rhs
);

}
