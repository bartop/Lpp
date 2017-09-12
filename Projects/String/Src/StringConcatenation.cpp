
#include "StringConcatenation.hpp"
#include "String.hpp"

namespace Lpp{

namespace{

class StringConcatenation : public String{
public:
	StringConcatenation(
		const Shared<const String> &_lhs,
		const Shared<const String> &_rhs
	);

	StringExchangeFormat value() const final override;

private:
	const Shared<const String> &m_left;
	const Shared<const String> &m_right;
};

StringConcatenation::StringConcatenation(
	const Shared<const String> &_lhs,
	const Shared<const String> &_rhs
)	: m_left(_lhs), m_right(_rhs)
{}

StringExchangeFormat StringConcatenation::value() const{
	return m_left->value() + m_right->value();
}

}

Unique<String> concatenation(
	const Shared<const String> &_lhs,
	const Shared<const String> &_rhs
){
	return makeUnique<StringConcatenation>(_lhs, _rhs);
}

}
