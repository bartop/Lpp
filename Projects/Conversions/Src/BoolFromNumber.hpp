
#include "Config/Src/config.hpp"

namespace Lpp{

struct Boolean;
struct Number;

Unique<const Boolean> toBool(const Shared<const Number> &_num);

}
