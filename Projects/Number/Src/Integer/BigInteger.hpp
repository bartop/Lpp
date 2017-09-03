
#pragma once

#include "Config/Src/config.hpp"

#include <deque>

namespace Lpp{

struct Integer;

Unique<const Integer> bigInteger(
	const std::deque<unsigned> &_bigInteger
);

}
