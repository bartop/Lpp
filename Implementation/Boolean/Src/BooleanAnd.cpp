
#include "BooleanAnd.hpp"

namespace Lpp{

namespace{

class BooleanAnd final : public Boolean{
public:
	BooleanAnd(
		Shared<const Boolean> _left, 
		Shared<const Boolean> _right);

	bool value() const final override;

private:
	const Shared<const Boolean> m_left;
	const Shared<const Boolean> m_right;
};

}


Unique<Boolean> logicalAnd(
	Shared<const Boolean> _left,
	Shared<const Boolean> _right){
	return std::make_unique<BooleanAnd>(_left, _right);
}

BooleanAnd::BooleanAnd(
	Shared<const Boolean> _left,
	Shared<const Boolean> _right)
  : m_left(_left), m_right(_right){}

bool BooleanAnd::value() const{
  return m_left->value() && m_right->value();
}

}
