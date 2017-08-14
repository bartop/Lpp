
#include "CachingBoolean.hpp"

namespace Lpp{

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
