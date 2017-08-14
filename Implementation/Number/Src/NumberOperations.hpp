
#pragma once

#include "NumberExchangeFormat.hpp"
#include "Generic.hpp"

namespace Lpp{

bool equals(
	const NumberExchangeFormat &_lhs,
	const NumberExchangeFormat &_rhs
);

const NumberExchangeFormat add(
	const NumberExchangeFormat &_lhs,
	const NumberExchangeFormat &_rhs
);

const NumberExchangeFormat multiply(
	const NumberExchangeFormat &_lhs,
	const NumberExchangeFormat &_rhs
);

const NumberExchangeFormat divide(
	const NumberExchangeFormat &_lhs,
	const NumberExchangeFormat &_rhs
);

}
