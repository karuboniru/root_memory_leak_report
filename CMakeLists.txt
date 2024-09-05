cmake_minimum_required(VERSION 3.12)
project(memory_test_rdf)

# Find the ROOT package
find_package(ROOT REQUIRED COMPONENTS RIO Tree)

# Add the include directories for ROOT
include_directories(${ROOT_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR})

# Add the source files for the TestData class
set(TESTDATA_HEADER TestData.h a_member.h)
set(TESTDATA_SOURCES TestData.cxx a_member.cxx)


# Add the library for the TestData class
add_library(TestData SHARED ${TESTDATA_SOURCES})
ROOT_GENERATE_DICTIONARY(G__TestData ${TESTDATA_HEADER} MODULE TestData LINKDEF TestDataLinkDef.h)
target_link_libraries(TestData ${ROOT_LIBRARIES})

# Add the executable for the gen program
add_executable(gen gen.cxx)
target_link_libraries(gen TestData ${ROOT_LIBRARIES})

# Add the executable for the read program
add_executable(read read.cxx)
target_link_libraries(read TestData ${ROOT_LIBRARIES})

add_executable(read_old read_old.cxx)
target_link_libraries(read_old TestData ${ROOT_LIBRARIES})