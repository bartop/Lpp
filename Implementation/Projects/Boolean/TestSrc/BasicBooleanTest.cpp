
#define CATCH_CONFIG_MAIN
#include "../Src/BasicBoolean.hpp"

#include <catch.hpp>

TEST_CASE( "BasicBoolean tests", "[BasicBoolean.hpp]" ) {
	const auto trueBool = Lpp::boolean(true);
	const auto falseBool = Lpp::boolean(false);

	REQUIRE( trueBool->value() );
	REQUIRE( !falseBool->value() );
}
