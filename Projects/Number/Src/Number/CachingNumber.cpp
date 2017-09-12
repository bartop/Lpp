
#include "CachingNumber.hpp"
#include "Number.hpp"
#include "NumberOperations.hpp"

namespace Lpp{

namespace{

class CachingNumber final : public Number {
public:
	CachingNumber(const Shared<const Number> &_number);

	NumberExchangeFormat numberValue() const final override;

private:
	const Shared<const Number> m_number;

	mutable Optional<NumberExchangeFormat> m_cache;
};

CachingNumber::CachingNumber(const Shared<const Number> &_number)
	: m_number(_number), m_cache()
{}

NumberExchangeFormat CachingNumber::numberValue() const {
	if (!m_cache.is_initialized())
		m_cache.emplace(m_number->numberValue());
	return *m_cache;
}

}

Unique<const Number> cache(const Shared<const Number> &_number){
	return makeUnique<CachingNumber>(_number);
}

}
