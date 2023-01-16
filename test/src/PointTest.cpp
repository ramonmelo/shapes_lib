#include "gtest/gtest.h"
#include <shapes/Point.h>

TEST(ShapesTest, SimpleTest) {
  Point p(1, 2, 3);

  EXPECT_EQ(p.getX(), 1);
  EXPECT_EQ(p.getY(), 2);
  EXPECT_EQ(p.getZ(), 3);
}