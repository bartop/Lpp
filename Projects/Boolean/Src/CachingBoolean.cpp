
#include "CachingBoolean.hpp"

namespace Lpp{

namespace{

class CachingBoolean final : public Boolean{
public:
	CachingBoolean(const Shared<const Boolean> &_boolean);

	bool value() const final override;

private:
	Shared<const Boolean> m_boolean;

	mutable Optional<bool> m_cache;
};

CachingBoolean::CachingBoolean(
	const Shared<const Boolean> &_boolean
) : m_boolean(_boolean), m_cache()
{}

bool CachingBoolean::value() const {
	if (!m_cache.is_initialized())
		m_cache = m_boolean->value();
	return *m_cache;
}

}

Unique<const Boolean> booleanCache(
	const Shared<const Boolean> &_boolean
){
	return makeUnique<CachingBoolean>(_boolean);
}

}
