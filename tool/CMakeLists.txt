set(SOURCES
    tool.cc
)

set(TEST_SOURCES
    tool_test.cc
)

add_library(tool ${SOURCES})
target_link_libraries(tool fmt::fmt)

list(TRANSFORM TEST_SOURCES PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/")
set(GLOBAL_TEST_SOURCES ${GLOBAL_TEST_SOURCES} ${TEST_SOURCES} PARENT_SCOPE)
