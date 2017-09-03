
#include "BooleanAnd.hpp"

namespace Lpp{

namespace{

class BooleanAnd final : public Boolean{
public:
	BooleanAnd(
		const Shared<const Boolean> &_left,
		const Shared<const Boolean> &_right
	);

	bool value() const final override;

private:
	const Shared<const Boolean> m_left;
	const Shared<const Boolean> m_right;
};

BooleanAnd::BooleanAnd(
	const Shared<const Boolean> &_left,
	const Shared<const Boolean> &_right
) : m_left(_left), m_right(_right)
{}

bool BooleanAnd::value() const {
  return m_left->value() && m_right->value();
}

}

Unique<const Boolean> logicalAnd(
	const Shared<const Boolean> &_left,
	const Shared<const Boolean> &_right
){
	return makeUnique<BooleanAnd>(_left, _right);
}

}
