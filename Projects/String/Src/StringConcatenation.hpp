
#pragma once

#include "Config/Src/config.hpp"

namespace Lpp{

struct String;

Unique<String> concatenation(
	const Shared<const String> &_lhs,
	const Shared<const String> &_rhs
);


}
