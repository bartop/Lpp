
#include "Negation.hpp"
#include "Number.hpp"
#include "NumberOperations.hpp"

namespace Lpp{

namespace{

class NumberNegation final : public Number {
public:
	NumberNegation(const Shared<const Number> &_toNegate);

	NumberExchangeFormat numberValue() const final override;

private:
	const Shared<const Number> m_toNegate;
};

NumberNegation::NumberNegation(const Shared<const Number> &_toNegate)
	: m_toNegate(_toNegate)
{}

NumberExchangeFormat NumberNegation::numberValue() const {
	return negate(m_toNegate->numberValue());
}

}

Unique<const Number> negation(
	const Shared<Number> &_toNegate
){
	return makeUnique<NumberNegation>(_toNegate);
}

}
