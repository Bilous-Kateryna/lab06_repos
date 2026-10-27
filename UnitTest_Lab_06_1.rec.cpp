#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
 
#define main program_main
#include "Lab_06_1.rec.cpp"
#undef main
 
TEST_CASE("Check")
{
    CHECK(Check(5) == true);     // додатне, не кратне 3
    CHECK(Check(6) == true);     // додатне, кратне 3
    CHECK(Check(-4) == true);    // від'ємне, не кратне 3
    CHECK(Check(-3) == false);   // від'ємне, кратне 3
    CHECK(Check(0) == false);    // нуль кратний 3, але не додатний
}
 
TEST_CASE("Count")
{
    int a[8] = { 5, -3, -4, 0, 6, -9, 3, -1 };
    CHECK(Count(a, 8, 0) == 5);  // 5, -4, 6, 3, -1
}
 
TEST_CASE("Sum")
{
    int a[8] = { 5, -3, -4, 0, 6, -9, 3, -1 };
    CHECK(Sum(a, 8, 0) == 9);    // 5 - 4 + 6 + 3 - 1
}
 
TEST_CASE("Zero")
{
    int a[8] = { 5, -3, -4, 0, 6, -9, 3, -1 };
    int res[8] = { 0, -3, 0, 0, 0, -9, 0, 0 };
    Zero(a, 8, 0);
    for (int i = 0; i < 8; i++)
        CHECK(a[i] == res[i]);
}
 
TEST_CASE("Create")
{
    int a[50];
    Create(a, 50, -10, 35, 0);
    for (int i = 0; i < 50; i++)
    {
        CHECK(a[i] >= -10);
        CHECK(a[i] <= 35);
    }
}
 