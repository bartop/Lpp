cmake_minimum_required(VERSION 2.8.10)

project(Conversions C CXX)

set(SOURCES
    Src/BoolFromNumber.cpp
    Src/IntegerFromHexString.cpp
)

set(TEST_SOURCES
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
