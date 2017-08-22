
#define CATCH_CONFIG_MAIN
#include "../../3rdParty/Catch/include/catch.hpp"
#include "../Src/BasicBoolean.hpp"

TEST_CASE( "BasicBoolean tests", "[BasicBoolean.hpp]" ) {
	const auto trueBool = Lpp::boolean(true);
	const auto falseBool = Lpp::boolean(false);

	REQUIRE( trueBool->value() );
	REQUIRE( !falseBool->value() );
}
