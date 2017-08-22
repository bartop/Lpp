
#pragma once

#include "Boolean.hpp"
#include <functional>
#include <memory>

namespace Lpp{

std::unique_ptr<Boolean> booleanFunction(
	std::function<bool(void)> _function
);
}
