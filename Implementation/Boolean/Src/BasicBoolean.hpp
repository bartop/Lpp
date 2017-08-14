
#pragma once

#include "Boolean.hpp"
#include <memory>

namespace Lpp{

std::unique_ptr<Boolean> boolean(bool _value);

class BasicBoolean final : public Boolean{
public:
  BasicBoolean(bool _value);

  bool value() const final override;

private:
  const bool m_value;
};

}
