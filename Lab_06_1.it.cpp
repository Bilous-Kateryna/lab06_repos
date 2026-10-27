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
 
// Перевіряє критерій: елемент додатний або не кратний 3
bool Check(const int x)
{
    return x > 0 || x % 3 != 0;
}
 
// Обчислює кількість елементів, які задовольняють критерію
int Count(int* a, const int size)
{
    int k = 0;
    for (int i = 0; i < size; i++)
        if (Check(a[i]))
            k++;
    return k;
}
 
// Обчислює суму елементів, які задовольняють критерію
int Sum(int* a, const int size)
{
    int S = 0;
    for (int i = 0; i < size; i++)
        if (Check(a[i]))
            S += a[i];
    return S;
}
 
// Замінює нулями елементи, які задовольняють критерію
void Zero(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        if (Check(a[i]))
            a[i] = 0;
}
 
int main()
{
    srand((unsigned)time(NULL));   // ініціалізація генератора випадкових чисел
 
    const int n = 22;
    int a[n];
 
    int Low = -10;
    int High = 35;
 
    Create(a, n, Low, High);
    cout << "Початковий масив:" << endl;
    Print(a, n);
 
    cout << "Кількість елементів: " << Count(a, n) << endl;
    cout << "Сума елементів:      " << Sum(a, n) << endl;
 
    Zero(a, n);
    cout << "Змінений масив:" << endl;
    Print(a, n);
 
    return 0;
}
