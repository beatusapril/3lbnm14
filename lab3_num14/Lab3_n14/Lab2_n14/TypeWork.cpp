#pragma once
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include <iomanip>
#include "HelpUtils.h"
#include "TypeWork.h"


// класс "тип работы"
TypeWork::TypeWork()
{
	string type_of_work = "";
	string unit = "";
	double cost = 0.0;
}

//"свойство" тип работы
string TypeWork::get_Type_of_work()
{
	return type_of_work;
}

//"свойство" единица измерения
string TypeWork::get_Unit()
{
	return unit;
}

//"свойство" цена
double TypeWork::get_Cost()
{
	return cost;
}

// ввод типа работы с консоли
TypeWork TypeWork::InputScreenTypeWork()
{
	TypeWork type;
	type.type_of_work = InputInformation("Введите тип работы: ");
	type.unit = InputInformation("Введите единицу измерения: ");
	type.cost = InputNumberToDouble(0.0, 1000000.0, "Введите стоимость единицы выполненной работы (0 - 1000000): ");

	return type;
}

// вывод типа работы на консоль
void TypeWork::OutputScreenTypeWork(TypeWork type)
{
	cout << setw(15) << setiosflags(ios::left) << type.type_of_work << "|";
	cout << setw(10) << setiosflags(ios::left) << type.unit << "|";
	cout << setw(10) << setiosflags(ios::left) << type.cost << endl;
}

// запись в бин файл
void TypeWork::WriteTypeWorkToFile(TypeWork type, ofstream& os)
{
	StringInBinFile(os, type.type_of_work);
	StringInBinFile(os, type.unit);
	os.write((char*)&type.cost, sizeof(double));
}

// чтение из бин файла
TypeWork TypeWork::ReadTypeWorkFile(ifstream& in)
{
	TypeWork type;

	type.type_of_work = StringFromBinFile(in);
	type.unit = StringFromBinFile(in);
	in.read((char*)&type.cost, sizeof(double));

	return type;
}

// вывод заголовка
void TypeWork::OutputScreenHeaderTypeWork()
{
	cout << setw(4) << setiosflags(ios::left) << "№" << "|";
	cout << setw(15) << setiosflags(ios::left) << "Тип работы" << "|";
	cout << setw(10) << setiosflags(ios::left) << "ЕИ" << "|";
	cout << setw(10) << setiosflags(ios::left) << "Стоимость ЕИ" << endl;
	cout << "------------------------------------------------" << endl;
}

// изменение типа работы
void TypeWork::ChangeTypeWork(TypeWork &result)
{
	if (InputNumber(0, 1, "Вы хотите изменить тип работы " + result.type_of_work + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
		result.type_of_work = InputInformation("Введите новый тип работы: ");
	if (InputNumber(0, 1, "Вы хотите изменить единицу измерения " + result.unit + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
		result.unit = InputInformation("Введите новую единицу измерения: ");
	if (InputNumber(0, 1, "Вы хотите изменить стоимость единицы выполнения работ " + to_string(result.cost) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
		result.cost = InputNumberToDouble(0.0, 1000000.0, "Введите новую стоимость (0 - 1000000): ");

}

// сравнение типа работы
bool TypeWork::EqualsTypeWork(TypeWork m, TypeWork n, int type_search)
{
	switch (type_search)
	{
		case 1:
			return (m.type_of_work == n.type_of_work);
		case 2:
			return (m.unit == n.unit);
		case 3:
			return (m.cost == n.cost);
		default:
			return false;
	}
}

// ввод критерия поиска
TypeWork TypeWork::InputCriteriaSearchTypeWork(int type_search)
{
	TypeWork result;
	switch (type_search)
	{
	case 1:
		result.type_of_work = InputInformation("Введите тип работы: ");
		return result;
	case 2:
		result.unit = InputInformation("Введите единицу измерения работы: ");
		return result;
	case 3:
		result.cost = InputNumberToDouble(1, 10000, "Введите стоимость единицы работы: ");
		return result;
	default:
		return result;
	}
}

// сравнение типа работ
int TypeWork::CompareTypeWork(TypeWork n, TypeWork m, int type_search)
{
	switch(type_search)
	{
	case 1:
		if (n.type_of_work > m.type_of_work) return 1;
		else if (n.type_of_work < m.type_of_work) return -1;
		else return 0;
	case 2:
		if (n.unit > m.unit) return 1;
		else if (n.unit < m.unit) return -1;
		else return 0;
	case 3:
		if (n.cost > m.cost) return 1;
		else if (n.cost < m.cost) return -1;
		else return 0;
	default:
		return -2;
	}
}

// перегруженнный оператор равенства
bool operator ==(const TypeWork  &a, const TypeWork &b)//перегрузка ==
{
	double e = 0.001;
	return ((a.type_of_work == b.type_of_work) && (a.unit == b.unit) && (abs(a.cost - b.cost) < e));
}