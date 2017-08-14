
#include "Number.hpp"
#include "NumberOperations.hpp"

namespace Lpp{

bool Number::equals(
		std::shared_ptr<const Number> _number
) const{
	return Lpp::equals(this->numberValue(), _number->numberValue());
}

}
