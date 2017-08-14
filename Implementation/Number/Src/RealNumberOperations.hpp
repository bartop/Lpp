
#pragma once

#include "RealNumberExchangeFormat.hpp"
#include "Generic.hpp"
#include "../../Generic/Src/Ordinal.hpp"

namespace Lpp{


std::pair<
	const RealNumberExchangeFormat,
	const RealNumberExchangeFormat
> toCommonDenominator(
	const RealNumberExchangeFormat &_lhs,
	const RealNumberExchangeFormat &_rhs
);

ResultOfComparison compare(
	const RealNumberExchangeFormat &_lhs,
	const RealNumberExchangeFormat &_rhs
);

const RealNumberExchangeFormat simplify(
	const RealNumberExchangeFormat &_realNumber
);

const RealNumberExchangeFormat negate(
	const RealNumberExchangeFormat &_realNumber
);

bool equals(
	const RealNumberExchangeFormat &_lhs,
	const RealNumberExchangeFormat &_rhs
);

const RealNumberExchangeFormat add(
	const RealNumberExchangeFormat &_lhs,
	const RealNumberExchangeFormat &_rhs
);

const RealNumberExchangeFormat multiply(
	const RealNumberExchangeFormat &_lhs,
	const RealNumberExchangeFormat &_rhs
);

}
