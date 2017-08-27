
#define CATCH_CONFIG_MAIN

#include "../Src/RealNumberOperations.hpp"
#include "../Src/IntegerOperations.hpp"

#include "../../Config/Src/config.hpp"

#include "../../3rdParty/Catch/include/catch.hpp"

using namespace Lpp;

TEST_CASE( "RealNumberOperations tests", "[RealNumberOperations.hpp]" ) {
	const IntegerExchangeFormat one({1});
	const IntegerExchangeFormat two({2});
	const IntegerExchangeFormat four({4});
	const IntegerExchangeFormat five({5});
	const IntegerExchangeFormat six({6});
	const IntegerExchangeFormat twelve({12});

	const RealNumberExchangeFormat half(one, two);
	const RealNumberExchangeFormat twoTwelths(two, twelve);
	const RealNumberExchangeFormat fourFourths(four, four);
	const RealNumberExchangeFormat fourFifths(four, five);
	const RealNumberExchangeFormat fourSixths(four, six);
	const RealNumberExchangeFormat fourTwelths(four, twelve);
	const RealNumberExchangeFormat fiveFourths(five, four);
	const RealNumberExchangeFormat fiveFifths(five, five);
	const RealNumberExchangeFormat fiveSixths(five, six);
	const RealNumberExchangeFormat fiveTwelths(five, twelve);
	const RealNumberExchangeFormat sixFourths(six, four);
	const RealNumberExchangeFormat sixFifths(six, five);
	const RealNumberExchangeFormat sixSixths(six, six);
	const RealNumberExchangeFormat sixTwelths(six, twelve);
	const RealNumberExchangeFormat twelveFourths(twelve, four);
	const RealNumberExchangeFormat twelveFifths(twelve, five);
	const RealNumberExchangeFormat twelveSixths(twelve, six);
	const RealNumberExchangeFormat twelveTwelths(twelve, twelve);

	SECTION("Comparisions tests"){
		CHECK(equals(fourFourths, fiveFifths));
		CHECK(equals(fiveFifths, sixSixths));
		CHECK(equals(sixSixths, twelveTwelths));

		CHECK(compare(fourFifths, fiveFourths) == ResultOfComparison::RightSideGreater);
		CHECK(compare(fourFifths, twelveFifths) == ResultOfComparison::RightSideGreater);
		CHECK(compare(fourFifths, fiveFifths) == ResultOfComparison::RightSideGreater);
		CHECK(compare(fourFifths, fourSixths) == ResultOfComparison::LeftSideGreater);
		CHECK(compare(sixFifths, fourSixths) == ResultOfComparison::LeftSideGreater);
		CHECK(compare(fourTwelths, fiveSixths) == ResultOfComparison::RightSideGreater);
		CHECK(
			equals(
				RealNumberExchangeFormat(
					negate(IntegerExchangeFormat({61})),
					IntegerExchangeFormat({30})
				),
				RealNumberExchangeFormat(
					IntegerExchangeFormat({61}),
					negate(IntegerExchangeFormat({30}))
				)
			)
		);
	}

	SECTION("Sign tests"){
		CHECK(!isNegative(fiveFifths));
		CHECK(!isNegative(half));
		CHECK(isNegative(negate(fourTwelths)));
		CHECK(
			!isNegative(
				RealNumberExchangeFormat(
					negate(IntegerExchangeFormat({61})),
					negate(IntegerExchangeFormat({30}))
				)
			)
		);
		CHECK(
			isNegative(
				RealNumberExchangeFormat(
					IntegerExchangeFormat({61}),
					negate(IntegerExchangeFormat({30}))
				)
			)
		);
		CHECK(
			isNegative(
				RealNumberExchangeFormat(
					negate(IntegerExchangeFormat({61})),
					IntegerExchangeFormat({30})
				)
			)
		);
	}

	SECTION("Addition tests"){
		CHECK(equals(add(fourTwelths, fourTwelths), fourSixths));
		CHECK(equals(add(negate(fourTwelths), negate(fourTwelths)), negate(fourSixths)));
		CHECK(equals(add(fiveTwelths, fiveTwelths), fiveSixths));
		CHECK(equals(add(twoTwelths, fourTwelths), sixTwelths));
		CHECK(equals(add(twoTwelths, twoTwelths), fourTwelths));
		CHECK(equals(add(fourFourths, sixSixths), twelveSixths));
		CHECK(equals(add(fourFourths, twelveSixths), twelveFourths));
		CHECK(equals(add(half, sixTwelths), twelveTwelths));
		CHECK(equals(add(half, half), twelveTwelths));
		CHECK(
			equals(
				add(sixFifths, fiveSixths),
				RealNumberExchangeFormat(
					IntegerExchangeFormat({61}),
					IntegerExchangeFormat({30})
				)
			)
		);
		CHECK(
			equals(
				add(fourFifths, fiveSixths),
				RealNumberExchangeFormat(
					IntegerExchangeFormat({49}),
					IntegerExchangeFormat({30})
				)
			)
		);
		CHECK(
			equals(
				add(fiveFourths, fiveSixths),
				RealNumberExchangeFormat(
					IntegerExchangeFormat({50}),
					IntegerExchangeFormat({24})
				)
			)
		);
		CHECK(
			equals(
				add(negate(sixFifths), fiveSixths),
				RealNumberExchangeFormat(
					negate(IntegerExchangeFormat({11})),
					IntegerExchangeFormat({30})
				)
			)
		);
		CHECK(
			equals(
				add(sixFifths, negate(fiveSixths)),
				RealNumberExchangeFormat(
					IntegerExchangeFormat({11}),
					IntegerExchangeFormat({30})
				)
			)
		);
		CHECK(
			equals(
				add(negate(fourFifths), fiveSixths),
				RealNumberExchangeFormat(
					IntegerExchangeFormat({1}),
					IntegerExchangeFormat({30})
				)
			)
		);
		CHECK(
			equals(
				add(fourFifths, negate(fiveSixths)),
				RealNumberExchangeFormat(
					negate(IntegerExchangeFormat({1})),
					IntegerExchangeFormat({30})
				)
			)
		);
	}

	SECTION("Multiplication tests"){
		CHECK(
			equals(
				multiply(fiveFourths, fiveSixths),
				RealNumberExchangeFormat(
					IntegerExchangeFormat({25}),
					IntegerExchangeFormat({24})
				)
			)
		);
		CHECK(
			equals(
				multiply(fourFifths, fiveSixths),
				RealNumberExchangeFormat(
					IntegerExchangeFormat({20}),
					IntegerExchangeFormat({30})
				)
			)
		);
		CHECK(
			equals(
				multiply(fourTwelths, half),
				RealNumberExchangeFormat(
					IntegerExchangeFormat({4}),
					IntegerExchangeFormat({24})
				)
			)
		);
		CHECK(
			equals(
				multiply(sixFourths, fiveSixths),
				RealNumberExchangeFormat(
					IntegerExchangeFormat({5}),
					IntegerExchangeFormat({4})
				)
			)
		);
		CHECK(
			equals(
				multiply(twoTwelths, fourFifths),
				RealNumberExchangeFormat(
					IntegerExchangeFormat({8}),
					IntegerExchangeFormat({60})
				)
			)
		);
		CHECK(
			equals(
				multiply(REAL_ZERO, fourFifths),
				RealNumberExchangeFormat(
					IntegerExchangeFormat({0}),
					IntegerExchangeFormat({60})
				)
			)
		);
	}

	SECTION("Division tests"){
		CHECK(
			equals(
				divide(fiveFourths, fiveSixths),
				RealNumberExchangeFormat(
					IntegerExchangeFormat({30}),
					IntegerExchangeFormat({20})
				)
			)
		);
		CHECK(
			equals(
				divide(fourFifths, fiveSixths),
				RealNumberExchangeFormat(
					IntegerExchangeFormat({24}),
					IntegerExchangeFormat({25})
				)
			)
		);
		CHECK(
			equals(
				divide(fourTwelths, half),
				RealNumberExchangeFormat(
					IntegerExchangeFormat({8}),
					IntegerExchangeFormat({12})
				)
			)
		);
		CHECK(
			equals(
				divide(sixFourths, fiveSixths),
				RealNumberExchangeFormat(
					IntegerExchangeFormat({36}),
					IntegerExchangeFormat({20})
				)
			)
		);
		CHECK(
			equals(
				divide(twoTwelths, fourFifths),
				RealNumberExchangeFormat(
					IntegerExchangeFormat({10}),
					IntegerExchangeFormat({48})
				)
			)
		);
	}
}
