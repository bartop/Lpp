
#pragma once

#include "Config/Src/config.hpp"

namespace Lpp{

struct Integer;

Unique<const Integer> cache(
	const Shared<const Integer> &_integer
);

}
