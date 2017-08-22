
#include "BooleanAnd.hpp"

namespace Lpp{

namespace{

class BooleanAnd final : public Boolean{
public:
	BooleanAnd(
		Pointer<const Boolean> _left, 
		Pointer<const Boolean> _right);

	bool value() const final override;

private:
	const Pointer<const Boolean> m_left;
	const Pointer<const Boolean> m_right;
};

}


std::unique_ptr<Boolean> logicalAnd(
	Pointer<const Boolean> _left,
	Pointer<const Boolean> _right){
	return std::make_unique<BooleanAnd>(_left, _right);
}

BooleanAnd::BooleanAnd(
	Pointer<const Boolean> _left,
	Pointer<const Boolean> _right)
  : m_left(_left), m_right(_right){}

bool BooleanAnd::value() const{
  return m_left->value() && m_right->value();
}

}
