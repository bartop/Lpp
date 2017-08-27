
#pragma once

#include "Generic.hpp"
#include "IntegerExchangeFormat.hpp"
#include "../../Generic/Src/Ordinal.hpp"


namespace Lpp{

bool equals(
	const IntegerExchangeFormat &_lhs,
	const IntegerExchangeFormat &_rhs
);

bool isNegative(
	const IntegerExchangeFormat &_number
);

ResultOfComparison compare(
	const IntegerExchangeFormat &_lhs,
	const IntegerExchangeFormat &_rhs
);

IntegerExchangeFormat negate(
	const IntegerExchangeFormat &_lhs
);

IntegerExchangeFormat absoluteValue(
	const IntegerExchangeFormat &_lhs
);

IntegerExchangeFormat add(
	const IntegerExchangeFormat &_lhs,
	const IntegerExchangeFormat &_rhs
);

IntegerExchangeFormat multiply(
	const IntegerExchangeFormat &_lhs,
	const IntegerExchangeFormat &_rhs
);

std::pair<const IntegerExchangeFormat,
	const IntegerExchangeFormat> integerDivide(
		const IntegerExchangeFormat &_lhs,
		const IntegerExchangeFormat &_rhs
);

IntegerExchangeFormat max(
	const IntegerExchangeFormat &_lhs,
	const IntegerExchangeFormat &_rhs
);

IntegerExchangeFormat min(
	const IntegerExchangeFormat &_lhs,
	const IntegerExchangeFormat &_rhs
);

IntegerExchangeFormat countGCD(
	const IntegerExchangeFormat &_lhs,
	const IntegerExchangeFormat &_rhs
);

IntegerExchangeFormat countLCM(
	const IntegerExchangeFormat &_lhs,
	const IntegerExchangeFormat &_rhs
);

}
