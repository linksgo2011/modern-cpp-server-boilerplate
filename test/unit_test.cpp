#include <string>
#include "Reverse.h"
#include <gtest/gtest.h>
#include "gmock/gmock.h"

class UtilTests : public ::testing::Test {
};

TEST_F(UtilTests, reverse_test) {
    std::string toRev = "Hello";

    Reverse rev;
    std::string res = rev.reverse(toRev);

    EXPECT_EQ(res, "olleH");
}

class MockedLogger : public Logger {
public:
    MOCK_METHOD(void, print, (std::string content), ());
};

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::Eq;

TEST_F(UtilTests, mock_test) {
    // Reverse depend on Logger, but logger throw an error, we have to mock it
    std::string toRev = "Hello";

    MockedLogger mockedLogger;
    EXPECT_CALL(mockedLogger, print(Eq("")));

    Reverse rev;
    std::string res = rev.reverse(toRev);

    EXPECT_EQ(res, "olleH");
}

