
#pragma once

#include "Boolean.hpp"
#include <memory>

namespace Lpp{

Unique<Boolean> logicalNegation(Shared<const Boolean> _boolean);

}
