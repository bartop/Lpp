
#pragma once

#include "Boolean.hpp"
#include <memory>

namespace Lpp{

std::unique_ptr<Boolean> logicalOr(
	Pointer<const Boolean> _left,
	Pointer<const Boolean> _right
);

}
