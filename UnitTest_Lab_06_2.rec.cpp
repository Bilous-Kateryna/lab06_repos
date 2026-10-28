#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define main program_main
#include "Lab_06_2.rec.cpp"
#undef main

TEST_CASE("IndexMinOdd - є непарні, мінімальний від'ємний")
{
    int a[6] = { 3, -5, 8, -7, 10, 1 };
    CHECK(IndexMinOdd(a, 6, 0, -1) == 3);    // найменший непарний -7
}

TEST_CASE("IndexMinOdd - немає непарних")
{
    int a[5] = { 2, 4, -6, 0, 8 };
    CHECK(IndexMinOdd(a, 5, 0, -1) == -1);
}

TEST_CASE("IndexMinOdd - мінімальний на початку")
{
    int a[5] = { -9, 4, 3, 6, 7 };
    CHECK(IndexMinOdd(a, 5, 0, -1) == 0);
}

TEST_CASE("IndexMinOdd - мінімальний в кінці")
{
    int a[5] = { 5, 4, 3, 6, -1 };
    CHECK(IndexMinOdd(a, 5, 0, -1) == 4);
}

TEST_CASE("IndexMinOdd - однакові мінімальні, повертається перший")
{
    int a[5] = { 7, -3, 4, -3, 9 };
    CHECK(IndexMinOdd(a, 5, 0, -1) == 1);
}

TEST_CASE("Create")
{
    int a[50];
    Create(a, 50, -20, 30, 0);
    for (int i = 0; i < 50; i++)
    {
        CHECK(a[i] >= -20);
        CHECK(a[i] <= 30);
    }
}