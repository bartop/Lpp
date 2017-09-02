#pragma once

#include "../../Config/Src/typedefs.hpp"

namespace Lpp{

struct Integer;

Unique<Integer> integerSum(
	Shared<Integer> _lhs,
	Shared<Integer> _rhs
);

}
