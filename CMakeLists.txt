cmake_minimum_required(VERSION 3.12)

project(pddlparser-pp)

set(CMAKE_CXX_STANDARD 11)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

include_directories(include)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_compile_options(-Wall -Wextra -pedantic -O2 -Wno-macro-redefined)

set(SOURCES
    src/domain.cc
    src/problem.cc
    src/action.cc
    src/predicate.cc
    src/pddldriver.cc
)
bison_target(
    pddlparser
    src/pddlparser.yy
    ${CMAKE_CURRENT_BINARY_DIR}/pddlparser.tab.cc
    DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/pddlparser.tab.hh
)
flex_target(
    pddllex
    src/pddlscanner.ll
    ${CMAKE_CURRENT_BINARY_DIR}/pddllex.yy.cc
)

add_library(libpddlparser 
    ${SOURCES}
    ${FLEX_pddllex_OUTPUTS}
    ${BISON_pddlparser_OUTPUTS}
)
target_link_libraries(libpddlparser ${FLEX_LIBRARIES})

add_executable(pddl src/main.cc)
target_link_libraries(pddl libpddlparser)