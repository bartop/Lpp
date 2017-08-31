#pragma once

#include "Integer.hpp"

namespace Lpp{

class IntegerSum final : public Integer {
public:
	IntegerSum(Shared<Integer> _lhs, Shared<Integer> _rhs);

	IntegerExchangeFormat integerValue() const final override;

private:
	const Shared<Integer> m_lhs;
	const Shared<Integer> m_rhs;
};

Unique<IntegerSum> sum(
	Shared<Integer> _lhs,
	Shared<Integer> _rhs
);

}
