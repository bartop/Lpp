
#pragma once

#include "Generic/Src/ValueObject.hpp"

#include "Config/Src/config.hpp"

namespace Lpp{

class Boolean : public ValueObject<Boolean> {
public:
	bool equals(const Shared<const Boolean> &_boolean) const final override;

	virtual bool value() const = 0;
};

}
