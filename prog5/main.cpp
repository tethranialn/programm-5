/*
  �����: ������� ���� ������������  ������: 4354  ������ ���������: 5
  ���� ������: 07.11.24  ����������: 17.11.24
  �������: ����� ���������� ������� �������������� ������� ������� ����:
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
const unsigned N = 10, M = N;
bool CalcSize(unsigned &a, unsigned *b, fstream& g, int& raz);
bool InpF(unsigned a, unsigned b, float A[N][M], fstream &g);
void Out(float A[N][M], unsigned a, unsigned b, fstream &g);
void OutStroke(unsigned b, fstream &g, float A[M]);
float Process(float A[N][M], unsigned a, unsigned b, int m, int k, float& result);
bool InM(int& m, unsigned a, fstream& g);
bool InK(int& k, unsigned a, fstream& g);
void main(void)
{
	setlocale(LC_ALL, "russian");
	fstream g; float A[N][M], result = 0; unsigned a, b;int m, k, raz = 0;
	g.open("out.txt", ios::out);
	if (!g.is_open()) cout << "File is not opened\n";
	else
	{
		if (CalcSize( a, &b, g, raz) == false)
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
				if (raz == 1337)
				{
					cout << "���� ����.\n";
					g << "���� ����.\n";
					return;
				}
				cout << "��� ����� ���������� m � k ����������, ��� ���������� �������� � ����� ���������� � �������.\n";
				cout << "����� �� ���������, ��� �������� �������� ������ ���� ������, �������������� � ������ ��� ����� ���������� �����/��������.\n\n";
				cout << "			          m\n";
				cout << "			[ ][ ][ ][x][x][x][x] k\n";
				cout << "			[ ][ ][x][x][x][x][ ]\n";
				cout << "			[ ][x][x][x][x][ ][ ]\n";
				cout << "			[x][x][x][x][ ][ ][ ]\n";
				cout << "			[x][x][x][ ][ ][ ][ ]\n";
				cout << "			[x][x][ ][ ][ ][ ][ ]\n";
				cout << "			[x][ ][ ][ ][ ][ ][ ]\n\n";
				g << "�����: ������� ���� ������������\t������ : 4354\t������ ��������� : 5\n���� ������ : 07.11.24\t���������� : 17.11.24\n";
				g << "�������: ����� ���������� ������� �������������� ������� ������� ����:\n\n";
				g << "		          m\n";
				g << "		[ ][ ][ ][x][x][x][x] k\n";
				g << "		[ ][ ][x][x][x][x][ ]\n";
				g << "		[ ][x][x][x][x][ ][ ]\n";
				g << "		[x][x][x][x][ ][ ][ ]\n";
				g << "		[x][x][x][ ][ ][ ][ ]\n";
				g << "		[x][x][ ][ ][ ][ ][ ]\n";
				g << "		[x][ ][ ][ ][ ][ ][ ]\n\n";
				g << "��������� ����������� �������: " << raz << "*" << raz << "\n";
				g << "���� ������������ ������������ �������:\n";
				Out(A, a, b, g);
				cout << "		     ����������� �������: " << a << "*" << a << "\n";
				g << "�������� ����������� �������: " << a << "*" << a << "\n";
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
						cout << "������������ ���������:\n";
						Process(A, a, b, m, k, result);
						cout << "���������� �������� ������� � �������� �������: " << result << "\n";
						g << "���������� �������� ������� � �������� �������: " << result << "\n";
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
	fstream f; unsigned h = 0, size = 0; char s = '!'; float tmp; int temp;
	f.open("in.txt", ios::in);
	if (!f.is_open())
	{
		g << "file not opened";
		f.close();
		return false;
	}
	else
	{
		f >> temp;
		if (f.eof())
		{
			a = 0;
			*b = 0;
			raz = 1337;
			return true;
		}
		if (temp <= 0)
		{
			a = 0;
			*b = 0;
			raz = temp;
			return true;
		}
		else if (temp > N)
		{
			a = N;
			raz = a;
		}
		else a = temp;
		raz = a;
		*b = a;
		while ((!f.eof()) && (s != '\n'))
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
				while ((s == ' ' || s == '\t') && (s != '\n') && (!f.eof()))
				{
					f >> s;
					if ((f.eof()) || (s == '\n'))
					{
						h++;
						if (*b > size) *b = size;
						if (h < a)a = h;
						s = '!';
					}
				}
				if ((s != '\n') || (!f.eof()))
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
	else
	{
		return true;
	}
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
	else
	{
		return true;
	}
}
float Process(float A[N][M], unsigned a, unsigned b, int m, int k, float& result)
{
	int t, i = 0, j = m, z, y; float B[N*N], temp; int x = -1;
	y = k;
	while (i!=a)
	{
		m = m - 1;
		if (m < 0) m = 0;
		//i = 0;
		//while (i < a)
		//{
			j = m;
			while (j < b)
			{
				x++;
				B[x] = A[i][j];
				cout << B[x] << ' ';
				z = x;
				j++;
			}
			i++;
			cout << '\n';
		//}
			if (i >= k)
			{
				b--;
			}
		/*for (t = 0; t < y; t++) k++;
		if (k > a)
		{
			k = a;
		}
		*/
	}
	x = 0;
	temp = B[x];
	while (x < z)
	{
		x++;
		if (temp < B[x]) temp = B[x];
		else result = temp;
	}
	return result;
}