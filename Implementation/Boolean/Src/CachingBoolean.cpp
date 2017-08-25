
#include "CachingBoolean.hpp"
#include <optional>

namespace Lpp{

namespace{

class CachingBoolean final : public Boolean{
public:
	CachingBoolean(Shared<const Boolean> _boolean);

	bool value() const final override;

private:
	Shared<const Boolean> m_boolean;

	mutable std::optional<bool> m_cache;
};

CachingBoolean::CachingBoolean(Shared<const Boolean> _boolean) :
	m_boolean(_boolean), m_cache(){}

bool CachingBoolean::value() const {
	if (!m_cache.has_value())
		m_cache = m_boolean->value();
	return *m_cache;
}

}

Unique<Boolean> booleanCache(
	Shared<const Boolean> _boolean
){
	return std::make_unique<CachingBoolean>(_boolean);
}

}
