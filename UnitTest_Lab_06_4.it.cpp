#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define main program_main
#include "Lab_06_4.it.cpp"
#undef main

TEST_CASE("SumPositive")
{
    double a[6] = { 1.5, -2, 3, 0, -4.5, 2 };
    CHECK(SumPositive(a, 6) == doctest::Approx(6.5));
}

TEST_CASE("SumPositive - немає додатних")
{
    double a[4] = { -1, -2.5, 0, -3 };
    CHECK(SumPositive(a, 4) == doctest::Approx(0));
}

TEST_CASE("IndexMaxAbs")
{
    double a[4] = { 1, -7, 3, 5 };
    CHECK(IndexMaxAbs(a, 4) == 1);
}

TEST_CASE("IndexMinAbs")
{
    double a[4] = { 4, -0.5, 3, 1 };
    CHECK(IndexMinAbs(a, 4) == 1);
}

TEST_CASE("ProductBetween")
{
    double a[5] = { 2, 3, 4, 5, 6 };
    double P = 0;
    CHECK(ProductBetween(a, 0, 4, P) == true);
    CHECK(P == doctest::Approx(60));       // 3 * 4 * 5
}

TEST_CASE("ProductBetween - індекси в зворотному порядку")
{
    double a[5] = { 2, 3, 4, 5, 6 };
    double P = 0;
    CHECK(ProductBetween(a, 4, 0, P) == true);
    CHECK(P == doctest::Approx(60));
}

TEST_CASE("ProductBetween - між індексами немає елементів")
{
    double a[5] = { 2, 3, 4, 5, 6 };
    double P = 0;
    CHECK(ProductBetween(a, 1, 2, P) == false);
    CHECK(ProductBetween(a, 3, 3, P) == false);
}

TEST_CASE("SortOddDesc")
{
    double b[7] = { 3, 2, 7, 4, 5, 8, 1 };
    double res[7] = { 7, 2, 5, 4, 3, 8, 1 };
    SortOddDesc(b, 7);
    for (int i = 0; i < 7; i++)
        CHECK(b[i] == doctest::Approx(res[i]));
}

TEST_CASE("SortOddDesc - від'ємні непарні")
{
    double b[4] = { -3, 4, -1, 5 };
    double res[4] = { 5, 4, -1, -3 };
    SortOddDesc(b, 4);
    for (int i = 0; i < 4; i++)
        CHECK(b[i] == doctest::Approx(res[i]));
}

TEST_CASE("SortOddDesc - немає непарних")
{
    double b[4] = { 2, 0, 4, -6 };
    double res[4] = { 2, 0, 4, -6 };
    SortOddDesc(b, 4);
    for (int i = 0; i < 4; i++)
        CHECK(b[i] == doctest::Approx(res[i]));
}

TEST_CASE("Create")
{
    double a[50];
    Create(a, 50, -10, 10);
    for (int i = 0; i < 50; i++)
    {
        CHECK(a[i] >= -10);
        CHECK(a[i] <= 10);
    }
}