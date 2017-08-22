
#include "BooleanNegation.hpp"

namespace Lpp{

namespace{

class BooleanNegation final : public Boolean{
public:
  BooleanNegation(Pointer<const Boolean> _boolean);

  bool value() const final override;

private:
  const Pointer<const Boolean> m_boolean;
};

}

std::unique_ptr<Boolean> logicalNegation(Pointer<const Boolean> _boolean){
	return std::make_unique<BooleanNegation>(_boolean);
}

BooleanNegation::BooleanNegation(Pointer<const Boolean> _boolean)
  : m_boolean(_boolean){}

bool BooleanNegation::value() const{
  return !m_boolean->value();
}

}
