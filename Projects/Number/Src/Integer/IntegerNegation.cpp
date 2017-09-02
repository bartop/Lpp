

#include "IntegerNegation.hpp"
#include "Integer.hpp"
#include "IntegerOperations.hpp"

namespace Lpp{

namespace{

class IntegerNegation final : public Integer {
public:
	IntegerNegation(Shared<Integer> _toNegate);

	IntegerExchangeFormat integerValue() const final override;

private:
	const Shared<Integer> m_toNegate;
};

IntegerNegation::IntegerNegation(Shared<Integer> _toNegate)
	: m_toNegate(_toNegate)
{}

IntegerExchangeFormat IntegerNegation::integerValue() const {
	return negate(m_toNegate->integerValue());
}

}

Unique<Integer> integerNegation(
	Shared<Integer> _toNegate
){
	return makeUnique<IntegerNegation>(_toNegate);
}

}
