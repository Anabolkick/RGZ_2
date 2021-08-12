#include <iostream>
#include <fstream>
#include <string>
#include "decode.h"

using namespace std;

int main()
{
	using namespace decode;
	setlocale(LC_ALL, "Russian");

	ifstream fin1;
	ifstream fin2;

	int dv[30];	   // 30 ������ � ����o� ��������
	int des[30];   // 30 ���������� �����
	int k = 0;     // ����� ������ ������� ���������� �����
	string str_des[30];
	string str_index[30];
	int swap_index[30];
	int idx_count = 0; //���-�� ���� ��������
	int dv_l = 0;
	int mode;

	string path1, path2, path3;
	cout << "Name 1 or path 1: \n";
	getline(cin, path1);
	cout << "Name 2 or path 2: \n";
	getline(cin, path2);
	cout << "Name 3 or path 3: \n";
	getline(cin, path3);

	do
	{
		cout << "�� ������ �����������(0), ������������(1), ��������(2) \n";
		cin >> mode;
	} while (mode != 0 && mode != 1 && mode != 2);

	fin2.open(path2);
	//���������� �������(�������) ���������, ������� ���� ����� ��������
	while (getline(fin2, str_index[idx_count], ','))
	{
		swap_index[idx_count] = atoi(str_index[idx_count].c_str());
		idx_count++;

		if (getline(fin2, str_index[idx_count], ';'))
		{
			swap_index[idx_count] = atoi(str_index[idx_count].c_str());
			idx_count++;
		}
	}
	idx_count--; //	��� ��� ��� ������ ���������� �� ���� ������ +1
	fin2.close();


	fin1.open(path1);
	while (getline(fin1, str_des[k], ';'))
	{
		dv_l = 0; //��������� ��������� �������� ������ (�����)
		des[k] = atoi(str_des[k].c_str());

		//������� � �������� �������
		while (des[k] > 1)
		{
			dv[dv_l] = des[k] % 2;
			des[k] = des[k] / 2;
			dv_l++;
		}
		dv[dv_l] = des[k]; //���������� �������
		int dv_inv[30];    //��� ������ � ���������� ���

		//������ � �����
		for (int m = 0, i = dv_l; i >= 0; i--, m++)
		{
			dv_inv[m] = dv[i];
		}

		if (mode == 0)
		{
			coding(dv_inv, dv_l, swap_index, idx_count, true, &path3);
		}

		k++;
	}

	if (mode == 1)
	{
		decoding(swap_index, idx_count, &path3);
	}
	else if (mode == 2)
	{
		clean(&path3);
	}

	fin1.close();
}




