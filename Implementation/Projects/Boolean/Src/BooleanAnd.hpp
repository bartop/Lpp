
#pragma once

#include "Boolean.hpp"
#include <memory>

namespace Lpp{

Unique<Boolean> logicalAnd(
	Shared<const Boolean> _left,
	Shared<const Boolean> _right
);

}
