
#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "../Src/BasicBoolean.hpp"
#include "../../Generic/Src/Function.hpp"

TEST_CASE( "BooleanFunction tests", "[BooleanFunction.hpp]" ) {
	const auto boolFun1 = Lpp::Function<Lpp::Boolean, bool>([](){
		return Lpp::boolean(true)->value();
	});

	const auto boolFun2 = Lpp::Function<Lpp::Boolean, bool>([](){
		return Lpp::boolean(false)->value();
	});

	const auto boolFun3 = Lpp::Function<Lpp::Boolean, bool>([](){
		return true;
	});

	const auto boolFun4 = Lpp::Function<Lpp::Boolean, bool>([](){
		return false;
	});

	REQUIRE( boolFun1.value() );
	REQUIRE( !boolFun2.value() );
	REQUIRE( boolFun3.value() );
	REQUIRE( !boolFun4.value() );
}
