

#include "Difference.hpp"
#include "Sum.hpp"
#include "Number.hpp"
#include "Negation.hpp"

namespace Lpp{

Unique<const Number> difference(
	const Shared<const Number> &_lhs,
	const Shared<const Number> &_rhs
){
	return sum(
		_lhs,
		negation(_rhs)
	);
}

}
