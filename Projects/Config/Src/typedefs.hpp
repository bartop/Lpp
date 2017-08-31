
#pragma once

#include "defines.hpp"
#include <memory>

namespace Lpp{

template<typename T>
using Shared = std::shared_ptr<T>;

template<typename T, typename... Args>
Shared<T> makeShared(Args&&... _args){
	return std::make_shared<T>(std::forward<Args>(_args)...);
}

template<typename T>
using Unique = std::unique_ptr<T>;

template<typename T, typename... Args>
Unique<T> makeUnique(Args&&... _args){
	return std::make_unique<T>(std::forward<Args>(_args)...);
}

}
