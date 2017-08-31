
#include "NumberExchangeFormat.hpp"

namespace Lpp{

NumberExchangeFormat::NumberExchangeFormat(
	const RealNumberExchangeFormat &_realPart,
	const RealNumberExchangeFormat &_imaginaryPart
) : realPart(_realPart), imaginaryPart(_imaginaryPart){}

}

