
#pragma once

#include "Config/Src/config.hpp"

namespace Lpp{

struct Integer;

Unique<const Integer> integerNegation(
	const Shared<const Integer> &_toNegate
);

}
