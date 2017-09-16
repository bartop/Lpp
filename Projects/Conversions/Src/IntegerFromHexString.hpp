

#include "Config/Src/config.hpp"

namespace Lpp{

struct Integer;
struct String;

Unique<const Integer> toInteger(const Shared<const String> &_string);

}
