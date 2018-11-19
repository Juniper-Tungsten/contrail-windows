#include "gtest\gtest.h"
#include <posix_time.h>
#include<stdlib.h>

char * test_stptime_template(const char *pval,char *pformat, struct tm *ptmstruct)
{
    if(ptmstruct != nullptr)
        memset((void*)ptmstruct, 0, sizeof(*ptmstruct));
    char *ret = strptime(pval, pformat, ptmstruct);
    return ret;
}

TEST(class_test_posix_time, strptime_basic)
{
    struct tm tmstruct;
    char *ret = test_stptime_template("6 Dec 2001 10:33:45", "%d %b %Y %H:%M:%S", &tmstruct);
    ASSERT_NE(ret, nullptr);
    EXPECT_EQ(tmstruct.tm_sec, 45);
    EXPECT_EQ(tmstruct.tm_min, 33);
    EXPECT_EQ(tmstruct.tm_hour, 10);
    EXPECT_EQ(tmstruct.tm_mday, 6);
    EXPECT_EQ(tmstruct.tm_mon, 11);
    EXPECT_EQ(tmstruct.tm_year, 101);
}
TEST(class_test_posix_time, strptime_percent_F_1)
{
    struct tm tmstruct;
    char *ret = test_stptime_template("2001-12-6 Contrailtest", "%F Contrailtest", &tmstruct);
    ASSERT_NE(ret, nullptr);
    EXPECT_EQ(tmstruct.tm_year, 101);
    EXPECT_EQ(tmstruct.tm_mon, 11);
    EXPECT_EQ(tmstruct.tm_mday, 6);
}
TEST(class_test_posix_time, strptime_percent_F_2)
{
    struct tm tmstruct;
    char *ret = test_stptime_template("2001-12-6", "%F", &tmstruct);
    ASSERT_NE(ret, nullptr);
    EXPECT_EQ(tmstruct.tm_year, 101);
    EXPECT_EQ(tmstruct.tm_mon, 11);
    EXPECT_EQ(tmstruct.tm_mday, 6);
}
TEST(class_test_posix_time, strptime_percent_F_3)
{
    struct tm tmstruct;;
    char *ret = test_stptime_template("test 2001-12-6", "test %F", &tmstruct);
    ASSERT_NE(ret, nullptr);
    EXPECT_EQ(tmstruct.tm_year, 101);
    EXPECT_EQ(tmstruct.tm_mon, 11);
    EXPECT_EQ(tmstruct.tm_mday, 6);
}
TEST(class_test_posix_time, strptime_percent_F_4)
{
    struct tm tmstruct;;
    char *ret = test_stptime_template("2001-12-6", "%%F", &tmstruct);
    EXPECT_EQ(ret, nullptr);
}
TEST(class_test_posix_time, strptime_percent_F_5)
{
    struct tm tmstruct;;
    char *ret = test_stptime_template("test 2001-12-6", "test %%F", &tmstruct);
    EXPECT_EQ(ret, nullptr);
}

TEST(class_test_posix_time, strptime_percent_F_6)
{
    struct tm tmstruct;;
    char *ret = test_stptime_template("2001-12-6", "%%%F", &tmstruct);
    ASSERT_NE(ret, nullptr);
    EXPECT_EQ(tmstruct.tm_year, 101);
    EXPECT_EQ(tmstruct.tm_mon, 11);
    EXPECT_EQ(tmstruct.tm_mday, 6);
}

TEST(class_test_posix_time, strptime_percent_F_7)
{
    struct tm tmstruct;;
    char *ret = test_stptime_template("2001-12-6 test 2001-12-6", "%F test %F", &tmstruct);
    ASSERT_NE(ret, nullptr);
    EXPECT_EQ(tmstruct.tm_year, 101);
    EXPECT_EQ(tmstruct.tm_mon, 11);
    EXPECT_EQ(tmstruct.tm_mday, 6);

}

TEST(class_test_posix_time, strptime_percent_F_8)
{
    struct tm tmstruct;;
    char *ret = test_stptime_template("2001-12-6", "%%%%F", &tmstruct);
    EXPECT_EQ(ret, nullptr);
}

TEST(class_test_posix_time, strptime_percent_F_9)
{
    struct tm tmstruct;;
    char *ret = test_stptime_template("2001-12-6", "%%%%%F", &tmstruct);
    ASSERT_NE(ret, nullptr);
    EXPECT_EQ(tmstruct.tm_year, 101);
    EXPECT_EQ(tmstruct.tm_mon, 11);
    EXPECT_EQ(tmstruct.tm_mday, 6);
}

TEST(class_test_posix_time, timegm_1)
{
    struct tm tmstruct;
    time_t tt;
    tmstruct.tm_hour = 21;
    tmstruct.tm_isdst = 0;
    tmstruct.tm_mday = 14;
    tmstruct.tm_min= 30;
    tmstruct.tm_mon=6;
    tmstruct.tm_sec=33;
    tmstruct.tm_year=113;
    tmstruct.tm_wday = 0;
    tmstruct.tm_yday = 0;

    tt = timegm(&tmstruct);
    EXPECT_EQ(1373837433, static_cast<int>(tt));
}

