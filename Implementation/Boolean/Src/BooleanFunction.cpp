
#include "BooleanFunction.hpp"

namespace Lpp{

namespace{

class BooleanFunction final : public Boolean{
public:
  BooleanFunction(std::function<bool(void)> _function);

  bool value() const final override;

private:
  const std::function<bool(void)> m_function;
};

}

std::unique_ptr<Boolean> booleanFunction(
	std::function<bool(void)> _function
){
	return std::make_unique<BooleanFunction>(_function);
}

BooleanFunction::BooleanFunction(std::function<bool(void)> _function)
  : m_function(_function)
{}

bool BooleanFunction::value() const { return m_function(); }

}
