
#include "Number.hpp"
#include "NumberOperations.hpp"

namespace Lpp{

bool Number::equals(
	const Shared<const Number> &_number
) const{
	return Lpp::equals(this->numberValue(), _number->numberValue());
}

}
