
#include <strings.h>
#include "gtest\gtest.h"
#include <limits>


template <class T> unsigned int rightmost_index_byshift(T val)
{
    static_assert(std::is_integral <T>::value, "value needs to be an integer type");
    T bitval = 1;
    unsigned int nBits = sizeof(val)*8;
    while (0 != nBits) {
        if (val&bitval)
            break;
        bitval <<= 1;
        nBits--;
    }
    return sizeof(val)*8 - nBits+1;
}

void TryFFS(unsigned int val)
{
    int bitpos = ffs(val);
    unsigned int rightmostindex = rightmost_index_byshift(val);
    EXPECT_EQ(rightmostindex, bitpos);
}

TEST(class_test_winutils, test_oldest_bit)
{
    int val = 1 << (sizeof(int) * 8 - 1);
    TryFFS(val);
}

TEST(class_test_winutils, test_ffs_all_values)
{
    unsigned int i = 0;
    unsigned short maxsize = std::numeric_limits<unsigned short>::max();
    while (i++ < maxsize)
    {
        TryFFS(i);
    }
}
