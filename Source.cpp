// Lab_7_3.cpp
// < Kolmykova Kateryna >
// Лабораторна робота № 7.3.
// Опрацювання динамічних багатовимірних масивів. Ітераційний спосіб.
// Варіант 12
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Input(int** a, const int k, const int n);
void Print(int** a, const int k, const int n);
void NullS(int** a, const int k, const int n);
int Num(int** a, const int n);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -20;
	int High = 20;
	int k, n;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;
	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];
	Input(a, k, n);
	Print(a, k, n);
	NullS(a, k, n);
	Print(a, k, n);
	cout << "Num=" << Num(a, n);
	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Input(int** a, const int k, const int n)
{
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}
void Print(int** a, const int k, const int n)
{
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
void NullS(int** a, const int k, const int n)
{
	for (int i = 0; i < k; i++)
	{
		int f = 0;
			for (int j = 0; j < n; j++)
				if (a[i][j] == 0)
					delete a[j];
		f++;
	}
}
int Num(int** a, const int n)
{
	int j = 0;
	int index=j;
	int i = 0;
	for (int j = 0; j < n; j++)
	{
		if (a[i][j] > 0)
			index = j;
		i++;
	}
	return index;
}