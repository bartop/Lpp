
#include "CachingInteger.hpp"
#include "Integer.hpp"
#include "IntegerOperations.hpp"

#include <optional>

namespace Lpp{

namespace{

class CachingInteger final : public Integer {
public:
	CachingInteger(const Shared<const Integer> &_integer);

	IntegerExchangeFormat integerValue() const final override;

private:
	const Shared<const Integer> m_integer;

	mutable std::optional<IntegerExchangeFormat> m_cache;
};

CachingInteger::CachingInteger(const Shared<const Integer> &_integer)
	: m_integer(_integer), m_cache()
{}

IntegerExchangeFormat CachingInteger::integerValue() const {
	if (!m_cache.has_value())
		m_cache.emplace(m_integer->integerValue());
	return *m_cache;
}

}

Unique<const Integer> cache(const Shared<const Integer> &_integer){
	return makeUnique<CachingInteger>(_integer);
}

}
