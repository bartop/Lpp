
#pragma once

#include "Boolean.hpp"
#include <memory>

namespace Lpp{

std::unique_ptr<const Boolean> boolean(bool _value);

}
