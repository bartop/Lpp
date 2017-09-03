
#pragma once

#include "Boolean.hpp"
#include <memory>

namespace Lpp{

Unique<const Boolean> logicalAnd(
	const Shared<const Boolean> &_left,
	const Shared<const Boolean> &_right
);

}
