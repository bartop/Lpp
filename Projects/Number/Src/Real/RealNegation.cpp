
#include "RealNegation.hpp"
#include "RealNumber.hpp"
#include "RealNumberOperations.hpp"

namespace Lpp{

namespace{

class RealNumberNegation final : public RealNumber {
public:
	RealNumberNegation(const Shared<const RealNumber> &_toNegate);

	RealNumberExchangeFormat realValue() const final override;

private:
	const Shared<const RealNumber> m_toNegate;
};

RealNumberNegation::RealNumberNegation(const Shared<const RealNumber> &_toNegate)
	: m_toNegate(_toNegate)
{}

RealNumberExchangeFormat RealNumberNegation::realValue() const {
	return negate(m_toNegate->realValue());
}

}

Unique<const RealNumber> realNegation(
	const Shared<RealNumber> &_toNegate
){
	return makeUnique<RealNumberNegation>(_toNegate);
}

}
