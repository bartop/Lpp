#pragma once

#include "Config/Src/config.hpp"

namespace Lpp{

struct Integer;

Unique<const Integer> integerDifference(
	const Shared<const Integer> &_lhs,
	const Shared<const Integer> &_rhs
);

}
