#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(5) << a[i];
    cout << endl;
}

// знаходить найбільший з парних елементів масиву;
bool MaxEven(int* a, const int size, int& maxEven)
{
    bool found = false;     // чи знайдено хоча б один парний елемент
    for (int i = 0; i < size; i++)
        if (a[i] % 2 == 0 && (!found || a[i] > maxEven))
        {
            maxEven = a[i];
            found = true;
        }
    return found;
}

//2)

template <typename T>
void Create(T* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = (T)(Low + rand() % (High - Low + 1));
}

template <typename T>
void Print(T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(5) << a[i];
    cout << endl;
}

template <typename T>
bool MaxEven(T* a, const int size, T& maxEven)
{
    bool found = false;
    for (int i = 0; i < size; i++)
        if (a[i] % 2 == 0 && (!found || a[i] > maxEven))
        {
            maxEven = a[i];
            found = true;
        }
    return found;
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 15;       
    int Low = -50;          
    int High = 50;          

    // 1) звичайні функції, масив типу int
    int a[n];
    Create(a, n, Low, High);
    Print(a, n);
    int maxA;
    if (MaxEven(a, n, maxA))
        cout << "MaxEven = " << maxA << endl;
    cout << endl;

    // 2) шаблони функцій, масив типу int
    int b[n];
    Create<int>(b, n, Low, High);
    Print<int>(b, n);
    int maxB;
    if (MaxEven<int>(b, n, maxB))
        cout << "MaxEven<int> = " << maxB << endl;
    cout << endl;
    
    // 2) шаблони функцій, масив типу long long
    long long c[n];
    Create<long long>(c, n, Low, High);
    Print<long long>(c, n);
    long long maxC;
    if (MaxEven<long long>(c, n, maxC))
        cout << "MaxEven<long long> = " << maxC << endl;

    return 0;
}
