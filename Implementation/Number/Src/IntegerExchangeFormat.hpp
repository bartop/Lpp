
#pragma once

#include <memory>
#include <deque>

namespace Lpp{

struct IntegerExchangeFormat final{
	IntegerExchangeFormat(
		const std::deque<unsigned> &_longInteger
	) noexcept;

	const std::deque<unsigned> longInteger;
};

const IntegerExchangeFormat INTEGER_ZERO =
		IntegerExchangeFormat({0});
const IntegerExchangeFormat INTEGER_ONE =
		IntegerExchangeFormat({1});

}
