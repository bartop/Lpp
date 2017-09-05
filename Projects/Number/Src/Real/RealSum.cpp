
#include "RealSum.hpp"
#include "RealNumber.hpp"
#include "RealNumberOperations.hpp"

namespace Lpp{

namespace{

class RealNumberSum final : public RealNumber {
public:
	RealNumberSum(
		const Shared<const RealNumber> &_lhs,
		const Shared<const RealNumber> &_rhs
	);

	RealNumberExchangeFormat realValue() const final override;

private:
	const Shared<const RealNumber> m_lhs;
	const Shared<const RealNumber> m_rhs;
};

RealNumberSum::RealNumberSum(
	const Shared<const RealNumber> &_lhs,
	const Shared<const RealNumber> &_rhs
)
	: m_lhs(_lhs), m_rhs(_rhs)
{}

RealNumberExchangeFormat RealNumberSum::realValue() const {
	return add(m_lhs->realValue(), m_rhs->realValue());
}

}

Unique<const RealNumber> realSum(
	const Shared<const RealNumber> &_lhs,
	const Shared<const RealNumber> &_rhs
){
	return makeUnique<RealNumberSum>(_lhs, _rhs);
}

}
