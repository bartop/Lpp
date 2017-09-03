
#pragma once

#include "Boolean.hpp"

#include <memory>

namespace Lpp{

Unique<const Boolean> logicalNegation(
	const Shared<const Boolean> &_boolean
);

}
