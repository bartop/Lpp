
#define CATCH_CONFIG_MAIN

#include "../Src/BasicInt.hpp"
#include "../Src/IntegerOperations.hpp"
#include "../Src/Integer.hpp"

#include <limits>
#include <catch.hpp>

using namespace Lpp;

TEST_CASE( "BasicInt tests", "[BasicInt.hpp]" ) {
	const auto one = basicInt(1);
	const auto minusOne = basicInt(-1);
	const auto zero = basicInt(0);
	const auto maxInt = basicInt(std::numeric_limits<int>::max());
	const auto minInt = basicInt(std::numeric_limits<int>::min());

	CHECK(equals(one->integerValue(), IntegerExchangeFormat({1})));
	CHECK(equals(zero->integerValue(), IntegerExchangeFormat({0})));
	CHECK(equals(minusOne->integerValue(), IntegerExchangeFormat({0xFFFFFFFF})));
	CHECK(equals(maxInt->integerValue(), IntegerExchangeFormat({0x7FFFFFFF})));
	CHECK(equals(minInt->integerValue(), IntegerExchangeFormat({0x80000000})));
}
