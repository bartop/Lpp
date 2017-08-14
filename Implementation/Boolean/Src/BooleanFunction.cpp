
#include "BooleanFunction.hpp"

namespace Lpp{

BooleanFunction::BooleanFunction(std::function<bool(void)> _function)
  : m_function(_function)
{}

bool BooleanFunction::value() const { return m_function(); }

}
