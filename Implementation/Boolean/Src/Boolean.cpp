
#include "Boolean.hpp"

namespace Lpp{

bool Boolean::equals(Pointer<const Boolean> _boolean) const{
	return this->value() == _boolean->value();
}

}

