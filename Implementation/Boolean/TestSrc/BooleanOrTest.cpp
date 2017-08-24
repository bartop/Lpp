#define CATCH_CONFIG_MAIN

#include "../../3rdParty/Catch/include/catch.hpp"
#include "../Src/BasicBoolean.hpp"
#include "../Src/BooleanOr.hpp"

TEST_CASE( "BooleanOr tests", "[BooleanOr.hpp]" ) {
	REQUIRE( logicalOr(Lpp::boolean(true), Lpp::boolean(true))->value() );
	REQUIRE( logicalOr(Lpp::boolean(true), Lpp::boolean(false))->value() );
	REQUIRE( logicalOr(Lpp::boolean(false), Lpp::boolean(true))->value() );
	REQUIRE( !logicalOr(Lpp::boolean(false), Lpp::boolean(false))->value() );
}
