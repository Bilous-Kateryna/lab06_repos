#include <iostream>
#include <iomanip>
#include <time.h>
#include <cassert>
 
using namespace std;
 
// Створює масив: елементи - випадкові числа з діапазону [Low, High]
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}
 
// Виводить масив у вигляді рядка
void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}
 
// Шукає індекс найменшого непарного елемента масиву.
// Якщо непарних елементів немає - повертає -1
int IndexMinOdd(int* a, const int size)
{
    int imin = -1;                        // індекс найменшого непарного
    for (int i = 0; i < size; i++)
        if (a[i] % 2 != 0 && (imin == -1 || a[i] < a[imin]))
            imin = i;
    return imin;
}
 

int main()
{
    srand((unsigned)time(NULL));   // ініціалізація генератора випадкових чисел

    const int n = 15;
    int a[n];
 
    int Low = -20;
    int High = 30;
 
    Create(a, n, Low, High);
    cout << "Масив:" << endl;
    Print(a, n);
 
    int imin = IndexMinOdd(a, n);
    if (imin == -1)
        cout << "У масиві немає непарних елементів" << endl;
    else
        cout << "Індекс найменшого непарного елемента: " << imin
             << " (a[" << imin << "] = " << a[imin] << ")" << endl;
 
    return 0;
}
