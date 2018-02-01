#include "stdafx.h"
#include <limits>
#include <cstddef>
#include <iostream>
#include "CppUnitTest.h"
#include "unistd.h"
#include "strings.h"

int ffs(int);


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittests
{
    TEST_CLASS(class_test_ffs)
    {
    public:
        void TryFFS(int i)
        {
            int bitpos = ffs(i);


        }
        
        TEST_METHOD(test_ffs_all)
        {
            unsigned short minval = std::numeric_limits<unsigned short>::min();
            unsigned short maxval = std::numeric_limits<unsigned short>::max();
            for (unsigned short i = minval; i <= maxval; i++)
            {
                TryFFS(i);
            }

        }
      
    };

   
   
}