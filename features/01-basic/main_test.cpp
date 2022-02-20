#include <string>
#include <gtest/gtest.h>

class UtilTests : public ::testing::Test {
};

TEST_F(UtilTests, simple) {
    std::string res = "Hello";
    EXPECT_EQ(res, "Hello");
}