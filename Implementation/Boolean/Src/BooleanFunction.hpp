
#pragma once

#include "Boolean.hpp"
#include <functional>

namespace Lpp{

class BooleanFunction final : public Boolean{
public:
  BooleanFunction(std::function<bool(void)> _function);

  bool value() const final override;

private:
  const std::function<bool(void)> m_function;
};

}
