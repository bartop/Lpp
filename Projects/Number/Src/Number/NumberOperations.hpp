
#pragma once

#include "NumberExchangeFormat.hpp"

#include "../Generic.hpp"

namespace Lpp{

bool equals(
	const NumberExchangeFormat &_lhs,
	const NumberExchangeFormat &_rhs
);

NumberExchangeFormat negate(
	const NumberExchangeFormat &_number
);

NumberExchangeFormat add(
	const NumberExchangeFormat &_lhs,
	const NumberExchangeFormat &_rhs
);

NumberExchangeFormat multiply(
	const NumberExchangeFormat &_lhs,
	const NumberExchangeFormat &_rhs
);

NumberExchangeFormat divide(
	const NumberExchangeFormat &_lhs,
	const NumberExchangeFormat &_rhs
);

}
