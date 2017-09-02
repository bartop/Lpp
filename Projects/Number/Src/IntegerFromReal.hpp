#pragma once

#include "../../Config/Src/typedefs.hpp"

namespace Lpp{

struct RealNumber;
struct Integer;

Unique<Integer> toInteger(
	Shared<RealNumber> _real
);

}
