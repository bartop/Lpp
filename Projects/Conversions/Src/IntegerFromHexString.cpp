#include "IntegerFromHexString.hpp"

#include "Number/Src/Integer/Integer.hpp"

#include "String/Src/String.hpp"

namespace Lpp{

namespace{

class IntegerFromHex final : public Integer{
public:
	IntegerFromHex(const Shared<const String> &_string);

	IntegerExchangeFormat integerValue() const final override;

private:
	const Shared<const String> m_string;

	static IntegerExchangeFormat parseHex(
		StringExchangeFormat _string
	);

	static unsigned parseChunk(
		StringExchangeFormat &_string
	);
};

IntegerFromHex::IntegerFromHex(const Shared<const String> &_string)
	: m_string(_string){
}

IntegerExchangeFormat IntegerFromHex::integerValue() const {
	return parseHex(m_string->value());
}

IntegerExchangeFormat IntegerFromHex::parseHex(
	StringExchangeFormat _string
){
	std::deque<unsigned> integer;
	while(_string.length() > 0)
		integer.push_back(parseChunk(_string));

	return IntegerExchangeFormat(integer);
}

unsigned IntegerFromHex::parseChunk(
	StringExchangeFormat &_string
){
	if(_string.length() <= sizeof(unsigned) * 2)
		return static_cast<unsigned>(std::stoul(_string));
	else {
		const auto str = _string.substr(
			_string.length() - sizeof(unsigned) * 2 - 1,
			_string.length() - 1
		);
		_string.erase(
			_string.length() - sizeof(unsigned) * 2 - 1,
		   	sizeof(unsigned) * 2
		);
		return static_cast<unsigned>(std::stoul(str));
	}
}

}

Unique<const Integer> toInteger(const Shared<const String> &_string){
	return makeUnique<IntegerFromHex>(_string);
}

}
