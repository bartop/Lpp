
#define CATCH_CONFIG_MAIN
#include "../../3rdParty/Catch/include/catch.hpp"
#include "../Src/BasicBoolean.hpp"
#include "../Src/BooleanFunction.hpp"

TEST_CASE( "BooleanFunction tests", "[BooleanFunction.hpp]" ) {
	const auto boolFun1 = Lpp::boolFunction([](){
		return Lpp::boolean(true)->value();
	});

	const auto boolFun2 = Lpp::boolFunction([](){
		return Lpp::boolean(false)->value();
	});

	const auto boolFun3 = Lpp::boolFunction([](){
		return true;
	});

	const auto boolFun4 = Lpp::boolFunction([](){
		return false;
	});

	const auto boolFun5 = Lpp::sharedBooleanFunction([]() {
		return Lpp::boolean(true);
	});

	const auto boolFun6 = Lpp::sharedBooleanFunction([]() {
		return Lpp::boolean(false);
	});

	const auto boolFun7 = Lpp::uniqueBooleanFunction([]() {
		return Lpp::boolean(true);
	});

	const auto boolFun8 = Lpp::uniqueBooleanFunction([]() {
		return Lpp::boolean(false);
	});

	REQUIRE( boolFun1->value() );
	REQUIRE( !boolFun2->value() );
	REQUIRE( boolFun3->value() );
	REQUIRE( !boolFun4->value() );
	REQUIRE( boolFun5->value() );
	REQUIRE( !boolFun6->value() );
	REQUIRE( boolFun7->value() );
	REQUIRE( !boolFun8->value() );
}
