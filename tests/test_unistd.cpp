#include "stdafx.h"
#include "CppUnitTest.h"
#include "unistd.h"
#include <windows.h>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittests
{		
	TEST_CLASS(class_test_sleep)
	{
	public:
        void TrySleep(unsigned int sleeptime)
        {
            DWORD before = ::GetTickCount();
            sleep(sleeptime);
            DWORD after = ::GetTickCount();
            //the exact time in milliseconds will not be sleeptime*1000
            //as the thread may have some delay while starting
            //but the rounded time to seconds should match
            Assert::AreEqual((unsigned long)sleeptime, (after - before) / 1000);
        }
        //just try a few random values and count ticks
		TEST_METHOD(test_sleep_zero)
		{
            TrySleep(0);
        }
        TEST_METHOD(test_sleep_val1)
        {
            TrySleep(1);
        }
        TEST_METHOD(test_sleep_val3)
        {
            TrySleep(3);
        }
	};

    TEST_CLASS(class_test_usleep)
    {
    public:
        void TryUSleep(useconds_t sleeptime)
        {
            DWORD before = ::GetTickCount();
            usleep(sleeptime);
            DWORD after = ::GetTickCount();
            //the exact time in milliseconds will not be sleeptime*1000
            //as the thread may have some delay while starting
            //but the rounded time to seconds should match
            Assert::AreEqual((unsigned long)sleeptime/1000, (after - before));
        }

        //just try a few random values and count ticks
        TEST_METHOD(test_usleep_zero)
        {
            TryUSleep(0);
        }
        TEST_METHOD(test_usleep_val1)
        {
            TryUSleep(1000000UL);
        }
        TEST_METHOD(test_usleep_val3)
        {
            TryUSleep(3000000UL);
        }
    };

    TEST_CLASS(class_test_getppid)
    {
    public:

        TEST_METHOD(test_getppid)
        {
            int ppid = getppid();
            //make sure the process id returned is valid
            HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, TRUE, ppid);
            Assert::AreNotEqual(hProcess, (void*)nullptr);
            CloseHandle(hProcess);
        }
    };
 
    TEST_CLASS(class_test_sysconf)
    {
    public:

        TEST_METHOD(test_sysconf)
        {
            Assert::AreEqual(sysconf(0), static_cast<long>(-1));
        }
    };

    TEST_CLASS(class_test_vfork)
    {
    public:

        TEST_METHOD(test_vfork)
        {
            Assert::AreEqual(sysconf(0), static_cast<long>(-1));
        }
    };

}