
#include "Boolean.hpp"

namespace Lpp{

bool Boolean::equals(Shared<const Boolean> _boolean) const{
	return this->value() == _boolean->value();
}

}

