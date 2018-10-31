
#include <posix_stdlib.h>
#include "gtest\gtest.h"


TEST(class_test_stdlib, getloadavg_1)
{
    int ret = getloadavg(nullptr, 3);
    EXPECT_EQ(ret, -1);
}

TEST(class_test_stdlib, getloadavg_2)
{
    double loadavg[3];
    int ret = getloadavg(loadavg, 0);
    EXPECT_EQ(ret, -1);
}

TEST(class_test_stdlib, getloadavg_3)
{
    double loadavg[1];
    int ret = getloadavg(loadavg, 1);
    EXPECT_GE(ret, 1);//at least one sample
    ASSERT_NE(0.0, loadavg[0]);
}

TEST(class_test_stdlib, getloadavg_4)
{
    double loadavg[3];
    int ret = getloadavg(loadavg, 2);
    EXPECT_GE(ret, 1);
    ASSERT_NE(0.0, loadavg[0]);
}

TEST(class_test_stdlib, getloadavg_5)
{
    double loadavg[3];
    int ret = getloadavg(loadavg, 3);
    EXPECT_GE(ret, 1);
    ASSERT_NE(0.0, loadavg[0]);
} 
