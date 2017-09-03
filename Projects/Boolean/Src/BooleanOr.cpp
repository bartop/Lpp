
#include "BooleanOr.hpp"

namespace Lpp{

namespace{

class BooleanOr final : public Boolean{
public:
	BooleanOr(
		const Shared<const Boolean> &_left,
		const Shared<const Boolean> &_right
	);

	bool value() const final override;

private:
	const Shared<const Boolean> m_left;
	const Shared<const Boolean> m_right;
};

BooleanOr::BooleanOr(
	const Shared<const Boolean> &_left,
	const Shared<const Boolean> &_right
) : m_left(_left), m_right(_right)
{}

bool BooleanOr::value() const{
  return m_left->value() || m_right->value();
}

}

Unique<const Boolean> logicalOr(
	const Shared<const Boolean> &_left,
	const Shared<const Boolean> &_right
){
	return makeUnique<BooleanOr>(_left, _right);
}

}
