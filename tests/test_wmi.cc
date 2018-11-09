#include "gtest\gtest.h"
#include "wmi.h"


TEST(class_test_ProcessorQueue, ProcessorQueue_Sanity)
{
    int queuelen = GetProcessorQueueLength();
    ASSERT_GE(queuelen, 0);
}
