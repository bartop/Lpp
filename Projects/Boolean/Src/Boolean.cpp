
#include "Boolean.hpp"

namespace Lpp{

bool Boolean::equals(const Shared<const Boolean> &_boolean) const{
	return this->value() == _boolean->value();
}

}

