

#include "IntegerNegation.hpp"
#include "Integer.hpp"
#include "IntegerOperations.hpp"

namespace Lpp{

namespace{

class IntegerNegation final : public Integer {
public:
	IntegerNegation(const Shared<const Integer> &_toNegate);

	IntegerExchangeFormat integerValue() const final override;

private:
	const Shared<const Integer> m_toNegate;
};

IntegerNegation::IntegerNegation(const Shared<const Integer> &_toNegate)
	: m_toNegate(_toNegate)
{}

IntegerExchangeFormat IntegerNegation::integerValue() const {
	return negate(m_toNegate->integerValue());
}

}

Unique<const Integer> integerNegation(
	const Shared<Integer> &_toNegate
){
	return makeUnique<IntegerNegation>(_toNegate);
}

}
