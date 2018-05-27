#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "HelpUtils.h"
using namespace std;


template <class Type>
class Operation {
private:
	// сортировка по заданному критерию
	// int(*Compare)(Type, Type, int) - указатель на функцию, которая сравнивает искомый эл-т с текущим по type_search  
	void ShellSort(int n, int typ, int(*Compare)(Type, Type, int))
	{
		int i, j, step;
		Type tmp;
		for (step = n / 2; step > 0; step /= 2)
			for (i = step; i < n; i++)
			{
				tmp = vect[i];
				for (j = i; j >= step; j -= step)
				{
					if ((Compare(tmp, vect[j - step], typ) == -1))
						vect[j] = vect[j - step];
					else
						break;
				}
				vect[j] = tmp;
			}

	}

	// бинарный поиск
	// int(*Compare)(Type, Type, int) - указатель на функцию, которая сравнивает искомый эл-т с текущим по type_search  
	int Binary_Search_Element(int left, int right, int type_search, Type d, int(*Compare)(Type, Type, int))
	{
		int midd = 0;
		while (1)
		{
			midd = (left + right) / 2;

			if (Compare(d, vect[midd], type_search) == -1)// если искомое больше значения в ячейке
				right = midd - 1;				// смещаем правую границу поиска
			else if (Compare(d, vect[midd], type_search) == 1)  // если искомое меньше значения в ячейке
				left = midd + 1;					// смещаем левую границу поиска
			else                       // иначе (значения равны)
				return midd;           // функция возвращает индекс ячейки

			if (left > right)          // если границы сомкнулись 
				return -1;
		}
	}
public:
	vector<Type> vect;
	Operation() {};
	~Operation() {};

	// удаление элемента
	void Remove(int numb)
	{
		if (numb != 0)
			vect.erase(vect.begin() + numb - 1);
	}
	
	// добавление элемента
	void Add(Type &elem)
	{
		vect.push_back(elem);
	}

	//размер вектора
	int size()
	{
		return vect.size();
	}

	// проверка на пустоту
	bool Is_empty()
	{
		return (vect.size() == 0);
	}

	// вывод в файл
	// void(*f) (Type) - указатель на функцию, которая записывает одну структуру в файл  
	void OutputFile(vector<Type> items, void(*f)(Type, ofstream&), string newfname)
	{
		ofstream fout(newfname, ios::binary);
		if (fout)
		{
			int i = vect.size();
			fout.write((char*)&i, sizeof(int));
			vector<Type>::const_iterator pos;
			for (pos = items.begin(); pos != items.end(); ++pos)
			{
					f(*pos, fout);
			}
			fout.close();
		}
	}

	// вывод на экран
	void OutputScreen(vector<Type> items, void(*f)(Type),void(*Header)())
	{
		vector<Type>::const_iterator pos;
		int count = 1;
		Header();
		for (pos = items.begin(); pos != items.end(); ++pos)
		{
			cout << setw(4) << setiosflags(ios::left) << count << "|";
			f(*pos);
			++count;
		}
	}

	// ввод из файла
	// Type(*f)(ifstream&) - указатель на функцию, которая считывает одну структуру из файла 
	bool ReadFromFile(Type(*f)(ifstream&), string newfname)
	{
		std::ifstream input;

		input.open(newfname, ios::binary);

		if (!input)
		{
			cout << "Не удалось открыть файл" << endl;
			return false;
		}
		else
		{
			int size;
			Type elem;
			input.read((char*)&size, sizeof(int));
			for (int i = 0; i < size; i++)
			{
				vect.push_back(f(input));
			}

			input.close();
			return true;
		}
	}

	// ввод с экрана
	//Type(*f)() - указатель на функцию, которая вводит одну структуру с консоли
	void ReadFromScreen(Type(*f)())
	{
		int n;
		Type elem;
		do
		{
			vect.push_back(f());
			n = InputNumber(0, 1, "Вы хотите добавить элемент? (1 - да, 0 - нет)\nВаш выбор: ");
		} while (n != 0);
	}

	// линейный поиск
	// bool(*Equal)(Type, Type, int) - указатель на функцию, которая проверяет равенство искомого эл-та с текущим по type_search
	vector<Type> LinearySearch(Type search_elem, bool(*Equal)(Type, Type, int), int type_search)
	{
		vector<Type> NewVect;
		for (auto iter = vect.begin(); iter != vect.end(); iter++)
		{
			if (Equal(search_elem, *iter, type_search))
				NewVect.push_back(*iter);

		}

		return NewVect;
	}

	// бинарный поиск
	// int(*Compare)(Type, Type, int) - указатель на функцию, которая сравнивает искомый эл-т с текущим по type_search 
	// bool(*Equal)(Type, Type, int) - указатель на функцию, которая проверяет равенство искомого эл-та с текущим по type_search
	vector<Type> BinarySearch(int type_search, Type find_element, int(*Compare)(Type, Type, int), bool(*Equal)(Type, Type, int))
	{
		vector<Type> NewVect;
		ShellSort(vect.size(), type_search, Compare);
		int left = 0;
		int right = vect.size();
		int index;
		if ((index = Binary_Search_Element(left, right - 1, type_search, find_element, Compare)) != -1)
		{
			NewVect.push_back(vect[index]);
			int first_index = index;
			while ((++index<right) && Equal(vect[index], find_element, type_search))
				NewVect.push_back(vect[index]);
			while ((--first_index >= 0) && Equal(vect[first_index], find_element, type_search))
				NewVect.push_back(vect[first_index]);
		}
		return NewVect;
	}

	// поиск одинакового элемента в векторе (без критериев)
	bool SearchEquals(Type elem)
	{
		bool result = false;
		vector<Type>::const_iterator pos;
		for (pos = vect.begin(); pos != vect.end(); ++pos)
		{
			if (*pos == elem)
			{
				result = true;
				break;
			}
		}
		return result;
	}
};