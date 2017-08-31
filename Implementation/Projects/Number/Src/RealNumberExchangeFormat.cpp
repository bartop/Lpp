
#include "RealNumberExchangeFormat.hpp"

namespace Lpp{

RealNumberExchangeFormat::RealNumberExchangeFormat(
		const IntegerExchangeFormat &_numerator,
		const IntegerExchangeFormat &_denominator
) : numerator(_numerator), denominator(_denominator){}


}

