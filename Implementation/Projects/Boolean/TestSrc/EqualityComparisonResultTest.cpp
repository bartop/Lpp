
#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "../Src/BasicBoolean.hpp"
#include "../Src/EqualityComparisonResult.hpp"

TEST_CASE( "EqualityComparisonResult tests", "[EqualityComparisonResult.hpp]" ) {
	REQUIRE( Lpp::compareForEquality(Lpp::boolean(true), Lpp::boolean(true))->value() );
	REQUIRE( !Lpp::compareForEquality(Lpp::boolean(true), Lpp::boolean(false))->value() );
	REQUIRE( !Lpp::compareForEquality(Lpp::boolean(false), Lpp::boolean(true))->value() );
	REQUIRE( Lpp::compareForEquality(Lpp::boolean(false), Lpp::boolean(false))->value() );
}
