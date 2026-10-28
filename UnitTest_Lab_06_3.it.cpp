#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define main program_main
#include "Lab_06_3.it.cpp"
#undef main

// ---------- 1) звичайні функції (int) ----------

TEST_CASE("MaxEven - є парні, максимальний додатний")
{
    int a[6] = { 3, 8, -4, 7, 10, 1 };
    int m = 0;
    CHECK(MaxEven(a, 6, m) == true);
    CHECK(m == 10);
}

TEST_CASE("MaxEven - усі парні від'ємні")
{
    int a[4] = { -8, -2, -6, -4 };
    int m = 0;
    CHECK(MaxEven(a, 4, m) == true);
    CHECK(m == -2);
}

TEST_CASE("MaxEven - немає парних")
{
    int a[5] = { 3, -5, 7, 1, -9 };
    int m = 0;
    CHECK(MaxEven(a, 5, m) == false);
}

TEST_CASE("Create - int")
{
    int a[50];
    Create(a, 50, -50, 50);
    for (int i = 0; i < 50; i++)
    {
        CHECK(a[i] >= -50);
        CHECK(a[i] <= 50);
    }
}

// ---------- 2) шаблони функцій ----------

TEST_CASE("MaxEven<int>")
{
    int a[6] = { 3, 8, -4, 7, 10, 1 };
    int m = 0;
    CHECK(MaxEven<int>(a, 6, m) == true);
    CHECK(m == 10);
}

TEST_CASE("MaxEven<int> - немає парних")
{
    int a[5] = { 3, -5, 7, 1, -9 };
    int m = 0;
    CHECK(MaxEven<int>(a, 5, m) == false);
}

TEST_CASE("MaxEven<long long>")
{
    long long a[6] = { 3, 8, -4, 7, 10, 1 };
    long long m = 0;
    CHECK(MaxEven<long long>(a, 6, m) == true);
    CHECK(m == 10);
}

TEST_CASE("MaxEven<long long> - немає парних")
{
    long long a[5] = { 3, -5, 7, 1, -9 };
    long long m = 0;
    CHECK(MaxEven<long long>(a, 5, m) == false);
}

TEST_CASE("Create<long long>")
{
    long long a[50];
    Create<long long>(a, 50, -50, 50);
    for (int i = 0; i < 50; i++)
    {
        CHECK(a[i] >= -50);
        CHECK(a[i] <= 50);
    }
}