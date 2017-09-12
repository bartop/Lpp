

#include "Substring.hpp"
#include "String.hpp"

#include "Number/Src/Integer/Integer.hpp"

namespace Lpp{

namespace{

class Substring : public String{
public:
	Substring(
		const Shared<const String> &_string,
		const Shared<const Integer> &_startOfNewString
	);

	StringExchangeFormat value() const final override;

private:
	const Shared<const String> &m_string;
	const Shared<const Integer> &m_substringStartPosition;
};

Substring::Substring(
	const Shared<const String> &_string,
	const Shared<const Integer> &_startOfNewString
)	: m_string(_string), m_substringStartPosition(_startOfNewString)
{}

StringExchangeFormat Substring::value() const{
	//TODO: String should be indexed with Integer, not with
	//oldschool int or size_t
	return m_string->value().substr(m_substringStartPosition->integerValue().longInteger[0]);
}

}

Unique<String> concatenation(
	const Shared<const String> &_string,
	const Shared<const Integer> &_startOfNewString
){
	return makeUnique<Substring>(_string, _startOfNewString);
}

}
