
#include "RealProduct.hpp"
#include "RealNumber.hpp"
#include "RealNumberOperations.hpp"

namespace Lpp{

namespace{

class RealNumberProduct final : public RealNumber {
public:
	RealNumberProduct(
		const Shared<const RealNumber> &_lhs,
		const Shared<const RealNumber> &_rhs
	);

	RealNumberExchangeFormat realValue() const final override;

private:
	const Shared<const RealNumber> m_lhs;
	const Shared<const RealNumber> m_rhs;
};

RealNumberProduct::RealNumberProduct(
	const Shared<const RealNumber> &_lhs,
	const Shared<const RealNumber> &_rhs
)
	: m_lhs(_lhs), m_rhs(_rhs)
{}

RealNumberExchangeFormat RealNumberProduct::realValue() const {
	return multiply(m_lhs->realValue(), m_rhs->realValue());
}

}

Unique<const RealNumber> realProduct(
	const Shared<const RealNumber> &_lhs,
	const Shared<const RealNumber> &_rhs
){
	return makeUnique<RealNumberProduct>(_lhs, _rhs);
}

}
