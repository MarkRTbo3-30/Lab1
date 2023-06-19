#include <iostream>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <math.h>

using namespace std;

const int N=10;

//Шаблон для ввода матрицы 10*10
template<typename T>

void CinMassive(T A[][N], T n)
{
	int x;
	cout << "Если хотите заполнить матрицу случайными числами на жмите 1, если хотите заполнить вручную нажмите 2" << endl;

	int a = _getch();  // считывание символа с клавиатуры
	srand(time(NULL)); // функция для генерации разных рандомных чисел

	if (a == '1')      // ввод матрицы случайных чисел от 0 до 100
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
			
				A[i][j] = rand() % 100;
	}

	if (a == '2')      // заполнение матрицы вручную
	{
		cout << "Заполнение массива" << endl;
		for (int i = 0; i < n; ++i)
		    for (int j = 0; j < n; ++j)
			{
		   		cout << "Введите элемент A" << i << j << " = ";
				cin >> x;
				A[i][j] = x;
			}
	}
}
//Шаблон для вывода двумерного массива
template<typename T>
void CoutMassive(T A[][N], T n)
{
	cout << "Вывод массива на экран" << endl;
	
	for (int i = 0; i < n; ++i)
	{
		
		for (int j = 0; j < n; ++j)
		{
			cout << "A" << i << j << " = " << setw(3) << A[i][j] << "   ";
		}
		cout << endl;
	}
}
// Шаблон для обработки двумерного массива
// Необходимо найти все положительные элементы матрицы и найти среднее арифметическое
template<typename T>
float Arifm(T A[][N], T n)
{
    float SUMM = 0.0;
	float KOLICHESVO = 0.0;
	float SR;
	for (int i = 0; i<n; i++)
		for(int j = 0; j < n; j++)
			if (A[i][j] > 0)
			{
				KOLICHESVO++;
				SUMM = SUMM + A[i][j];
			}
	SR = SUMM / KOLICHESVO;
	return SR;
	}
// ************************Основная функция**********************************************
int main()
{
	setlocale(LC_ALL, "rus");
    float SrArifm;
	int n;
	int A[N][N];
	int Finish = 0;
    float SR;
	cout << "Лабораторная №1" << endl;
	cout << "Нажмите Enter чтобы начать" << endl;

	do 
	{
    Finish = _getch();
		cout << "Введите порядок матрицы = ";
		cin >> n;

		if (n > N)
		{
			cout << "Порядок матрицы не может превышать число 10, введите число от 0 до 10" << N << endl;
			while (n > N) 
			{ 
			    cin >> n;
			    cout << "Введите число от 0 до 10 " << N << endl;
		    }
		}

		CinMassive<int>(A, n);
		
		CoutMassive<int>(A, n);
		
        cout << "Среднее арифметическое положительных элементов матрицы = "<<Arifm( A, n) <<endl;
        
		cout << "Для выхода нажмите клавишу Esc" << endl;
		system("cls");
		cout << "Для повтора нажмите любую клавишу" << endl;
		Finish = _getch();
	 }
	 while (Finish != 27);
	  
	return 0;
}
