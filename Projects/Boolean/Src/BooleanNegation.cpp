
#include "BooleanNegation.hpp"

namespace Lpp{

namespace{

class BooleanNegation final : public Boolean{
public:
	BooleanNegation(const Shared<const Boolean> &_boolean);

	bool value() const final override;

private:
	const Shared<const Boolean> m_boolean;
};

BooleanNegation::BooleanNegation(const Shared<const Boolean> &_boolean)
	: m_boolean(_boolean)
{}

bool BooleanNegation::value() const{
	return !m_boolean->value();
}

}

Unique<const Boolean> logicalNegation(
	const Shared<const Boolean> &_boolean
){
	return makeUnique<BooleanNegation>(_boolean);
}

}
