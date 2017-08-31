
#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include "../Src/BasicBoolean.hpp"
#include "../Src/BooleanNegation.hpp"

TEST_CASE( "BooleanNegation tests", "[BooleanNegation.hpp]" ) {
	REQUIRE( logicalNegation(Lpp::boolean(false))->value() );
	REQUIRE( !logicalNegation(Lpp::boolean(true))->value() );
}
