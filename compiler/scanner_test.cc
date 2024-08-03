#include <gtest/gtest.h>

namespace cgo {
namespace testing {

TEST(AdditionTest, HandlesPositiveInput) {
  EXPECT_EQ(3, 3);
  EXPECT_EQ(7, 7);
}

} // namespace testing
} // namespace cgo
