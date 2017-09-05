
#include "String.hpp"

namespace Lpp{

ResultOfComparison String::compare(
	const Shared<const String> &_valueObject
) const{
	if (value() == _valueObject->value())
		return ResultOfComparison::Equal;

	return value() > _valueObject->value() ?
		ResultOfComparison::LeftSideGreater :
		ResultOfComparison::RightSideGreater;
}

}
