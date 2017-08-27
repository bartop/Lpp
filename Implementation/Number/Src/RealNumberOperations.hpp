
#pragma once

#include "RealNumberExchangeFormat.hpp"
#include "Generic.hpp"
#include "../../Generic/Src/Ordinal.hpp"

namespace Lpp{


std::pair<
	RealNumberExchangeFormat,
	RealNumberExchangeFormat
> toCommonDenominator(
	const RealNumberExchangeFormat &_lhs,
	const RealNumberExchangeFormat &_rhs
);

ResultOfComparison compare(
	const RealNumberExchangeFormat &_lhs,
	const RealNumberExchangeFormat &_rhs
);

RealNumberExchangeFormat simplify(
	const RealNumberExchangeFormat &_realNumber
);

RealNumberExchangeFormat negate(
	const RealNumberExchangeFormat &_realNumber
);

bool equals(
	const RealNumberExchangeFormat &_lhs,
	const RealNumberExchangeFormat &_rhs
);

RealNumberExchangeFormat add(
	const RealNumberExchangeFormat &_lhs,
	const RealNumberExchangeFormat &_rhs
);

RealNumberExchangeFormat multiply(
	const RealNumberExchangeFormat &_lhs,
	const RealNumberExchangeFormat &_rhs
);

RealNumberExchangeFormat divide(
	const RealNumberExchangeFormat &_lhs,
	const RealNumberExchangeFormat &_rhs
);

}