TEST(class_test_posix_time, timegm_2)
{
    struct tm tmstruct;
    time_t tt;

    tmstruct.tm_hour = 0;
    tmstruct.tm_isdst = 0;
    tmstruct.tm_mday = 1;
    tmstruct.tm_min = 0;
    tmstruct.tm_mon = 0;
    tmstruct.tm_sec = 0;
    tmstruct.tm_year = 70;
    tmstruct.tm_wday = 0;
    tmstruct.tm_yday = 0;

    tt = timegm(&tmstruct);
    EXPECT_EQ(0, static_cast<int>(tt));
}

TEST(class_test_posix_time, timegm_3)
{
    struct tm tmstruct;
    time_t tt;

    tmstruct.tm_hour = 0;
    tmstruct.tm_isdst = 0;
    tmstruct.tm_mday = 1;
    tmstruct.tm_min = 0;
    tmstruct.tm_mon = 0;
    tmstruct.tm_sec = 0;
    tmstruct.tm_year = 71;
    tmstruct.tm_wday = 0;
    tmstruct.tm_yday = 0;

    tt = timegm(&tmstruct);
    //31536000 is the exact number of seconds in 365 days
    EXPECT_EQ(31536000, static_cast<int>(tt));
}

TEST(class_test_posix_time, timegm_4)
{
    struct tm tmstruct;
    time_t tt;

    tmstruct.tm_hour = 0;
    tmstruct.tm_isdst = 0;
    tmstruct.tm_mday = 1;
    tmstruct.tm_min = 0;
    tmstruct.tm_mon = 0;
    tmstruct.tm_sec = 0;
    tmstruct.tm_year = 55;
    tmstruct.tm_wday = 0;
    tmstruct.tm_yday = 0;

    tt = timegm(&tmstruct);
    EXPECT_EQ(-1, static_cast<int>(tt));
}

TEST(class_test_posix_time, timegm_5)
{
    time_t tt;
    tt = timegm(nullptr);
    EXPECT_EQ(-1, static_cast<int>(tt));
}


TEST(class_test_posix_time, gmtime_r_1)
{
    struct tm *ptm=nullptr, _tm;
    time_t timestr;
    memset(&_tm, 0, sizeof(struct tm));
    timestr = static_cast<time_t>(0);
    ptm = gmtime_r(&timestr, &_tm);
    EXPECT_EQ(ptm, &_tm);
    EXPECT_EQ(_tm.tm_sec, 0);
    EXPECT_EQ(_tm.tm_min, 0);
    EXPECT_EQ(_tm.tm_hour, 0);
    EXPECT_EQ(_tm.tm_mday, 1);
    EXPECT_EQ(_tm.tm_mon, 0);
    EXPECT_EQ(_tm.tm_year, 70);//1970 is 70 years ahead of 1900
    EXPECT_EQ(_tm.tm_wday, 4);//it was a thursday
    EXPECT_EQ(_tm.tm_yday, 0);
    EXPECT_EQ(_tm.tm_isdst, 0);
}

TEST(class_test_posix_time, ctime_r_1) //basic test
{
    time_t tt;
    const int BUFSIZE = 4096;
    char timeval[BUFSIZE] = { 0 };
    EXPECT_EQ(_putenv_s("TZ", "UTC"), 0);
    tt = static_cast<time_t>(0);
    char* val = ctime_r(&tt, timeval);

    std::string tvalstr = timeval;
    tvalstr = tvalstr.erase(tvalstr.find_last_not_of(" \t\n\r") + 1);
    struct std::tm tm { 0 };
    std::istringstream str(tvalstr.c_str());
    str >> std::get_time(&tm, "%a %b %d %H:%M:%S %Y"); // Thu Jan  1 00:00:00 1970

    ASSERT_NE(str.fail(), true);
    ASSERT_NE(val, nullptr);
    EXPECT_EQ(tm.tm_sec, 0);
    EXPECT_EQ(tm.tm_min, 0);
    EXPECT_EQ(tm.tm_hour, 0);
    EXPECT_EQ(tm.tm_mday, 1);
    EXPECT_EQ(tm.tm_mon, 0);
    EXPECT_EQ(tm.tm_year, 70);//1970 is 70 years ahead of 1900
    EXPECT_EQ(tm.tm_wday, 4);//it was a thursday
    EXPECT_EQ(tm.tm_yday, 0);
    EXPECT_EQ(tm.tm_isdst, 0);
}

TEST(class_test_posix_time, clock_gettime_monotonic_1)
{
    struct timespec ts;
    int ret = clock_gettime_monotonic(&ts);
    ASSERT_NE(ret, -1);
}

TEST(class_test_posix_time, clock_gettime_realtime_1)
{
    struct timespec ts;
    int ret = clock_gettime_realtime(&ts);
    ASSERT_NE(ret, -1);
}

TEST(class_test_posix_time, clock_gettime_1)
{
    struct timespec ts;
    int ret = clock_gettime(CLOCK_MONOTONIC, &ts);
    ASSERT_NE(ret, -1);
}

TEST(class_test_posix_time, clock_gettime_2)
{
    struct timespec ts;
    int ret = clock_gettime(CLOCK_REALTIME, &ts);
    ASSERT_NE(ret, -1);
}

TEST(class_test_posix_time, clock_getres_monotonic_1)
{
    struct timespec res;
    int ret = clock_getres_monotonic(&res);
    ASSERT_NE(ret, -1);
}

TEST(class_test_posix_time, clock_getres_1)
{
    struct timespec res;
    int ret = clock_getres(CLOCK_MONOTONIC, &res);
    ASSERT_NE(ret, -1);
}
