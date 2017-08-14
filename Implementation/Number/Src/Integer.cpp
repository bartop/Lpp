
#include "Integer.hpp"

namespace Lpp{

RealNumberExchangeFormat
Integer::realValue() const{
	return RealNumberExchangeFormat(
		integerValue(),
		INTEGER_ONE
	);
}

}
