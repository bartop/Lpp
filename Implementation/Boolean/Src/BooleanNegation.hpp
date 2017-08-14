
#pragma once

#include "Boolean.hpp"
#include <memory>

namespace Lpp{

std::unique_ptr<Boolean> logicalNegation(Pointer<const Boolean> _boolean);

class BooleanNegation final : public Boolean{
public:
  BooleanNegation(Pointer<const Boolean> _boolean);

  bool value() const final override;

private:
  const Pointer<const Boolean> m_boolean;
};

}
