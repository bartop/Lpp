
#include "RealDifference.hpp"
#include "RealSum.hpp"
#include "RealNumber.hpp"
#include "RealNegation.hpp"

namespace Lpp{

Unique<const RealNumber> realDifference(
	const Shared<const RealNumber> &_lhs,
	const Shared<const RealNumber> &_rhs
){
	return realSum(
		_lhs,
		realNegation(_rhs)
	);
}

}
