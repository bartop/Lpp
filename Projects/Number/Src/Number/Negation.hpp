
#pragma once

#include "Config/Src/config.hpp"

namespace Lpp{

struct Number;

Unique<const Number> negation(
	const Shared<const Number> &_toNegate
);

}
