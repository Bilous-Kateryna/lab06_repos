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
 
// Перевіряє критерій варіанту 2: елемент додатний або не кратний 3
bool Check(const int x)
{
    return x > 0 || x % 3 != 0;
}
 
// Рекурсивно обчислює кількість елементів, які задовольняють критерію
int Count(int* a, const int size, int i)
{
    if (i < size)
    {
        if (Check(a[i]))
            return 1 + Count(a, size, i + 1);
        else
            return Count(a, size, i + 1);
    }
    else
        return 0;
}
 
// Рекурсивно обчислює суму елементів, які задовольняють критерію
int Sum(int* a, const int size, int i)
{
    if (i < size)
    {
        if (Check(a[i]))
            return a[i] + Sum(a, size, i + 1);
        else
            return Sum(a, size, i + 1);
    }
    else
        return 0;
}
 
// Рекурсивно замінює нулями елементи, які задовольняють критерію
void Zero(int* a, const int size, int i)
{
    if (Check(a[i]))
        a[i] = 0;
    if (i < size - 1)
        Zero(a, size, i + 1);
}
 
int main()
{
    srand((unsigned)time(NULL));   // ініціалізація генератора випадкових чисел
 
    const int n = 22;
    int a[n];
 
    int Low = -10;
    int High = 35;
 
    Create(a, n, Low, High, 0);
    cout << "Початковий масив:" << endl;
    Print(a, n, 0);
 
    cout << "Кількість елементів: " << Count(a, n, 0) << endl;
    cout << "Сума елементів:      " << Sum(a, n, 0) << endl;
 
    Zero(a, n, 0);
    cout << "Змінений масив:" << endl;
    Print(a, n, 0);
 
    return 0;
}
