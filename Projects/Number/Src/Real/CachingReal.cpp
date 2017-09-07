
#include "CachingReal.hpp"
#include "RealNumber.hpp"
#include "RealNumberOperations.hpp"

#include <optional>

namespace Lpp{

namespace{

class CachingRealNumber final : public RealNumber {
public:
	CachingRealNumber(const Shared<const RealNumber> &_real);

	RealNumberExchangeFormat realValue() const final override;

private:
	const Shared<const RealNumber> m_real;

	mutable std::optional<RealNumberExchangeFormat> m_cache;
};

CachingRealNumber::CachingRealNumber(const Shared<const RealNumber> &_real)
	: m_real(_real), m_cache()
{}

RealNumberExchangeFormat CachingRealNumber::realValue() const {
	if (!m_cache.has_value())
		m_cache.emplace(m_real->realValue());
	return *m_cache;
}

}

Unique<const RealNumber> cache(const Shared<const RealNumber> &_real){
	return makeUnique<CachingRealNumber>(_real);
}

}
