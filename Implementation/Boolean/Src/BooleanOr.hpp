
#pragma once

#include "Boolean.hpp"
#include <memory>

namespace Lpp{

Unique<Boolean> logicalOr(
	Shared<const Boolean> _left,
	Shared<const Boolean> _right
);

}
