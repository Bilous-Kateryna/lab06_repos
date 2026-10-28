#include <iostream>
#include <iomanip>
#include <time.h>
#include <cassert>
 
using namespace std;
 
// Рекурсивно створює масив: елементи - випадкові числа з діапазону [Low, High]
void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}
 
// Рекурсивно виводить масив у вигляді рядка
void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}
 
// Рекурсивно шукає індекс найменшого непарного елемента масиву.
// imin - індекс найменшого непарного серед переглянутих (на початку -1).
// Якщо непарних елементів немає - повертає -1
int IndexMinOdd(int* a, const int size, int i, int imin)
{
    if (a[i] % 2 != 0 && (imin == -1 || a[i] < a[imin]))
        imin = i;
 
    if (i < size - 1)
        return IndexMinOdd(a, size, i + 1, imin);
    else
        return imin;
}
 
int main()
{
    srand((unsigned)time(NULL));   // ініціалізація генератора випадкових чисел
 
    const int n = 15;
    int a[n];
 
    int Low = -20;
    int High = 30;
 
    Create(a, n, Low, High, 0);
    cout << "Масив:" << endl;
    Print(a, n, 0);
 
    int imin = IndexMinOdd(a, n, 0, -1);
    if (imin == -1)
        cout << "У масиві немає непарних елементів" << endl;
    else
        cout << "Індекс найменшого непарного елемента: " << imin
             << " (a[" << imin << "] = " << a[imin] << ")" << endl;
 
    return 0;
}
