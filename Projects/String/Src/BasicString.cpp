
#include "BasicString.hpp"
#include "String.hpp"

namespace Lpp{

namespace{

class BasicString : public String{
public:
	BasicString(const StringExchangeFormat &_string);

	StringExchangeFormat value() const final override;

private:
	const StringExchangeFormat m_string;
};

BasicString::BasicString(const StringExchangeFormat &_string)
	: m_string(_string)
{}

StringExchangeFormat BasicString::value() const{
	return m_string;
}

}

Unique<String> basicString(const StringExchangeFormat &_string){
	return makeUnique<BasicString>(_string);
}

}
