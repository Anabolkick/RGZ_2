#include <iostream>
#include <string>
#include <fstream>

namespace decode
{
	using namespace std;

	ifstream fin3;
	ofstream fout3;

	void coding(int* dvoich, int dv_length, int *swap_index, int index_count, bool write, string * path) //кодирует каждый элемент отдельно TODO link
	{
		if (!fout3.is_open())
		{
			fout3.open(*path, fstream::app);
		}

		for (int x = 0; x < index_count; x += 2)	//х - индекс с которым сверяю
		{
			int a = swap_index[x];
			int b = swap_index[x + 1];

			if (b <= dv_length && a <= dv_length && a >= 0 && b >= 0)	 //Индексы которые меняем не больше общего кол-ва элементов
			{
				//swap
				int c;
				c = dvoich[a];
				dvoich[a] = dvoich[b];
				dvoich[b] = c;
			}
		}

		if (write)
		{
			for (int i = 0; i <= dv_length; i++)	 //Что бы после всех перемещений только записывало
			{
				fout3 << dvoich[i];
			}
			fout3 << ";";
		}

		fout3.close();
	}

	void decoding(int * swap_index, int index_count, string * path)
	{
		double des = 0;
		int dv[20];
		string str_dv[30];
		int d = 0;	// какое знак дв числа меняем

		//Надо выполнить перестановку зеркально
		for (int i = 0, j = index_count; i <= j; i++, j--)
		{
			int c;
			c = swap_index[i];
			swap_index[i] = swap_index[j];
			swap_index[j] = c;
		}

		//dv считываем с 3 файла
		if (!fin3.is_open())
		{
			fin3.open(*path);
		}

		while (getline(fin3, str_dv[d], ';'))
		{
			int len = str_dv[d].size() - 1;

			for (int i = 0; i <= len; i++)
			{
				dv[i] = str_dv[d].c_str()[i] - 48;	 
			}

			coding(dv, len, swap_index, index_count, false, path);	//Возвращение 3 файла в нормальный вид	 

			for (int i = len; i >= 0; i--)
			{
				des = des + dv[len - i] * pow(2, i);
			}

			cout << des << endl;
			d++;
			des = 0;
		}

		fin3.close();
	}

	void clean(string * path)
	{
		if (!fout3.is_open())
		{
			fout3.open(*path);
		}
		fout3.close();
	}
}