
#include "BooleanNegation.hpp"

namespace Lpp{

namespace{

class BooleanNegation final : public Boolean{
public:
  BooleanNegation(Shared<const Boolean> _boolean);

  bool value() const final override;

private:
  const Shared<const Boolean> m_boolean;
};

}

Unique<Boolean> logicalNegation(Shared<const Boolean> _boolean){
	return std::make_unique<BooleanNegation>(_boolean);
}

BooleanNegation::BooleanNegation(Shared<const Boolean> _boolean)
  : m_boolean(_boolean){}

bool BooleanNegation::value() const{
  return !m_boolean->value();
}

}
