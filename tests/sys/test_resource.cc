
#include <sys/resource.h>
#include "gtest\gtest.h"


void test_getrlimit( int limit, struct rlimit *rl, int expected)
{
    int ret = getrlimit(limit, rl);
    ASSERT_EQ(ret, expected);
}

void test_setrlimit(int limit, struct rlimit *rl, int expected)
{
    int ret = setrlimit(limit, rl);
    ASSERT_EQ(ret, expected);
}

void test_getrusage(int usage, struct rusage *ru, int expected)
{
    int ret = getrusage(usage, ru);
    ASSERT_EQ(ret, expected);
}

TEST(class_test_resource, getrusage_nullptr)
{
    test_getrusage(RUSAGE_SELF, nullptr,-1);
    test_getrusage(RUSAGE_CHILDREN, nullptr, -1);
    test_getrusage(RUSAGE_THREAD, nullptr, -1);
    test_getrusage(RUSAGE_BOTH, nullptr, -1);
}

TEST(class_test_resource, getrlimit_nullptr)
{
    test_getrlimit(RLIMIT_CPU, nullptr, -1);
    test_getrlimit(RLIMIT_FSIZE, nullptr, -1);
    test_getrlimit(RLIMIT_DATA, nullptr, -1);
    test_getrlimit(RLIMIT_STACK, nullptr, -1);
    test_getrlimit(RLIMIT_CORE, nullptr, -1);
    test_getrlimit(RLIMIT_RSS, nullptr, -1);
    test_getrlimit(RLIMIT_NPROC, nullptr, -1);
    test_getrlimit(RLIMIT_NOFILE, nullptr, -1);
    test_getrlimit(RLIMIT_MEMLOCK, nullptr, -1);
    test_getrlimit(RLIMIT_AS, nullptr, -1);
    test_getrlimit(RLIMIT_LOCKS, nullptr, -1);
    test_getrlimit(RLIMIT_SIGPENDING, nullptr, -1);
    test_getrlimit(RLIMIT_MSGQUEUE, nullptr, -1);
    test_getrlimit(RLIMIT_NICE, nullptr, -1);
    test_getrlimit(RLIMIT_RTPRIO, nullptr, -1);
    test_getrlimit(RLIMIT_RTTIME, nullptr, -1);
    test_getrlimit(RLIM_NLIMITS, nullptr, -1);
}

TEST(class_test_resource, setrlimit_nullptr)
{
    test_setrlimit(RLIMIT_CPU, nullptr, -1);
    test_setrlimit(RLIMIT_FSIZE, nullptr, -1);
    test_setrlimit(RLIMIT_DATA, nullptr, -1);
    test_setrlimit(RLIMIT_STACK, nullptr, -1);
    test_setrlimit(RLIMIT_CORE, nullptr, -1);
    test_setrlimit(RLIMIT_RSS, nullptr, -1);
    test_setrlimit(RLIMIT_NPROC, nullptr, -1);
    test_setrlimit(RLIMIT_NOFILE, nullptr, -1);
    test_setrlimit(RLIMIT_MEMLOCK, nullptr, -1);
    test_setrlimit(RLIMIT_AS, nullptr, -1);
    test_setrlimit(RLIMIT_LOCKS, nullptr, -1);
    test_setrlimit(RLIMIT_SIGPENDING, nullptr, -1);
    test_setrlimit(RLIMIT_MSGQUEUE, nullptr, -1);
    test_setrlimit(RLIMIT_NICE, nullptr, -1);
    test_setrlimit(RLIMIT_RTPRIO, nullptr, -1);
    test_setrlimit(RLIMIT_RTTIME, nullptr, -1);
    test_setrlimit(RLIM_NLIMITS, nullptr, -1);
}

TEST(class_test_resource, getrlimit_invalid_param)
{
    struct rlimit ru;
    test_getrlimit(RLIMIT_CPU - 1, &ru, -1);
    test_getrlimit(RLIM_NLIMITS + 1, &ru, -1);
}

TEST(class_test_resource, setrlimit_invalid_param)
{
    struct rlimit ru;
    test_setrlimit(RLIMIT_CPU - 1, &ru, -1);
    test_setrlimit(RLIM_NLIMITS + 1, &ru, -1);
}

TEST(class_test_resource, getrusage_invalid_param)
{
    struct rusage ru;
    test_getrusage(RUSAGE_BOTH - 1, &ru, -1);
    test_getrusage(RUSAGE_THREAD + 1, &ru, -1);
}

TEST(class_test_resource, getrusage_sanity)
{
    struct rusage ru;
    test_getrusage(RUSAGE_SELF, &ru, 0);
    test_getrusage(RUSAGE_CHILDREN, &ru, 0);
    test_getrusage(RUSAGE_THREAD, &ru, 0);
    test_getrusage(RUSAGE_BOTH, &ru, 0);
}

TEST(class_test_resource, getrlimit_sanity)
{
    struct rlimit rl;
    test_getrlimit(RLIMIT_CPU, &rl, 0);
    test_getrlimit(RLIMIT_FSIZE, &rl, 0);
    test_getrlimit(RLIMIT_DATA, &rl, 0);
    test_getrlimit(RLIMIT_STACK, &rl, 0);
    test_getrlimit(RLIMIT_CORE, &rl, 0);
    test_getrlimit(RLIMIT_RSS, &rl, 0);
    test_getrlimit(RLIMIT_NPROC, &rl, 0);
    test_getrlimit(RLIMIT_NOFILE, &rl, 0);
    test_getrlimit(RLIMIT_MEMLOCK, &rl, 0);
    test_getrlimit(RLIMIT_AS, &rl, 0);
    test_getrlimit(RLIMIT_LOCKS, &rl, 0);
    test_getrlimit(RLIMIT_SIGPENDING, &rl, 0);
    test_getrlimit(RLIMIT_MSGQUEUE, &rl, 0);
    test_getrlimit(RLIMIT_NICE, &rl, 0);
    test_getrlimit(RLIMIT_RTPRIO, &rl, 0);
    test_getrlimit(RLIMIT_RTTIME, &rl, 0);
    test_getrlimit(RLIM_NLIMITS, &rl, 0);
}
TEST(class_test_resource, setrlimit_sanity)
{
    struct rlimit rl;
    test_setrlimit(RLIMIT_CPU, &rl, 0);
    test_setrlimit(RLIMIT_FSIZE, &rl, 0);
    test_setrlimit(RLIMIT_DATA, &rl, 0);
    test_setrlimit(RLIMIT_STACK, &rl, 0);
    test_setrlimit(RLIMIT_CORE, &rl, 0);
    test_setrlimit(RLIMIT_RSS, &rl, 0);
    test_setrlimit(RLIMIT_NPROC, &rl, 0);
    test_setrlimit(RLIMIT_NOFILE, &rl, 0);
    test_setrlimit(RLIMIT_MEMLOCK, &rl, 0);
    test_setrlimit(RLIMIT_AS, &rl, 0);
    test_setrlimit(RLIMIT_LOCKS, &rl, 0);
    test_setrlimit(RLIMIT_SIGPENDING, &rl, 0);
    test_setrlimit(RLIMIT_MSGQUEUE, &rl, 0);
    test_setrlimit(RLIMIT_NICE, &rl, 0);
    test_setrlimit(RLIMIT_RTPRIO, &rl, 0);
    test_setrlimit(RLIMIT_RTTIME, &rl, 0);
    test_setrlimit(RLIM_NLIMITS, &rl, 0);
}
