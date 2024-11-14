/*
  Задание:
  Автор: Чучалин Иван Валентинович  Группа: 4354  Версия программы: 5
  Дата начала: 07.11.24  Завершения: 00.11.24
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <locale>
#include <math.h>
using namespace std;
const unsigned N = 20, M = N;
void main(void)
{
	setlocale(LC_ALL, "russian");
	fstream g, f; float A[N][M]; unsigned a, b, h = 0, size = 0, i = 0, j = 0; char s = '!'; float tmp;
	g.open("out.txt", ios::out);
	f.open("in.txt", ios::in);
	if (!f.is_open())
	{
		g << "file not opened";
	}
	else
	{
		f >> a;
		if ((f.eof()) || (a <= 0))
		{
			a = 0;
			b = 0;
		}
		else if (a > N) a = N;
		b = a;
		while (!f.eof() && s != '\n')
		{
			f << skipws;
			f >> tmp;
			f << noskipws;
			if (f.eof())
			{
				h++;
				if (b > size) b = size;
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
						if (b > size) b = size;
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
					if (b > size)
					{
						b = size;
						size = 0;
					}
					s = '!';
				}
			}
		}
	}
	if (a < b)a = b;
	if (b < a)b = a;
	f.close();g.close();
}

/*
bool CalcSize(char Name[20], unsigned &a, unsigned *b, fstream& g);
bool InpF(char Name[20], unsigned a, unsigned b, float A[N][M], fstream &g);
void Out1(float A[N][M], unsigned a, unsigned b, fstream &g);
void OutStroke(unsigned b, fstream &g, float A[M]);
void Out2(fstream &g, int Number);
int Process(float A[N][M], unsigned a, unsigned b);

void main(void)
{
	setlocale(LC_ALL, "russian");
	fstream g; float A[N][M]; unsigned a, b; char Name[20];
	g.open("out.txt", ios::out);
	if (!g.is_open()) cout << "File is not opened\n";
	else
	{
		if (CalcSize(Name, a, &b, g) == false)
		{
			cout << "Не удалось считать размер\n";
		}
		else
		{
			if (InpF(Name, a, b, A, g) == false)
			{
				cout << "Ошибка обработки";
			}
			else
			{
				Out1(A, a, b, g);
				//Out2(g, Process(A, a, b));
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
void Out1(float A[N][M], unsigned a, unsigned b, fstream& g)
{
	unsigned i;
	for (i = 0; i < a; i++) OutStroke(b, g, A[i]);
}
void Out2(fstream& g, int Number)
{

}
bool CalcSize(char Name[20], unsigned& a, unsigned* b, fstream& g)
{
	fstream f; unsigned h = 0, size = 0; char s[] = "Hello"; float tmp;
	f.open("in.txt", ios::in);
	if (!f.is_open())
	{
		g << " ";
		return false;
	}
	else
	{
		f >> a;
		if ((f.eof()) || (a < 0) || (a == 0))
		{
			a = 0;
			*b = 0;
			return true;
		}
		else if (a > N) a = N;
		*b = a;
		f << noskipws;
		while (!f.eof() && s != "\n")
		{
			f << skipws;
			f >> tmp;
			f << noskipws;
			if (f.eof())
			{
				h++;
				if (*b > size) *b = size;
				else
				{
					size++;
					f >> s;
					while (s == " " || s == "\t" && s != "\n" && !f.eof())
					{
						f >> s;
						if (f.eof() || s == "\n")
						{
							h++;
							if (*b > size) *b = size;
						}
					}
					if (s != "\n" || !f.eof()) f.seekg(-1, ios::cur);
					else if (s == "\n")
					{
						h++;
						if (*b > size)
						{
							*b = size;
							size = 0;
						}
					}
				}
			}
			if (h < a)a = h;
		}
	}
	f.close();
	if (a < *b)a = *b;
	if (*b < a)*b = a;
}
bool InpF(char Name[20], unsigned a, unsigned b, float A[N][M], fstream& g)
{
	fstream f; unsigned i, j; char s[] = "Hello";
	if (f.eof()) return false;
	for (i = 0; i < a; i++)
	{
		f << skipws;
		for (j = 0; j < b; j++)A[i][j];
		f << noskipws;
		while (!f.eof() && s != "\n") f >> s;
	}
	return true;
}
int Process(float A[N][M], unsigned a, unsigned b)
{
	return 0;
}
*/

