
#pragma once

#include "defines.hpp"
#include <memory>

namespace Lpp{

template<typename T>
using Pointer = std::shared_ptr<T>;

template<typename... Args>
constexpr auto makePointer = std::make_shared<Args...>;

}
