
#include "BooleanNegation.hpp"

namespace Lpp{

std::unique_ptr<Boolean> logicalNegation(Pointer<const Boolean> _boolean){
	return std::make_unique<BooleanNegation>(_boolean);
}

BooleanNegation::BooleanNegation(Pointer<const Boolean> _boolean)
  : m_boolean(_boolean){}

bool BooleanNegation::value() const{
  return !m_boolean->value();
}

}
