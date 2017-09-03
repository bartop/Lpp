
#pragma once

#include "Boolean.hpp"

#include <memory>

namespace Lpp{

Unique<const Boolean> logicalOr(
	const Shared<const Boolean> &_left,
	const Shared<const Boolean> &_right
);

}
