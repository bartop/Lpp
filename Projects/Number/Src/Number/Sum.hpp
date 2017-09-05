
#pragma once

#include "Config/Src/config.hpp"

namespace Lpp{

struct Number;

Unique<const Number> sum(
	const Shared<const Number> &_lhs,
	const Shared<const Number> &_rhs
);

}
