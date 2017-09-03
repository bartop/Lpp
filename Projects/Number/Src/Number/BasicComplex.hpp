
#pragma once

#include "Config/Src/typedefs.hpp"

namespace Lpp{

struct Number;
struct RealNumber;

Unique<Number> basicComplex(
	Shared<const RealNumber> _realPart,
	Shared<const RealNumber> _imaginaryPart
);

}
