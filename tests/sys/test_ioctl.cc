#include <sys/ioctl.h>

#include "gtest\gtest.h"


TEST(class_test_ioctl, ioctl1) //nullptr should not crash the test
{

    EXPECT_EQ(ioctl(0, TIOCGWINSZ, nullptr), -1);
}
TEST(class_test_ioctl, ioctl2)
{
    struct winsize sz;
    EXPECT_EQ(ioctl(0, TIOCGWINSZ + 1, &sz), -1);
}
TEST(class_test_ioctl,ioctl3)
{
    struct winsize sz;
    EXPECT_EQ(ioctl(0, TIOCGWINSZ - 1, &sz), -1);
}
TEST(class_test_ioctl,ioctl4)
{
    struct winsize sz;
    EXPECT_EQ(ioctl(0, TIOCGWINSZ, &sz), 0);
}