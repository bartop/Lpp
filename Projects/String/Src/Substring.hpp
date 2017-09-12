
#pragma once

#include "Config/Src/config.hpp"

namespace Lpp{

struct String;
struct Integer;

Unique<String> substring(
	const Shared<const String> &_string,
	const Shared<const Integer> &_startOfNewString
);


}
