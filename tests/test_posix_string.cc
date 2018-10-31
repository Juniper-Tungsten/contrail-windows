#include <posix_string.h>
#include <cstring>
#include "gtest\gtest.h"

TEST(class_posix_string, strsignal_1)
{
    char *str = strsignal(123);
    ASSERT_NE(nullptr, str);
    //str != nullptr is not needed since ASSERT_NE will terminate the function
    EXPECT_EQ(0, strncmp("Signal #123", str, strlen("Signal #123")));
}
