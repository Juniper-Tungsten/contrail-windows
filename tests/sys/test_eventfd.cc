
#include <sys/eventfd.h>
#include "gtest\gtest.h"


TEST(class_test_eventfd, eventfd_1)
{
    EXPECT_EQ(eventfd(0, 0), -1);
}
