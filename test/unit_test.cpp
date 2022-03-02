#include <string>
#include <gtest/gtest.h>
#include "Reverse.h"

class UtilTests : public ::testing::Test
{
};

TEST_F(UtilTests, simple){
    std::string toRev = "Hello";

    Reverse rev;
    std::string res = rev.reverse(toRev);

    EXPECT_EQ(res, "olleH" );
}