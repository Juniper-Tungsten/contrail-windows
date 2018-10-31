#include <endian.h>

#include "gtest\gtest.h"


TEST(class_test_endian, htobe64_1)
{
    EXPECT_EQ(htobe64(0),static_cast<uint64_t>(0));
}
TEST(class_test_endian, htobe64_2)
{
    EXPECT_EQ(htobe64(0xFFFFFFFFFFFFFFFF), 0xFFFFFFFFFFFFFFFF);
}
TEST(class_test_endian, htobe64_3)
{
    EXPECT_EQ(htobe64(0x0123456789ABCDEF), static_cast<uint64_t>(0xEFCDAB8967452301));
}

