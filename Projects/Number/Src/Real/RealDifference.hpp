
#pragma once

#include "Config/Src/config.hpp"

namespace Lpp{

struct RealNumber;

Unique<const RealNumber> realDifference(
	const Shared<const RealNumber> &_lhs,
	const Shared<const RealNumber> &_rhs
);

}
