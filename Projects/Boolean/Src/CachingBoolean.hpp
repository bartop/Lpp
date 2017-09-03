
#pragma once

#include "Boolean.hpp"

#include <memory>

namespace Lpp{

Unique<const Boolean> booleanCache(
	const Shared<const Boolean> &_boolean
);

}
