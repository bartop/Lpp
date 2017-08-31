
#define CATCH_CONFIG_MAIN

#include "../Src/NumberOperations.hpp"
#include "../Src/RealNumberOperations.hpp"
#include "../Src/IntegerOperations.hpp"

#include "../../Config/Src/config.hpp"

#include <catch.hpp>

using namespace Lpp;

TEST_CASE( "NumberOperations tests", "[NumberOperations.hpp]" ) {
	const IntegerExchangeFormat one({1});
	const IntegerExchangeFormat two({2});
	const IntegerExchangeFormat four({4});
	const IntegerExchangeFormat five({5});
	const IntegerExchangeFormat six({6});
	const IntegerExchangeFormat twelve({12});

	const NumberExchangeFormat oneI(
		RealNumberExchangeFormat(
			INTEGER_ZERO,
			INTEGER_ONE
		),
		RealNumberExchangeFormat(
			INTEGER_ONE,
			INTEGER_ONE
		)
	);

	SECTION("Comparison tests"){
		CHECK(equals(oneI, oneI));
		CHECK(
			!equals(
				oneI,
				NumberExchangeFormat(
					RealNumberExchangeFormat(
						INTEGER_ONE,
						INTEGER_ONE
					),
					RealNumberExchangeFormat(
						INTEGER_ZERO,
						INTEGER_ONE
					)
				)
			)
		);
		CHECK(
			!equals(
				oneI,
				NumberExchangeFormat(
					RealNumberExchangeFormat(
						INTEGER_ZERO,
						INTEGER_ONE
					),
					RealNumberExchangeFormat(
						two,
						INTEGER_ONE
					)
				)
			)
		);
	}

	SECTION("Addition tests"){
		CHECK(
			equals(
				add(
					oneI,
					NumberExchangeFormat(
						RealNumberExchangeFormat(
							INTEGER_ONE,
							INTEGER_ONE
						),
						RealNumberExchangeFormat(
							INTEGER_ZERO,
							INTEGER_ONE
						)
					)
				),
				NumberExchangeFormat(
					RealNumberExchangeFormat(
						INTEGER_ONE,
						INTEGER_ONE
					),
					RealNumberExchangeFormat(
						INTEGER_ONE,
						INTEGER_ONE
					)
				)
			)
		);
		CHECK(
			equals(
				add(
					oneI,
					NumberExchangeFormat(
						RealNumberExchangeFormat(
							four,
							INTEGER_ONE
						),
						RealNumberExchangeFormat(
							four,
							INTEGER_ONE
						)
					)
				),
				NumberExchangeFormat(
					RealNumberExchangeFormat(
						four,
						INTEGER_ONE
					),
					RealNumberExchangeFormat(
						five,
						INTEGER_ONE
					)
				)
			)
		);
	}

	SECTION("Multiplication tests"){
		CHECK(
			equals(
				multiply(
					oneI,
					NumberExchangeFormat(
						RealNumberExchangeFormat(
							four,
							INTEGER_ONE
						),
						RealNumberExchangeFormat(
							INTEGER_ZERO,
							INTEGER_ONE
						)
					)
				),
				NumberExchangeFormat(
					RealNumberExchangeFormat(
						INTEGER_ZERO,
						INTEGER_ONE
					),
					RealNumberExchangeFormat(
						four,
						INTEGER_ONE
					)
				)
			)
		);
		CHECK(
			equals(
				multiply(
					oneI,
					NumberExchangeFormat(
						RealNumberExchangeFormat(
							four,
							INTEGER_ONE
						),
						RealNumberExchangeFormat(
							four,
							INTEGER_ONE
						)
					)
				),
				NumberExchangeFormat(
					negate(
						RealNumberExchangeFormat(
							four,
							INTEGER_ONE
						)
					),
					RealNumberExchangeFormat(
						four,
						INTEGER_ONE
					)
				)
			)
		);
	}

	SECTION("Division tests"){
		CHECK(
			equals(
				divide(
					NumberExchangeFormat(
						RealNumberExchangeFormat(
							INTEGER_ZERO,
							INTEGER_ONE
						),
						RealNumberExchangeFormat(
							four,
							INTEGER_ONE
						)
					),
					NumberExchangeFormat(
						RealNumberExchangeFormat(
							four,
							INTEGER_ONE
						),
						RealNumberExchangeFormat(
							INTEGER_ZERO,
							INTEGER_ONE
						)
					)
				),
				oneI
			)
		);
		CHECK(
			equals(
				divide(
					NumberExchangeFormat(
						negate(
							RealNumberExchangeFormat(
								four,
								INTEGER_ONE
							)
						),
						RealNumberExchangeFormat(
							four,
							INTEGER_ONE
						)
					),
					NumberExchangeFormat(
						RealNumberExchangeFormat(
							four,
							INTEGER_ONE
						),
						RealNumberExchangeFormat(
							four,
							INTEGER_ONE
						)
					)
				),
				oneI
			)
		);
	}
}
