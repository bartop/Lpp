
#pragma once

#include "IntegerExchangeFormat.hpp"
#include "Generic.hpp"

namespace Lpp{

struct IntegerExchangeFormat;

struct RealNumberExchangeFormat final{
	RealNumberExchangeFormat(
		const IntegerExchangeFormat &_numerator,
		const IntegerExchangeFormat &_denominator
	);


	const IntegerExchangeFormat numerator;
	const IntegerExchangeFormat denominator;
};

const RealNumberExchangeFormat REAL_ZERO =
	RealNumberExchangeFormat(INTEGER_ZERO,
		INTEGER_ONE
	);

}
