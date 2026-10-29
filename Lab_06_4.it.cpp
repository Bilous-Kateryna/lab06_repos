#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>

using namespace std;

// формує масив a з n дійсних випадкових чисел з діапазону [Low; High]
void Create(double* a, const int n, const double Low, const double High)
{
    for (int i = 0; i < n; i++)
        a[i] = Low + (High - Low) * rand() / RAND_MAX;
}

// виводить масив a у вигляді рядка
void Print(double* a, const int n)
{
    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++)
        cout << setw(7) << a[i];
    cout << endl;
}

// 1.1. обчислює суму додатних елементів масиву
double SumPositive(double* a, const int n)
{
    double S = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > 0)
            S += a[i];
    return S;
}

// повертає індекс максимального за модулем елемента
int IndexMaxAbs(double* a, const int n)
{
    int iMax = 0;
    for (int i = 1; i < n; i++)
        if (fabs(a[i]) > fabs(a[iMax]))
            iMax = i;
    return iMax;
}

// повертає індекс мінімального за модулем елемента
int IndexMinAbs(double* a, const int n)
{
    int iMin = 0;
    for (int i = 1; i < n; i++)
        if (fabs(a[i]) < fabs(a[iMin]))
            iMin = i;
    return iMin;
}

// обчислює добуток елементів, розташованих строго між індексами i1 та i2;
// повертає false, якщо між ними немає жодного елемента
bool ProductBetween(double* a, const int i1, const int i2, double& P)
{
    int from = (i1 < i2 ? i1 : i2) + 1;     // перший індекс проміжку
    int to = (i1 < i2 ? i2 : i1);         // індекс, що вже не входить у проміжок
    if (from >= to)
        return false;
    P = 1;
    for (int i = from; i < to; i++)
        P *= a[i];
    return true;
}


// впорядковує непарні елементи за спаданням, парні залишаються на місці
void SortOddDesc(double* b, int n)
{

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (int(b[i]) % 2 != 0 && int(b[j]) % 2 != 0 && b[j] > b[i])
            {
                double tmp = b[i];
                b[i] = b[j];
                b[j] = tmp;
            }
}

int main()
{
    srand((unsigned)time(NULL));

    int n;                          // кількість елементів масиву
    cout << "n = "; cin >> n;

    double* a = new double[n];      // динамічний масив
    double Low = -10, High = 10;    // діапазон значень елементів

    Create(a, n, Low, High);
    Print(a, n);

    cout << "1.1. = " << SumPositive(a, n) << endl;

    int iMax = IndexMaxAbs(a, n);
    int iMin = IndexMinAbs(a, n);
    cout << "     max |a| : a[" << iMax << "] = " << a[iMax] << endl;
    cout << "     min |a| : a[" << iMin << "] = " << a[iMin] << endl;

    double P;
    if (ProductBetween(a, iMax, iMin, P))
        cout << "1.2. Product between = " << P << endl;

    SortOddDesc(a, n);
    cout << "2. " << endl;
    Print(a, n);

    delete[] a;
    return 0;
}