
#include "BooleanOr.hpp"

namespace Lpp{

std::unique_ptr<Boolean> logicalOr(
	Pointer<const Boolean> _left,
	Pointer<const Boolean> _right){
	return std::make_unique<BooleanOr>(_left, _right);
}

BooleanOr::BooleanOr(
	Pointer<const Boolean> _left,
	Pointer<const Boolean> _right)
  : m_left(_left), m_right(_right){}

bool BooleanOr::value() const{
  return m_left->value() || m_right->value();
}

}
