
#pragma once

#include <memory>
#include <vector>

namespace Lpp{

struct IntegerExchangeFormat final{
	IntegerExchangeFormat(
		const std::vector<unsigned> &_longInteger
	) noexcept;

	const std::vector<unsigned> longInteger;
};

const IntegerExchangeFormat INTEGER_ZERO =
		IntegerExchangeFormat({0});
const IntegerExchangeFormat INTEGER_ONE =
		IntegerExchangeFormat({1});

}
