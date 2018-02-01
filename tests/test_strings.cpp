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
        
        TEST_METHOD(test_ffs_sanity)
        {
            unsigned int i = 1;
            unsigned int maxsize = sizeof(i) * CHAR_BIT;
            unsigned int val = 0;
            val = ~val; //not using ~0 for clarity only
            while (i < maxsize )
            {

            }

    

        }
      
    };

   
   
}