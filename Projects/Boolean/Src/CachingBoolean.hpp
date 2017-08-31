
#pragma once

#include "Boolean.hpp"
#include <memory>

namespace Lpp{

Unique<Boolean> booleanCache(
	Shared<const Boolean> _boolean
);

}
