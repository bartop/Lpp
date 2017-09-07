
#pragma once

#include "Config/Src/config.hpp"

namespace Lpp{

struct RealNumber;

Unique<const RealNumber> cache(
	const Shared<const RealNumber> &_real
);

}
