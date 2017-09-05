
#include "RealQuotient.hpp"
#include "RealNumber.hpp"
#include "RealNumberOperations.hpp"

namespace Lpp{

namespace{

class RealNumberQuotient final : public RealNumber {
public:
	RealNumberQuotient(
		const Shared<const RealNumber> &_lhs,
		const Shared<const RealNumber> &_rhs
	);

	RealNumberExchangeFormat realValue() const final override;

private:
	const Shared<const RealNumber> m_lhs;
	const Shared<const RealNumber> m_rhs;
};

RealNumberQuotient::RealNumberQuotient(
	const Shared<const RealNumber> &_lhs,
	const Shared<const RealNumber> &_rhs
)
	: m_lhs(_lhs), m_rhs(_rhs)
{}

RealNumberExchangeFormat RealNumberQuotient::realValue() const {
	return divide(m_lhs->realValue(), m_rhs->realValue());
}

}

Unique<const RealNumber> realQuotient(
	const Shared<const RealNumber> &_lhs,
	const Shared<const RealNumber> &_rhs
){
	return makeUnique<RealNumberQuotient>(_lhs, _rhs);
}

}
