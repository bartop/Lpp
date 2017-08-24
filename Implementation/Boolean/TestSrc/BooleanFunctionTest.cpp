
#define CATCH_CONFIG_MAIN
#include "../../3rdParty/Catch/include/catch.hpp"
#include "../Src/BasicBoolean.hpp"
#include "../Src/BooleanFunction.hpp"

TEST_CASE( "BooleanFunction tests", "[BooleanFunction.hpp]" ) {
	const auto boolFun1 = Lpp::booleanFunction([](){
		return Lpp::boolean(true)->value();
	});

	const auto boolFun2 = Lpp::booleanFunction([](){
		return Lpp::boolean(false)->value();
	});

	const auto boolFun3 = Lpp::booleanFunction([](){
		return true;
	});

	const auto boolFun4 = Lpp::booleanFunction([](){
		return false;
	});

	REQUIRE( boolFun1->value() );
	REQUIRE( !boolFun2->value() );
	REQUIRE( boolFun3->value() );
	REQUIRE( !boolFun4->value() );
}
