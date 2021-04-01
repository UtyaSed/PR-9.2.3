// Lab_9_2_3.cpp
// ������ ³����
// ����������� ������ � 9.2.3
// ������������� �� ������� ����� � ����� ��������
// ������ 7

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>


using namespace std;

enum Specialty { KN, IT, ME, PI, TN };;
string SpecialtyStr[] = { "��������� �����", "�����������", "���������� �� ��������","Գ���� �� �����������","������� ��������" };

struct Student
{
	string prizv;
	int kurs;
	Specialty specialty;
	int Phisic;
	int Math;
	union {
		int Prog;
		int Num_Methods;
		int Pedagogy;
	};


};


void Create(Student* p, const int N);
void Print(Student* p, const int N);
int BinSearch(Student* p, const int N, const string prizv, const int specialty);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	string priz;
	int specialty;
	int found;
	cout << "������ ������� �������� N: "; cin >> N;

	Student* p = new Student[N];

	int menuItem;
	do {
		cout << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ������� �����" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			cout << "������ ����� ������:" << endl;

			cout << " �������: "; cin >> priz;

			cout << " ������ � �������� ��������: "; cin >> specialty;

			cout << endl;
			if ((found = BinSearch(p, N, priz, specialty)) != -1)
				cout << "�������� �������� � �������: " << found + 1 << endl;
			else
				cout << "�������� �������� �� ��������" << endl;
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);

	return 0;

}

void Create(Student* p, const int N)
{
	int specialty;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();

		cout << " �������: "; getline(cin, p[i].prizv);
		cout << " ����: "; cin >> p[i].kurs;
		cout << " ������������ (0 - ��������� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������): ";
		cin >> specialty;
		p[i].specialty = (Specialty)specialty;
		cout << " ������ � Գ����: "; cin >> p[i].Phisic;
		cout << " ������ � ����������: "; cin >> p[i].Math;
		switch (p[i].specialty)
		{
		case KN:
			cout << " ������ � �������������: "; cin >> p[i].Prog;
			break;
		case IT:
			cout << " ������ � ��������� ������: "; cin >> p[i].Num_Methods;
			break;
		case ME:
		case PI:
		case TN:
			cout << " ������ � ���������: "; cin >> p[i].Pedagogy;
			break;
		}
		cout << endl;
	}
}
void Print(Student* p, const int N)
{
	cout << "============================================================================================================================================================================"
		<< endl;
	cout << "                                                                     ������ ��������" << endl;

	cout << "============================================================================================================================================================================"
		<< endl;
	cout << "|  � |    �������   | ���� |      ������������      | ������ � Գ���� | ������ � ���������� | ������ � ������������� | ������ � ��������� ������  | ������ � ��������� | "
		<< endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(13) << left << p[i].prizv << " "
			<< "| " << setw(4) << right << p[i].kurs << " "
			<< "| " << setw(23) << left << SpecialtyStr[p[i].specialty] << " "
			<< "| " << setw(15) << right << p[i].Phisic << " "
			<< "| " << setw(19) << right << p[i].Math << " ";
		switch (p[i].specialty)
		{
		case KN:
			cout << "| " << setw(22) << right << p[i].Prog << " |" << setw(30) << "|" << setw(22) << "  |" << endl;
			break;
		case IT:
			cout << "| " << setw(24) << " |" << setw(29) << right << p[i].Num_Methods << "|" << setw(22) << " |" << endl;
			break;
		case ME:
		case PI:
		case TN:
			cout << "| " << setw(24) << " |" << setw(30) << "|" << setw(21) << right << p[i].Pedagogy << "|" << endl;
			break;
		}

	}
	cout << "============================================================================================================================================================================="
		<< endl;
	cout << endl;
}
int BinSearch(Student* p, const int N, const string prizv, const int specialty)
{
	int Left = 0, Right = N - 1, i;
	do {
		i = (Left + Right) / 2;
		if (p[i].prizv == prizv && p[i].specialty == specialty)
			return i;
		if ((p[i].prizv < prizv)
			||
			(p[i].prizv == prizv &&
				p[i].specialty < specialty))
		{
			Left = i + 1;
		}
		else
		{
			Right = i - 1;
		}

	} while (Left <= Right);

	return -1;
}