

#define CATCH_CONFIG_MAIN
#include "../Src/IntegerOperations.hpp"

#include "../../Config/Src/config.hpp"

#include "../../3rdParty/Catch/include/catch.hpp"

using namespace Lpp;

TEST_CASE( "Comparisons tests", "[IntegerOperations.hpp]" ) {
	const auto zero = INTEGER_ZERO;
	const auto one = INTEGER_ONE;
	IntegerExchangeFormat minusOne({static_cast<unsigned>(-1)});

	CHECK(equals(zero, zero));
	CHECK(equals(one, one));
	CHECK(equals(minusOne, minusOne));

	CHECK(!equals(zero, one));
	CHECK(!equals(zero, minusOne));
	CHECK(!equals(one, minusOne));

	CHECK(compare(zero, one) == ResultOfComparison::RightSideGreater);
	CHECK(compare(zero, minusOne) == ResultOfComparison::LeftSideGreater);
	CHECK(compare(one, minusOne) == ResultOfComparison::LeftSideGreater);

	CHECK(compare(one, zero) == ResultOfComparison::LeftSideGreater);
	CHECK(compare(minusOne, zero) == ResultOfComparison::RightSideGreater);
	CHECK(compare(minusOne, one) == ResultOfComparison::RightSideGreater);

	CHECK(compare(zero, zero) == ResultOfComparison::Equal);
	CHECK(compare(one, one) == ResultOfComparison::Equal);
	CHECK(compare(minusOne, minusOne) == ResultOfComparison::Equal);

	IntegerExchangeFormat hundred({100});
	IntegerExchangeFormat bigNumber({1000, 1});
	IntegerExchangeFormat biggerNumber({1000, 2});
	IntegerExchangeFormat smallNumber({1000, static_cast<unsigned>(-1)});
	IntegerExchangeFormat hugeNumber({1000, 2, 1});

	CHECK(equals(hundred, hundred));
	CHECK(equals(bigNumber, bigNumber));
	CHECK(equals(biggerNumber, biggerNumber));
	CHECK(equals(hugeNumber, hugeNumber));
	CHECK(equals(smallNumber, smallNumber));

	CHECK(!equals(bigNumber, biggerNumber));
	CHECK(!equals(bigNumber, hundred));
	CHECK(!equals(bigNumber, smallNumber));

	CHECK(compare(bigNumber, biggerNumber) == ResultOfComparison::RightSideGreater);
	CHECK(compare(hugeNumber, smallNumber) == ResultOfComparison::LeftSideGreater);
	CHECK(compare(bigNumber, hundred) == ResultOfComparison::LeftSideGreater);
	CHECK(compare(hugeNumber, zero) == ResultOfComparison::LeftSideGreater);
	CHECK(compare(smallNumber, minusOne) == ResultOfComparison::RightSideGreater);
	CHECK(compare(smallNumber, bigNumber) == ResultOfComparison::RightSideGreater);
}

TEST_CASE( "Basic negation tests", "[IntegerOperations.hpp]" ) {
	const auto zero = INTEGER_ZERO;
	const auto one = INTEGER_ONE;
	IntegerExchangeFormat minusOne({static_cast<unsigned>(-1)});

	CHECK(equals(negate(one), minusOne));
	CHECK(equals(negate(zero), zero));
	CHECK(equals(negate(minusOne), one));
}

TEST_CASE( "Basic add tests", "[IntegerOperations.hpp]" ) {
	const auto zero = INTEGER_ZERO;
	const auto one = INTEGER_ONE;
	IntegerExchangeFormat minusOne({static_cast<unsigned>(-1)});

	CHECK(equals(add(one, minusOne), zero));
	CHECK(equals(add(one, zero), one));
	CHECK(equals(add(minusOne, zero), minusOne));

	CHECK(equals(add(one, minusOne), add(minusOne, one)));
}

TEST_CASE( "Basic multiplication tests", "[IntegerOperations.hpp]" ) {
	const auto zero = INTEGER_ZERO;
	const auto one = INTEGER_ONE;
	IntegerExchangeFormat minusOne({static_cast<unsigned>(-1)});

	CHECK(equals(multiply(one, minusOne), minusOne));
	CHECK(equals(multiply(one, zero), zero));
	CHECK(equals(multiply(minusOne, zero), zero));

	CHECK(equals(multiply(one, minusOne), multiply(minusOne, one)));
}

TEST_CASE( "Basic abs tests", "[IntegerOperations.hpp]" ) {
	const auto zero = INTEGER_ZERO;
	const auto one = INTEGER_ONE;
	IntegerExchangeFormat minusOne({static_cast<unsigned>(-1)});

	CHECK(equals(absoluteValue(one), one));
	CHECK(equals(absoluteValue(zero), zero));
	CHECK(equals(absoluteValue(minusOne), one));
}

TEST_CASE( "Basic division tests", "[IntegerOperations.hpp]" ) {
	const auto zero = INTEGER_ZERO;
	const auto one = INTEGER_ONE;
	IntegerExchangeFormat minusOne({static_cast<unsigned>(-1)});

	CHECK(equals(integerDivide(one, one).first, one));
	CHECK(equals(integerDivide(zero, one).first, zero));
	CHECK(equals(integerDivide(zero, minusOne).first, zero));
	CHECK(equals(integerDivide(one, minusOne).first, minusOne));
	CHECK(equals(integerDivide(minusOne, one).first, minusOne));
	CHECK(equals(integerDivide(minusOne, minusOne).first, one));

	CHECK(equals(integerDivide(one, one).second, zero));
	CHECK(equals(integerDivide(zero, one).second, zero));
	CHECK(equals(integerDivide(zero, minusOne).second, zero));
	CHECK(equals(integerDivide(one, minusOne).second, zero));
	CHECK(equals(integerDivide(minusOne, one).second, zero));
	CHECK(equals(integerDivide(one, minusOne).second, zero));
}

TEST_CASE( "Basic min/max tests", "[IntegerOperations.hpp]" ) {
	const auto zero = INTEGER_ZERO;
	const auto one = INTEGER_ONE;
	IntegerExchangeFormat minusOne({static_cast<unsigned>(-1)});

	CHECK(equals(max(minusOne, minusOne), minusOne));
	CHECK(equals(max(minusOne, zero), zero));
	CHECK(equals(max(minusOne, one), one));
	CHECK(equals(max(zero, minusOne), zero));
	CHECK(equals(max(zero, zero), zero));
	CHECK(equals(max(zero, one), one));
	CHECK(equals(max(one, minusOne), one));
	CHECK(equals(max(one, zero), one));
	CHECK(equals(max(one, one), one));

	CHECK(equals(min(minusOne, minusOne), minusOne));
	CHECK(equals(min(minusOne, zero), minusOne));
	CHECK(equals(min(minusOne, one), minusOne));
	CHECK(equals(min(zero, minusOne), minusOne));
	CHECK(equals(min(zero, zero), zero));
	CHECK(equals(min(zero, one), zero));
	CHECK(equals(min(one, minusOne), minusOne));
	CHECK(equals(min(one, zero), zero));
	CHECK(equals(min(one, one), one));
}
