#pragma once
#pragma once
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"
#include "MyDate.h"



// класс "тип работы"
class TypeWork
{
private:

	// вид работы
	string type_of_work;
	// единица измерения
	string unit;
	// стоимость единицы выполнения работ
	double cost;

public:

	// конструктор
	TypeWork();

	//"свойство" тип работы
	string get_Type_of_work();

	//"свойство" единица измерения
	string get_Unit();

	//"свойство" цена
	double get_Cost();

	// функция ввода структуры "компания" с консоли
	static TypeWork InputScreenTypeWork();

	// функция вывода структуры "компания" на консоль
	static void OutputScreenTypeWork(TypeWork type);

	// запись в бинарный файл
	static void WriteTypeWorkToFile(TypeWork type, ofstream& os);

	//считывание из бинарного файла
	static TypeWork ReadTypeWorkFile(ifstream& in);

	// вывод на консоль заголовка
	static void OutputScreenHeaderTypeWork();

	// изменение типа работ
	static void ChangeTypeWork(TypeWork &result);

	// поиск равного элемента по выбранному критерию
	static bool EqualsTypeWork(TypeWork m, TypeWork n, int type_search);
	
	// ввод критерия поиска в зависимости от выбранного типа 
	static TypeWork InputCriteriaSearchTypeWork(int type_search);
	
	// сравнения структур в зависимости от выбранного поля для сортировки
	static int CompareTypeWork(TypeWork n, TypeWork m, int type_search);

	// перегруженный оператор равенства
	friend bool operator ==(const TypeWork  &a, const TypeWork &b); //перегрузка ==
};
