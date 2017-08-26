

#define CATCH_CONFIG_MAIN
#include "../Src/IntegerOperations.hpp"

#include "../../Config/Src/config.hpp"

#include "../../3rdParty/Catch/include/catch.hpp"

using namespace Lpp;

TEST_CASE( "Comparisons tests for single numbers in integers", "[IntegerOperations.hpp]" ) {
	const auto zero1 = INTEGER_ZERO;
	const auto zero2 = INTEGER_ZERO;

	const auto one1 = INTEGER_ONE;
	const auto one2 = INTEGER_ONE;

	IntegerExchangeFormat minusOne1({static_cast<unsigned>(-1)});
	IntegerExchangeFormat minusOne2({static_cast<unsigned>(-1)});

	CHECK(equals(zero1, zero2));
	CHECK(equals(one1, one2));
	CHECK(equals(minusOne1, minusOne2));

	CHECK(!equals(zero1, one1));
	CHECK(!equals(zero1, minusOne1));
	CHECK(!equals(one1, minusOne1));

	CHECK(compare(zero1, one1) == ResultOfComparison::RightSideGreater);
	CHECK(compare(zero1, minusOne1) == ResultOfComparison::LeftSideGreater);
	CHECK(compare(one1, minusOne1) == ResultOfComparison::LeftSideGreater);

	CHECK(compare(one1, zero1) == ResultOfComparison::LeftSideGreater);
	CHECK(compare(minusOne1, zero1) == ResultOfComparison::RightSideGreater);
	CHECK(compare(minusOne1, one1) == ResultOfComparison::RightSideGreater);

	CHECK(compare(zero1, zero2) == ResultOfComparison::Equal);
	CHECK(compare(one1, one2) == ResultOfComparison::Equal);
	CHECK(compare(minusOne1, minusOne2) == ResultOfComparison::Equal);
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
