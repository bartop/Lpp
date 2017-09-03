
#pragma once

#include "Config/Src/typedefs.hpp"

#include <deque>

namespace Lpp{

struct Integer;

Unique<Integer> bigInteger(
	const std::deque<unsigned> &_bigInteger
);

}
