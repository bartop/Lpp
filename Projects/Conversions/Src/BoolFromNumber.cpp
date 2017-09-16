
#include "BoolFromNumber.hpp"

#include "Number/Src/Number/Number.hpp"
#include "Number/Src/Number/NumberOperations.hpp"

#include "Boolean/Src/Boolean.hpp"

namespace Lpp{

namespace{

class BoolFromNumber final : public Boolean{
public:
	BoolFromNumber(const Shared<const Number> &_num);

	bool value() const final override;

private:
	const Shared<const Number> m_number;
};

BoolFromNumber::BoolFromNumber(const Shared<const Number> &_num)
	: m_number(_num){
}

bool BoolFromNumber::value() const {
	return !Lpp::equals(m_number->numberValue(), NUMBER_ZERO);
}

}

Unique<const Boolean> toBool(const Shared<const Number> &_num){
	return makeUnique<BoolFromNumber>(_num);
}

}
