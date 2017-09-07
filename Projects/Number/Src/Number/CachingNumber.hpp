
#pragma once

#include "Config/Src/config.hpp"

namespace Lpp{

struct Number;

Unique<const Number> cache(
	const Shared<const Number> &_number
);

}
