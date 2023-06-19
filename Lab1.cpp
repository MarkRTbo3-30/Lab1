#include <iostream>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <math.h>

using namespace std;

const int N=10;

//������ ��� ����� ������� 10*10
template<typename T>

void CinMassive(T A[][N], T n)
{
	int x;
	cout << "���� ������ ��������� ������� ���������� ������� �� ����� 1, ���� ������ ��������� ������� ������� 2" << endl;

	int a = _getch();  // ���������� ������� � ����������
	srand(time(NULL)); // ������� ��� ��������� ������ ��������� �����

	if (a == '1')      // ���� ������� ��������� ����� �� 0 �� 100
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
			
				A[i][j] = rand() % 100;
	}

	if (a == '2')      // ���������� ������� �������
	{
		cout << "���������� �������" << endl;
		for (int i = 0; i < n; ++i)
		    for (int j = 0; j < n; ++j)
			{
		   		cout << "������� ������� A" << i << j << " = ";
				cin >> x;
				A[i][j] = x;
			}
	}
}
//������ ��� ������ ���������� �������
template<typename T>
void CoutMassive(T A[][N], T n)
{
	cout << "����� ������� �� �����" << endl;
	
	for (int i = 0; i < n; ++i)
	{
		
		for (int j = 0; j < n; ++j)
		{
			cout << "A" << i << j << " = " << setw(3) << A[i][j] << "   ";
		}
		cout << endl;
	}
}
// ������ ��� ��������� ���������� �������
// ���������� ����� ��� ������������� �������� ������� � ����� ������� ��������������
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
// ************************�������� �������**********************************************
int main()
{
	setlocale(LC_ALL, "rus");
    float SrArifm;
	int n;
	int A[N][N];
	int Finish = 0;
    float SR;
	cout << "������������ �1" << endl;
	cout << "������� Enter ����� ������" << endl;

	do 
	{
    Finish = _getch();
		cout << "������� ������� ������� = ";
		cin >> n;

		if (n > N)
		{
			cout << "������� ������� �� ����� ��������� ����� 10, ������� ����� �� 0 �� 10" << N << endl;
			while (n > N) 
			{ 
			    cin >> n;
			    cout << "������� ����� �� 0 �� 10 " << N << endl;
		    }
		}

		CinMassive<int>(A, n);
		
		CoutMassive<int>(A, n);
		
        cout << "������� �������������� ������������� ��������� ������� = "<<Arifm( A, n) <<endl;
        
		cout << "��� ������ ������� ������� Esc" << endl;
		system("cls");
		cout << "��� ������� ������� ����� �������" << endl;
		Finish = _getch();
	 }
	 while (Finish != 27);
	  
	return 0;
}

