set(SOURCES
    scanner.cc
)

set(TEST_SOURCES
    scanner_test.cc
)

add_library(compiler ${SOURCES})
target_link_libraries(compiler fmt::fmt)

list(TRANSFORM TEST_SOURCES PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/")
set(GLOBAL_TEST_SOURCES ${GLOBAL_TEST_SOURCES} ${TEST_SOURCES} PARENT_SCOPE)