
#include "BooleanFunction.hpp"
#include "../../Config/Src/config.hpp"

namespace Lpp{

namespace{

class BoolFunction final : public Boolean{
public:
  BoolFunction(std::function<bool(void)> _function);

  bool value() const final override;

private:
  const std::function<bool(void)> m_function;
};


BoolFunction::BoolFunction(std::function<bool(void)> _function)
  : m_function(_function)
{}


bool BoolFunction::value() const { return m_function(); }

class BooleanFunction final : public Boolean{
public:
  BooleanFunction(std::function<Shared<const Boolean>(void)> _function);

  bool value() const final override;

private:
  const std::function<Shared<const Boolean>(void)> m_function;
};

BooleanFunction::BooleanFunction(std::function<Shared<const Boolean>(void)> _function)
  : m_function(_function)
{}

bool BooleanFunction::value() const { return m_function()->value(); }

class UniqueBooleanFunction final : public Boolean{
public:
  UniqueBooleanFunction(std::function<Unique<const Boolean>(void)> _function);

  bool value() const final override;

private:
  const std::function<Unique<const Boolean>(void)> m_function;
};

UniqueBooleanFunction::UniqueBooleanFunction(
		std::function<Unique<const Boolean>(void)> _function
) : m_function(_function)
{}

bool UniqueBooleanFunction::value() const { return m_function()->value(); }

}

Unique<const Boolean> boolFunction(
	std::function<bool(void)> _function
){
	return makeUnique<BoolFunction>(_function);
}

Unique<const Boolean> sharedBooleanFunction(
	std::function<Shared<const Boolean>(void)> _function
){
	return makeUnique<const BooleanFunction>(_function);
}

Unique<const Boolean> uniqueBooleanFunction(
	std::function<Unique<const Boolean>(void)> _function
){
	return makeUnique<const UniqueBooleanFunction>(_function);
}

}
