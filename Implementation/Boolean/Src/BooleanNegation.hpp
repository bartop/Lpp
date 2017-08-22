
#pragma once

#include "Boolean.hpp"
#include <memory>

namespace Lpp{

std::unique_ptr<Boolean> logicalNegation(Pointer<const Boolean> _boolean);

}
