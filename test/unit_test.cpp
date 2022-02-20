#include <string>
#include <gtest/gtest.h>

class UtilTests : public ::testing::Test
{
};

TEST_F(UtilTests, simple){
    EXPECT_EQ(3L, 3L);
}