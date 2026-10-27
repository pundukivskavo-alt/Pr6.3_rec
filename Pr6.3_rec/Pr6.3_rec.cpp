// Лабораторна робота № 6. Завдання 6.3 (рекурсивний спосіб). Варіант 20
// Функція знаходить найбільший з елементів масиву:
// 1) звичайна функція; 2) шаблон функції.
#include <iostream>
#include<iomanip>
#include <string>

using namespace std;

template <typename T>
void Print(T* a, const int size, int i);

int Max(int* a, const int size, int i,int max);

template <typename T>
T Max(T* a, const int size, int i, T max);

int main()
{
	const int n = 10;
	int a[n]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	Print(a, n, 0);

	int m1 = Max(a, n, 0,a[0]);
	cout << "Max = " << m1 << endl;

	int m2 = Max<int>(a, n, 0, a[0]);
	cout << "Max<int> = " << m2 << endl;

	double b[n] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10 };
	Print(b, n, 0);

	double m3 = Max(b, n, 0, b[0]);
	cout << "Max<double> = " << m3 << endl;

	string c[n] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
	Print(c, n, 0);

	string m4 = Max(c, n, 0, c[0]);
	cout << "Max<string> = " << m4 << endl;
	
	return 0;


}    


// Виведення масиву будь-якого типу в один рядок
template <typename T>
void Print(T* a, const int size, int i)
{
	if (i < size)
	{
		cout << setw(6) << a[i];
		Print(a, size, i + 1);

	}
	else
		cout << endl;
}

// Пошук найбільшого елемента масиву цілих чисел

int Max(int* a, const int size, int i, int max)
{
	if (a[i] > max)
		max = a[i];
	if (i < size - 1)
		return Max(a, size, i + 1, max);
	else
		return max;
}

// Шаблон пошуку найбільшого елемента масиву будь-якого типу
template <typename T>
T Max (T *a, const int size, int i, T max)
{
	if (a[i] > max)
		max = a[i];
	if (i < size - 1)
		return Max<T>(a, size, i + 1, max);
	else
		return max;
}