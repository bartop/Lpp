
#pragma once

#include "Boolean.hpp"
#include <functional>
#include <memory>

namespace Lpp{

Unique<const Boolean> boolFunction(
	std::function<bool(void)> _function
);

Unique<const Boolean> sharedBooleanFunction(
	std::function<Shared<const Boolean>(void)> _function
);

Unique<const Boolean> uniqueBooleanFunction(
	std::function<Unique<const Boolean>(void)> _function
);

}
