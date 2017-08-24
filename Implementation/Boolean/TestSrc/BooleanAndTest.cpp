
#define CATCH_CONFIG_MAIN

#include "../../3rdParty/Catch/include/catch.hpp"
#include "../Src/BasicBoolean.hpp"
#include "../Src/BooleanAnd.hpp"

TEST_CASE( "BooleanAnd tests", "[BooleanAnd.hpp]" ) {
	REQUIRE( !logicalAnd(Lpp::boolean(false), Lpp::boolean(false))->value() );
	REQUIRE( !logicalAnd(Lpp::boolean(true), Lpp::boolean(false))->value() );
	REQUIRE( !logicalAnd(Lpp::boolean(false), Lpp::boolean(true))->value() );
	REQUIRE( logicalAnd(Lpp::boolean(true), Lpp::boolean(true))->value() );
}
