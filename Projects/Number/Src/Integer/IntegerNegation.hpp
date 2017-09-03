
#pragma once

#include "Config/Src/typedefs.hpp"

namespace Lpp{

struct Integer;

Unique<Integer> integerNegation(
	Shared<Integer> _toNegate
);

}
