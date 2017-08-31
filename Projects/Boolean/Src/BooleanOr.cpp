
#include "BooleanOr.hpp"

namespace Lpp{

namespace{

class BooleanOr final : public Boolean{
public:
	BooleanOr(
		Shared<const Boolean> _left,
		Shared<const Boolean> _right);

	bool value() const final override;

private:
	const Shared<const Boolean> m_left;
	const Shared<const Boolean> m_right;
};

}

Unique<Boolean> logicalOr(
	Shared<const Boolean> _left,
	Shared<const Boolean> _right){
	return std::make_unique<BooleanOr>(_left, _right);
}

BooleanOr::BooleanOr(
	Shared<const Boolean> _left,
	Shared<const Boolean> _right)
  : m_left(_left), m_right(_right){}

bool BooleanOr::value() const{
  return m_left->value() || m_right->value();
}

}
