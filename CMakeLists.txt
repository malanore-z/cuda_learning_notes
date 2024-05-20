cmake_minimum_required(VERSION 3.28)
project(cuda_learning_notes CUDA CXX C)

set(CMAKE_CUDA_STANDARD 20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 17)

option(CLN_BUILD_TESTS "build tests" ON)
option(CLN_BUILD_BM "build benchmarks" ON)

# absl flag
set(ABSL_PROPAGATE_CXX_STD ON)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third-party/abseil-cpp)
set(ABSL_LIBS absl::strings)


include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third-party)

set(SOURCES cln/mat.cu)


add_library(cln SHARED ${SOURCES})
target_link_libraries(cln PUBLIC ${ABSL_LIBS})
set_target_properties(cln PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)

add_executable(cln_cli cln/cli_main.cu)
target_link_libraries(cln_cli cln)

if (CLN_BUILD_TESTS)
    include(FetchContent)
    # v1.14.0
    FetchContent_Declare(
            googletest
            URL https://github.com/google/googletest/archive/f8d7d77c06936315286eb55f8de22cd23c188571.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()

    set(TEST_SOURCES cln/mat_test.cc)

    add_executable(cln_test ${TEST_SOURCES})
    target_link_libraries(cln_test PUBLIC cln GTest::gtest_main)

    include(GoogleTest)
    gtest_discover_tests(cln_test)
endif (CLN_BUILD_TESTS)

if (CLN_BUILD_BM)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third-party/benchmark)

    set(BM_SOURCES cln/mat_bm.cc)

    add_executable(cln_bm ${BM_SOURCES})
    target_link_libraries(cln_bm PUBLIC cln benchmark::benchmark)
endif (CLN_BUILD_BM)
