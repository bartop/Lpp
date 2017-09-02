
#pragma once

#include "../Real/RealNumberExchangeFormat.hpp"

namespace Lpp{

struct NumberExchangeFormat final{
	NumberExchangeFormat(
		const RealNumberExchangeFormat &_realPart,
		const RealNumberExchangeFormat &_imaginaryPart
	);

	const RealNumberExchangeFormat realPart;
	const RealNumberExchangeFormat imaginaryPart;
};

}
