
#include "CachingBoolean.hpp"

namespace Lpp{

namespace{

class CachingBoolean final : public Boolean{
public:
	CachingBoolean(Pointer<const Boolean> _boolean);

	bool value() const final override;

private:
	Pointer<const Boolean> m_boolean;

	mutable bool m_cacheFilled;
	mutable bool m_cache;
};

}

std::unique_ptr<Boolean> booleanCache(
	Pointer<const Boolean> _boolean
){
	return std::make_unique<CachingBoolean>(_boolean);
}
CachingBoolean::CachingBoolean(Pointer<const Boolean> _boolean) :
	m_boolean(_boolean){}

bool CachingBoolean::value() const {
	if (m_cacheFilled){
		return m_cache;
	}
	else{
		m_cacheFilled = true;
		return m_cache = m_boolean->value();
	}
}

}
