#include <posix_fcntl.h>
#include "gtest\gtest.h"

TEST(class_test_fcntl,fcntl1) //nullptr should not crash the test
{
    EXPECT_EQ(fcntl(0, F_SETFD, nullptr), -1);
}
TEST(class_test_fcntl,fcntl2) //nullptr should not crash the test
{
    EXPECT_EQ(fcntl(0, F_SETFD, FD_CLOEXEC+1), -1);
}
TEST(class_test_fcntl,fcntl3) //nullptr should not crash the test
{
    EXPECT_EQ(fcntl(0, F_SETFD, FD_CLOEXEC-1), -1);
}
TEST(class_test_fcntl,fcntl4) //nullptr should not crash the test
{
    EXPECT_EQ(fcntl(0, F_SETFD, FD_CLOEXEC), 0);
}
TEST(class_test_fcntl,fcntl5)
{
    EXPECT_EQ(fcntl(0, F_SETFD + 1, FD_CLOEXEC), -1);
}
TEST(class_test_fcntl,fcntl6)
{
    EXPECT_EQ(fcntl(0, F_SETFD - 1, FD_CLOEXEC), -1);
}


