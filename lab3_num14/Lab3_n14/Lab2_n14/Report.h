#pragma once
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"
#include "MyDate.h"
#include "TypeWork.h"



// класс "отчет о заказе"
class ReportWork
{
private:
	/*название фирмы*/
	string company_name;
	// вид работы
	string type_of_work;
	// единица измерения
	string unit;
	// стоимость единицы выполнения работ
	double cost;
	// дата исполнения
	string exec_date;
	// обьем работ
	double scope_of_work;
	// общая стоимость
	double common_cost;

public:

	// конструктор
	ReportWork();

	// св-во для имени
	void set_Name(string value);

	// функция ввода структуры "компания" с консоли
	static ReportWork InputScreenReportWork();
	
	// функция ввода структуры "отчет о работе" для администратора
	static ReportWork Input(string _nm, TypeWork tp);

	// функция вывода структуры "компания" на консоль
	static void OutputScreenReportWork(ReportWork c);

	// запись в бинарный файл
	static void WriteReportWorkToFile(ReportWork a, ofstream& os);

	// считывание из бинарного файла
	static ReportWork ReadReportWorkFile(ifstream& in);

	// вывод на консоль заголовка
	static void OutputScreenHeaderReportWork();

	// изменение отчета о работе
	static void ChangeReportWork(ReportWork &result);
		
	// поиск равного элемента по выбранному критерию
	static bool EqualsReportWork(ReportWork m, ReportWork n, int type_search);
	
	// ввод критерия поиска в зависимости от выбранного типа 
	static ReportWork InputCriteriaSearchReportWork(int type_search);
	
	// сравнения структур в зависимости от выбранного поля для сортировки
	static int CompareReportWork(ReportWork n, ReportWork m, int type_search);
	
};