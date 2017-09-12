
#include "CachingInteger.hpp"
#include "Integer.hpp"
#include "IntegerOperations.hpp"

#include <boost/utility/in_place_factory.hpp>

namespace Lpp{

namespace{

class CachingInteger final : public Integer {
public:
	CachingInteger(const Shared<const Integer> &_integer);

	IntegerExchangeFormat integerValue() const final override;

private:
	const Shared<const Integer> m_integer;

	mutable Optional<IntegerExchangeFormat> m_cache;
};

CachingInteger::CachingInteger(const Shared<const Integer> &_integer)
	: m_integer(_integer), m_cache()
{}

IntegerExchangeFormat CachingInteger::integerValue() const {
	if (!m_cache.is_initialized())
		m_cache = boost::in_place(m_integer->integerValue());
	return *m_cache;
}

}

Unique<const Integer> cache(const Shared<const Integer> &_integer){
	return makeUnique<CachingInteger>(_integer);
}

}
