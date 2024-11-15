/*
  Автор: Чучалин Иван Валентинович  Группа: 4354  Версия программы: 5
  Дата начала: 07.11.24  Завершения: 00.11.24
  Задание: Найти наибольший элемент заштрихованной области таблицы вида:
									m
						  [ ][ ][ ][x][x][x][x] k
						  [ ][ ][x][x][x][x][ ]
						  [ ][x][x][x][x][ ][ ]
						  [x][x][x][x][ ][ ][ ]
						  [x][x][x][ ][ ][ ][ ]
						  [x][x][ ][ ][ ][ ][ ]
						  [x][ ][ ][ ][ ][ ][ ]
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <locale>
#include <math.h>
using namespace std;
const unsigned N = 20, M = N;
bool CalcSize(unsigned &a, unsigned *b, fstream& g, int& raz);
bool InpF(unsigned a, unsigned b, float A[N][M], fstream &g);
void Out(float A[N][M], unsigned a, unsigned b, fstream &g);
void OutStroke(unsigned b, fstream &g, float A[M]);
int Process(float A[N][M], unsigned a, unsigned b, int m, int k, float& result);
bool InM(int& m, unsigned a, fstream& g);
bool InK(int& k, unsigned a, fstream& g);
void main(void)
{
	setlocale(LC_ALL, "russian");
	fstream g; float A[N][M], result = 0; unsigned a, b; char Name[20]; int m, k, raz = 0;
	g.open("out.txt", ios::out);
	if (!g.is_open()) cout << "File is not opened\n";
	else
	{
		if (CalcSize( a, &b, g, raz) == false)
		{
			cout << "Не удалось считать размер\n";
			g << "Не удалось считать размер\n";
		}
		else
		{
			if (InpF( a, b, A, g) == false)
			{
				cout << "Ошибка обработки\n";
				g << "Ошибка обработки\n";
			}
			else
			{
				cout << "При вводе параметров m и k учитывайте, что исчисление столбцов и строк начинается с единицы.\n";
				cout << "Также не забывайте, что вводимые значения должны быть целыми.\n\n";
				cout << "			          m\n";
				cout << "			[ ][ ][ ][x][x][x][x] k\n";
				cout << "			[ ][ ][x][x][x][x][ ]\n";
				cout << "			[ ][x][x][x][x][ ][ ]\n";
				cout << "			[x][x][x][x][ ][ ][ ]\n";
				cout << "			[x][x][x][ ][ ][ ][ ]\n";
				cout << "			[x][x][ ][ ][ ][ ][ ]\n";
				cout << "			[x][ ][ ][ ][ ][ ][ ]\n\n";
				g << "Автор: Чучалин Иван Валентинович\tГруппа : 4354\tВерсия программы : 5\nДата начала : 07.11.24\tЗавершения : 00.11.24\n";
				g << "Задание: Найти наибольший элемент заштрихованной области таблицы вида:\n\n";
				g << "					          m\n";
				g << "					[ ][ ][ ][x][x][x][x] k\n";
				g << "					[ ][ ][x][x][x][x][ ]\n";
				g << "					[ ][x][x][x][x][ ][ ]\n";
				g << "					[x][x][x][x][ ][ ][ ]\n";
				g << "					[x][x][x][ ][ ][ ][ ]\n";
				g << "					[x][x][ ][ ][ ][ ][ ]\n";
				g << "					[x][ ][ ][ ][ ][ ][ ]\n\n";
				g << "Указанная размерность матрицы: " << raz << "*" << raz << "\n";
				g << "Ниже представлена обработанная матрица:\n";
				Out(A, a, b, g);
				g << "Реальная размерность матрицы: " << a << "*" << a << ".\n";
				cout << "Введите m\n";
				cin >> m;
				if (InM(m, a, g) == false)
				{
					cout << "Введены неправильные параметры обработки. Перезапустите программу.\n";
					g << "Введены неправильные параметры обработки. Перезапустите программу.\n";
				}
				else
				{
					cout << "Введите k\n";
					cin >> k;
					if (InK(k, a, g) == false)
					{
						cout << "Введены неправильные параметры обработки. Перезапустите программу.\n";
						g << "Введены неправильные параметры обработки. Перезапустите программу.\n";
					}
					else
					{
						g << "Введенное m: " << m << "\tВведенное k: " << k << "\n";
						Process(A, a, b, m, k, result);
						cout << "Результат обработки массива: " << result << "\n";
						g << "Результат обработки массива: " << result << "\n";
					}
				}
			}
		}
	}
	g.close();
}
void OutStroke(unsigned b, fstream& g, float A[M])
{
	unsigned i; 
	for (i = 0; i < b; i++) g << A[i] << " ";
	g << "\n";
}
void Out(float A[N][M], unsigned a, unsigned b, fstream& g)
{
	unsigned i;
	for (i = 0; i < a; i++) OutStroke(b, g, A[i]);
}
bool CalcSize(unsigned& a, unsigned* b, fstream& g, int& raz)
{
	fstream f; unsigned h = 0, size = 0; char s = '!'; float tmp;
	f.open("in.txt", ios::in);
	if (!f.is_open())
	{
		g << "file not opened";
		f.close();
		return false;
	}
	else
	{
		f >> tmp;
		if ((f.eof()) || (tmp <= 0))
		{
			a = 0;
			*b = 0;
			raz = a;
		}
		else if (tmp > N)
		{
			a = N;
			raz = a;
		}
		else a = tmp;
		raz = a;
		*b = a;
		while (!f.eof() && s != '\n')
		{
			f << skipws;
			f >> tmp;
			f << noskipws;
			if (f.eof())
			{
				h++;
				if (*b > size) *b = size;
			}
			else
			{
				size++;
				f >> s;
				while ((s == ' ' || s == '\t') && s != '\n' && !f.eof())
				{
					f >> s;
					if (f.eof() || s == '\n')
					{
						h++;
						if (*b > size) *b = size;
						if (h < a)a = h;
						s = '!';
					}
				}
				if (s != '\n' || !f.eof())
				{
					f.seekg(-1, ios::cur);
					s = '!';
				}
				else if (s == '\n')
				{
					h++;
					if (*b > size)
					{
						*b = size;
						size = 0;
					}
					s = '!';
				}
			}
		}
		if (a < *b)a = *b;
		if (*b < a)*b = a;
		f.close();
		return true;
	}
}
bool InpF(unsigned a, unsigned b, float A[N][M], fstream& g)
{
	fstream f; unsigned i, j; char s = '!'; float tmp;
	f.open("in.txt", ios::in);
	if (f.eof()) return false;
	else
	{
		f >> tmp;
		for (i = 0; i < a; i++)
		{
			f << skipws;
			for (j = 0; j < b; j++) f >> A[i][j];
			f << noskipws;
			s = '!';
			while (!f.eof() && s != '\n') f >> s;
		}
		return true;
	}
	f.close();
}
bool InM(int& m,unsigned a, fstream& g)
{
	if (m-1 < 0)
	{
		cout << "Значение m не может быть меньше или равно нулю.\n";
		g << "Введенное m: " << m << "\tЗначение m не может быть меньше или равно нулю.\n";
		return false;
	}
	else if (m > a)
	{
		cout << "Значение m не может быть больше колличества столбцов.\n";
		g << "Введенное m: " << m << "\tЗначение m не может быть больше колличества столбцов.\n";
		return false;
	}
	else return true;
}
bool InK(int& k, unsigned a, fstream& g)
{
	if (k - 1 < 0)
	{
		cout << "Значение k не может быть меньше или равно нулю.\n";
		g << "Введенное k: " << k << "\tЗначение k не может быть меньше или равно нулю.\n";
		return false;
	}
	else if (k > a)
	{
		cout << "Значение k не может быть больше колличества строк.\n";
		g << "Введенное k: " << k << "\tЗначение k не может быть больше колличества строк.\n";
		return false;
	}
	else return true;
}
int Process(float A[N][M], unsigned a, unsigned b, int m, int k, float& result)
{
	unsigned i, j;
	result = 1982370;
	return result;
}