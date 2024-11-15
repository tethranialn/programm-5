/*
  �������:
  �����: ������� ���� ������������  ������: 4354  ������ ���������: 5
  ���� ������: 07.11.24  ����������: 00.11.24
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <locale>
#include <math.h>
using namespace std;
const unsigned N = 20, M = N;

bool CalcSize( unsigned &a, unsigned *b, fstream& g);
bool InpF( unsigned a, unsigned b, float A[N][M], fstream &g);
void Out(float A[N][M], unsigned a, unsigned b, fstream &g);
void OutStroke(unsigned b, fstream &g, float A[M]);
int Process(float A[N][M], unsigned a, unsigned b);
bool InM(int& m, unsigned a, fstream& g);
bool InK(int& k, unsigned a, fstream& g);
void main(void)
{
	setlocale(LC_ALL, "russian");
	fstream g; float A[N][M]; unsigned a, b; char Name[20]; int m, k;
	g.open("out.txt", ios::out);
	if (!g.is_open()) cout << "File is not opened\n";
	else
	{
		if (CalcSize( a, &b, g) == false)
		{
			cout << "�� ������� ������� ������\n";
			g << "�� ������� ������� ������\n";
		}
		else
		{
			if (InpF( a, b, A, g) == false)
			{
				cout << "������ ���������\n";
				g << "������ ���������\n";
			}
			else
			{
				cout << "��� ����� ���������� m � k ����������, ��� ���������� �������� � ����� ���������� � �������.\n";
				cout << "����� �� ���������, ��� �������� �������� ������ ���� ������.\n";
				g << "�������:\n�����: ������� ���� ������������\t������ : 4354\t������ ��������� : 5\n���� ������ : 07.11.24\t���������� : 00.11.24\n";
				g << "��� ����� ���������� m � k ����������, ��� ���������� �������� � ����� ���������� � �������.\n";
				g << "����� �� ���������, ��� �������� �������� ������ ���� ������.\n";
				g << "���� ������������ ������������ �������:\n";
				Out(A, a, b, g);
				cout << "������� m\n";
				cin >> m;
				if (InM(m, a, g) == false)
				{
					cout << "������� ������������ ��������� ���������. ������������� ���������.\n";
					g << "������� ������������ ��������� ���������. ������������� ���������.\n";
				}
				else
				{
					cout << "������� k\n";
					cin >> k;
					if (InK(k, a, g) == false)
					{
						cout << "������� ������������ ��������� ���������. ������������� ���������.\n";
						g << "������� ������������ ��������� ���������. ������������� ���������.\n";
					}
					else
					{
						g << "��������� m: " << m << "\t��������� k: " << k << "\n";
						Process(A, a, b);
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
bool CalcSize( unsigned& a, unsigned* b, fstream& g)
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
		f >> a;
		if ((f.eof()) || (a <= 0))
		{
			a = 0;
			*b = 0;
		}
		else if (a > N) a = N;
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
		return true;
		f.close();
	}
}
bool InpF(unsigned a, unsigned b, float A[N][M], fstream& g)
{
	fstream f; unsigned i, j; char s = '!';
	f.open("in.txt", ios::in);
	if (f.eof()) return false;
	for (i = 0; i < a; i++)
	{
		f << skipws;
		for (j = 0; j < b; j++) f >> A[i][j];
		f << noskipws;
		s = '!';
		while (!f.eof() && s != '\n') f >> s;
	}
	f.close();
	return true;
}
int Process(float A[N][M], unsigned a, unsigned b)
{
	unsigned i, j; 
	return 0;
}
bool InM(int& m,unsigned a, fstream& g)
{
	if (m-1 < 0)
	{
		cout << "�������� m �� ����� ���� ������ ��� ����� ����.\n";
		g << "��������� m: " << m << "\t�������� m �� ����� ���� ������ ��� ����� ����.\n";
		return false;
	}
	else if (m > a)
	{
		cout << "�������� m �� ����� ���� ������ ����������� ��������.\n";
		g << "��������� m: " << m << "\t�������� m �� ����� ���� ������ ����������� ��������.\n";
		return false;
	}
	else return true;
}
bool InK(int& k, unsigned a, fstream& g)
{
	if (k - 1 < 0)
	{
		cout << "�������� k �� ����� ���� ������ ��� ����� ����.\n";
		g << "��������� k: " << k << "\t�������� k �� ����� ���� ������ ��� ����� ����.\n";
		return false;
	}
	else if (k > a)
	{
		cout << "�������� k �� ����� ���� ������ ����������� �����.\n";
		g << "��������� k: " << k << "\t�������� k �� ����� ���� ������ ����������� �����.\n";
		return false;
	}
	else return true;
}


