cmake_minimum_required(VERSION 2.8.10)

project(Number C CXX)

set(SOURCES
    Src/Integer/BasicInt.cpp
    Src/Integer/BigInteger.cpp
    Src/Integer/CachingInteger.cpp
    Src/Integer/DivisionRemainder.cpp
    Src/Integer/Integer.cpp
    Src/Integer/IntegerDifference.cpp
    Src/Integer/IntegerExchangeFormat.cpp
    Src/Integer/IntegerFromReal.cpp
    Src/Integer/IntegerNegation.cpp
    Src/Integer/IntegerOperations.cpp
    Src/Integer/IntegerProduct.cpp
    Src/Integer/IntegerQuotient.cpp
    Src/Integer/IntegerSum.cpp
    Src/Number/BasicComplex.cpp
    Src/Number/CachingNumber.cpp
    Src/Number/Difference.cpp
    Src/Number/Negation.cpp
    Src/Number/Number.cpp
    Src/Number/NumberExchangeFormat.cpp
    Src/Number/NumberOperations.cpp
    Src/Number/Product.cpp
    Src/Number/Quotient.cpp
    Src/Number/Sum.cpp
    Src/Real/CachingReal.cpp
    Src/Real/RealDifference.cpp
    Src/Real/RealNegation.cpp
    Src/Real/RealNumber.cpp
    Src/Real/RealNumberExchangeFormat.cpp
    Src/Real/RealNumberOperations.cpp
    Src/Real/RealProduct.cpp
    Src/Real/RealQuotient.cpp
    Src/Real/RealSum.cpp
)

set(TEST_SOURCES
	TestSrc/IntegerOperationsTest.cpp
	TestSrc/NumberOperationsTest.cpp
	TestSrc/RealNumberOperationsTest.cpp
    TestSrc/BasicIntTest.cpp
)

include_directories(${CATCH_INCLUDE_DIR})

add_library(${PROJECT_NAME} STATIC ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED 14
    CXX_EXTENSIONS OFF
)

target_link_libraries(${PROJECT_NAME})

enable_testing()
foreach( testsourcefile ${TEST_SOURCES} )
    string( REPLACE "TestSrc/" "" testname ${testsourcefile} )
    string( REPLACE ".cpp" "" testname ${testname} )
    add_executable( ${testname} ${testsourcefile} )
	target_link_libraries( ${testname} ${PROJECT_NAME})
	add_test( ${testname} ${testname})
endforeach( testsourcefile ${TEST_SOURCES} )

# Expose Boolean's public includes to other subprojects through cache variable.
#set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include
#    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
