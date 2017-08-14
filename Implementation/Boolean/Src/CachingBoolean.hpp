
#pragma once

#include "Boolean.hpp"
#include <memory>

namespace Lpp{

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
