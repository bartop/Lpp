

#define CATCH_CONFIG_MAIN
#include "../Src/Integer/IntegerOperations.hpp"

#include "../../Config/Src/config.hpp"

#include <catch.hpp>

using namespace Lpp;

TEST_CASE( "IntegerOperations tests", "[IntegerOperations.hpp]" ) {
	const auto zero = INTEGER_ZERO;
	const auto one = INTEGER_ONE;
	const IntegerExchangeFormat minusOne({static_cast<unsigned>(-1)});

	const IntegerExchangeFormat hundred({100});
	const IntegerExchangeFormat bigNumber({1024, 1});
	const IntegerExchangeFormat biggerNumber({1024, 2});
	const IntegerExchangeFormat minusBigNumber({0xFFFFFC00, 0xFFFFFFFE});

	SECTION("Comparisons test") {
		const IntegerExchangeFormat hugeNumber({1000, 2, 1});
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

		CHECK(equals(hundred, hundred));
		CHECK(equals(bigNumber, bigNumber));
		CHECK(equals(biggerNumber, biggerNumber));
		CHECK(equals(hugeNumber, hugeNumber));
		CHECK(equals(minusBigNumber, minusBigNumber));

		CHECK(!equals(bigNumber, biggerNumber));
		CHECK(!equals(bigNumber, hundred));
		CHECK(!equals(bigNumber, minusBigNumber));

		CHECK(compare(bigNumber, biggerNumber) == ResultOfComparison::RightSideGreater);
		CHECK(compare(hugeNumber, minusBigNumber) == ResultOfComparison::LeftSideGreater);
		CHECK(compare(bigNumber, hundred) == ResultOfComparison::LeftSideGreater);
		CHECK(compare(hugeNumber, zero) == ResultOfComparison::LeftSideGreater);
		CHECK(compare(minusBigNumber, minusOne) == ResultOfComparison::RightSideGreater);
		CHECK(compare(minusBigNumber, bigNumber) == ResultOfComparison::RightSideGreater);
	}

	SECTION("Sign tests") {
		CHECK(!isNegative(one));
		CHECK(!isNegative(zero));
		CHECK(isNegative(minusOne));
		CHECK(!isNegative(bigNumber));
		CHECK(!isNegative(biggerNumber));
	}

	SECTION("Negation tests") {
		IntegerExchangeFormat smallerNumber({0xFFFFFC00, 0xFFFFFFFD});
		CHECK(equals(negate(one), minusOne));
		CHECK(equals(negate(zero), zero));
		CHECK(equals(negate(minusOne), one));
		CHECK(equals(negate(bigNumber), minusBigNumber));
		CHECK(equals(negate(biggerNumber), smallerNumber));
	}

	SECTION("Add tests") {
		CHECK(equals(add(one, minusOne), zero));
		CHECK(equals(add(one, zero), one));
		CHECK(equals(add(minusOne, zero), minusOne));
		CHECK(equals(add(bigNumber, minusBigNumber), zero));
		CHECK(equals(add(bigNumber, bigNumber), IntegerExchangeFormat({2048, 2})));
		CHECK(equals(add(biggerNumber, bigNumber), IntegerExchangeFormat({2048, 3})));
		CHECK(equals(add(minusBigNumber, minusBigNumber), IntegerExchangeFormat({0xFFFFF800, 0xFFFFFFFD})));
		CHECK(equals(add(biggerNumber, minusBigNumber), IntegerExchangeFormat({0, 1})));
		CHECK(equals(add(hundred, minusBigNumber), IntegerExchangeFormat({0xFFFFFC64, 0xFFFFFFFE})));

		CHECK(equals(add(one, minusOne), add(minusOne, one)));
		CHECK(equals(add(bigNumber, biggerNumber), add(biggerNumber, bigNumber)));

		//<TODO type="tests" severity="high" reason="Add more tests in this category or even generate ones in python or so" />
	}

	SECTION("Subtract tests") {
		CHECK(equals(subtract(one, minusOne), add(one, one)));
		CHECK(equals(subtract(one, zero), one));
		CHECK(equals(subtract(minusOne, zero), minusOne));
		CHECK(equals(subtract(bigNumber, minusBigNumber), add(bigNumber, bigNumber)));
		CHECK(equals(subtract(bigNumber, bigNumber), zero));
		CHECK(equals(subtract(biggerNumber, bigNumber), IntegerExchangeFormat({0, 1})));
		CHECK(equals(subtract(minusBigNumber, minusBigNumber), IntegerExchangeFormat({0})));
		CHECK(equals(subtract(biggerNumber, minusBigNumber), IntegerExchangeFormat({2048, 3})));
		CHECK(equals(subtract(hundred, minusBigNumber), IntegerExchangeFormat({1124, 1})));

		//<TODO type="tests" severity="high" reason="Add more tests in this category or even generate ones in python or so" />
	}

	SECTION("Multiplication tests") {
		const IntegerExchangeFormat three({3});
		const auto minusThreeTimesBigNum(add(minusBigNumber, add(minusBigNumber, minusBigNumber)));
		const auto threeTimesBigNum(add(bigNumber, add(bigNumber, bigNumber)));
		CHECK(equals(multiply(one, minusOne), minusOne));
		CHECK(equals(multiply(one, zero), zero));
		CHECK(equals(multiply(minusOne, zero), zero));
		CHECK(equals(multiply(minusOne, bigNumber), minusBigNumber));
		CHECK(equals(multiply(bigNumber, negate(three)), minusThreeTimesBigNum));
		CHECK(equals(multiply(bigNumber, zero), zero));
		CHECK(equals(multiply(bigNumber, three), threeTimesBigNum));

		CHECK(equals(multiply(one, minusOne), multiply(minusOne, one)));
		CHECK(equals(multiply(bigNumber, negate(three)), multiply(negate(three), bigNumber)));
		CHECK(equals(multiply(bigNumber, three), multiply(three, bigNumber)));
		CHECK(equals(multiply(minusOne, bigNumber), multiply(bigNumber, minusOne)));

		//<TODO type="tests" severity="high" reason="Add more tests in this category or even generate ones in python or so" />
	}

	SECTION("Abs tests") {
		CHECK(equals(absoluteValue(one), one));
		CHECK(equals(absoluteValue(zero), zero));
		CHECK(equals(absoluteValue(minusOne), one));
		CHECK(equals(absoluteValue(minusBigNumber), bigNumber));
	}

	SECTION("Division tests") {
		const IntegerExchangeFormat two({2});
		const IntegerExchangeFormat three({3});
		const IntegerExchangeFormat ten({10});
		const IntegerExchangeFormat bigNumPlusTen(add(ten, bigNumber));
		const IntegerExchangeFormat smallNumPlusTen(add(ten, minusBigNumber));
		const auto minusThreeTimesBigNum(add(minusBigNumber, add(minusBigNumber, minusBigNumber)));
		const auto threeTimesBigNum(add(bigNumber, add(bigNumber, bigNumber)));
		const auto minusThreeTimesBigNumPlusThree(add(minusThreeTimesBigNum, three));

		CHECK(equals(integerDivide(one, one).first, one));
		CHECK(equals(integerDivide(zero, one).first, zero));
		CHECK(equals(integerDivide(zero, minusOne).first, zero));
		CHECK(equals(integerDivide(one, minusOne).first, minusOne));
		CHECK(equals(integerDivide(minusOne, one).first, minusOne));
		CHECK(equals(integerDivide(minusOne, minusOne).first, one));
		CHECK(equals(integerDivide(bigNumber, bigNumber).first, one));
		CHECK(equals(integerDivide(zero, bigNumber).first, zero));
		CHECK(equals(integerDivide(bigNumber, minusBigNumber).first, minusOne));
		CHECK(equals(integerDivide(bigNumPlusTen, bigNumber).first, one));
		CHECK(equals(integerDivide(smallNumPlusTen, bigNumber).first, zero));
		CHECK(equals(integerDivide(threeTimesBigNum, bigNumber).first, three));
		CHECK(equals(integerDivide(minusThreeTimesBigNumPlusThree, bigNumber).first, negate(two)));
		CHECK(equals(integerDivide(threeTimesBigNum, negate(three)).first, negate(bigNumber)));
		CHECK(equals(integerDivide(bigNumber, one).first, bigNumber));

		CHECK(equals(integerDivide(one, one).second, zero));
		CHECK(equals(integerDivide(zero, one).second, zero));
		CHECK(equals(integerDivide(zero, minusOne).second, zero));
		CHECK(equals(integerDivide(one, minusOne).second, zero));
		CHECK(equals(integerDivide(minusOne, one).second, zero));
		CHECK(equals(integerDivide(one, minusOne).second, zero));
		CHECK(equals(integerDivide(bigNumber, bigNumber).second, zero));
		CHECK(equals(integerDivide(zero, bigNumber).second, zero));
		CHECK(equals(integerDivide(bigNumber, minusBigNumber).second, zero));
		CHECK(equals(integerDivide(bigNumPlusTen, bigNumber).second, ten));
		CHECK(equals(integerDivide(smallNumPlusTen, bigNumber).second, smallNumPlusTen));
		CHECK(equals(integerDivide(threeTimesBigNum, bigNumber).second, zero));
		CHECK(equals(integerDivide(minusThreeTimesBigNumPlusThree, bigNumber).second, add(minusBigNumber, three)));
		CHECK(equals(integerDivide(threeTimesBigNum, negate(three)).second, zero));
		CHECK(equals(integerDivide(bigNumber, one).second, zero));
		//<TODO type="tests" severity="high" reason="Add more tests in this category or even generate ones in python or so" />
	}

	SECTION("Min/max tests") {
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

	SECTION("GCD tests") {
		CHECK(
			equals(
				countGCD(
					IntegerExchangeFormat({4}),
					IntegerExchangeFormat({8})
				),
				IntegerExchangeFormat({4})
			)
		);
		CHECK(
			equals(
				countGCD(
					IntegerExchangeFormat({4}),
					negate(IntegerExchangeFormat({8}))
				),
				IntegerExchangeFormat({4})
			)
		);
		CHECK(
			equals(
				countGCD(
					negate(IntegerExchangeFormat({4})),
					IntegerExchangeFormat({8})
				),
				IntegerExchangeFormat({4})
			)
		);
		CHECK(
			equals(
				countGCD(
					negate(IntegerExchangeFormat({4})),
					negate(IntegerExchangeFormat({8}))
				),
				IntegerExchangeFormat({4})
			)
		);
		CHECK(
			equals(
				countGCD(
					IntegerExchangeFormat({7}),
					IntegerExchangeFormat({22})
				),
				IntegerExchangeFormat({1})
			)
		);
		CHECK(
			equals(
				countGCD(
					IntegerExchangeFormat({15}),
					IntegerExchangeFormat({25})
				),
				IntegerExchangeFormat({5})
			)
		);
		CHECK(
			equals(
				countGCD(
					IntegerExchangeFormat({5}),
					IntegerExchangeFormat({3})
				),
				IntegerExchangeFormat({1})
			)
		);
	}

	SECTION("LCM tests") {
		CHECK(
			equals(
				countLCM(
					IntegerExchangeFormat({4}),
					IntegerExchangeFormat({8})
				),
				IntegerExchangeFormat({8})
			)
		);
		//<TODO type="convention" severity="minor" reason="Should LCM ever return negative value?">
		CHECK(
			equals(
				countLCM(
					IntegerExchangeFormat({4}),
					negate(IntegerExchangeFormat({8}))
				),
				negate(IntegerExchangeFormat({8}))
			)
		);
		CHECK(
			equals(
				countLCM(
					negate(IntegerExchangeFormat({4})),
					IntegerExchangeFormat({8})
				),
				negate(IntegerExchangeFormat({8}))
			)
		);
		//</TODO>
		CHECK(
			equals(
				countLCM(
					negate(IntegerExchangeFormat({4})),
					negate(IntegerExchangeFormat({8}))
				),
				IntegerExchangeFormat({8})
			)
		);
		CHECK(
			equals(
				countLCM(
					IntegerExchangeFormat({7}),
					IntegerExchangeFormat({22})
				),
				IntegerExchangeFormat({154})
			)
		);
		CHECK(
			equals(
				countLCM(
					IntegerExchangeFormat({15}),
					IntegerExchangeFormat({25})
				),
				IntegerExchangeFormat({75})
			)
		);
		CHECK(
			equals(
				countLCM(
					IntegerExchangeFormat({5}),
					IntegerExchangeFormat({3})
				),
				IntegerExchangeFormat({15})
			)
		);
	}
}


