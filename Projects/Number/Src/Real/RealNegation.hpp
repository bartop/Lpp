
#pragma once

#include "Config/Src/config.hpp"

namespace Lpp{

struct RealNumber;

Unique<const RealNumber> realNegation(
	const Shared<const RealNumber> &_toNegate
);

}
