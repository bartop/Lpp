
#include "IntegerDifference.hpp"
#include "IntegerSum.hpp"
#include "Integer.hpp"
#include "IntegerNegation.hpp"

namespace Lpp{

Unique<const Integer> integerDifference(
	const Shared<const Integer> &_lhs,
	const Shared<const Integer> &_rhs
){
	return integerSum(
		_lhs,
		integerNegation(_rhs)
	);
}

}
