
#define CATCH_CONFIG_MAIN
#include "../../3rdParty/Catch/include/catch.hpp"
#include "../Src/BasicBoolean.hpp"
#include "../Src/EqualityComparisonResult.hpp"

TEST_CASE( "EqualityComparisonResult tests", "[EqualityComparisonResult.hpp]" ) {
	const auto trueBool = Lpp::boolean(true);
	const auto falseBool = Lpp::boolean(false);

	REQUIRE( Lpp::compareForEquality(Lpp::boolean(true), Lpp::boolean(true))->value() );
//	REQUIRE( !Lpp::compareForEquality(falseBool, trueBool)->value() );
//	REQUIRE( !Lpp::compareForEquality(trueBool, falseBool)->value() );
//	REQUIRE( Lpp::compareForEquality(falseBool, falseBool)->value() );
}
