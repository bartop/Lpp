#pragma once

#include "Config/Src/typedefs.hpp"

namespace Lpp{

struct RealNumber;
struct Integer;

Unique<const Integer> toInteger(
	const Shared<const RealNumber> &_real
);

}
