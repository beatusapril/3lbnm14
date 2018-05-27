#pragma once
#include <stdio.h>
#include <conio.h>
#include <sstream>
#include <math.h>
#include <iostream>
#include <string>
#include <iomanip>
#include "HelpUtils.h"
#include "Report.h"
#include "TypeWork.h"



// конструктор
ReportWork::ReportWork()
{
	/*название фирмы*/
	string company_name = "";
	// вид работы
	string type_of_work = "";
	// единица измерения
	string unit = "";
	// стоимость единицы выполнения работ
	double cost = 0.0;
	// дата исполнения
	string exec_date;
	// обьем работ
	double scope_of_work = 0.0;
	// общая стоимость
	double common_cost = 0.0;
}

// св-во имя
void ReportWork::set_Name(string value)
{
	company_name = value;
}


// функция ввода структуры "компания" с консоли
ReportWork ReportWork::InputScreenReportWork()
{
	ReportWork c;
	MyDate k;
	c.company_name = InputInformation("Введите имя ( наименование компании ): ");
	c.type_of_work = InputInformation("Введите тип работы: ");
	c.unit = InputInformation("Введите единицу измерения: ");
	c.cost = InputNumberToDouble(0.0, 1000000.0, "Введите стоимость единицы выполненной работы (0 - 1000000): ");
	k.InputDate();
	c.exec_date = k.ToString();
	c.scope_of_work = InputNumberToDouble(0.0, 10000.0, "Введите обьем работ (0 - 10000): ");
	c.common_cost = c.cost*c.scope_of_work;
	return c;
}

// функция ввода структуры "отчет о работе" с известным именем и типом работы
ReportWork ReportWork::Input(string _nm, TypeWork tp)
{
	ReportWork rep;
	MyDate k;
	rep.company_name = _nm;
	rep.type_of_work = tp.get_Type_of_work();
	rep.unit = tp.get_Unit();
	rep.cost = tp.get_Cost();
	k.InputDate();
	rep.exec_date = k.ToString();
	rep.scope_of_work = InputNumberToDouble(0.0, 10000.0, "Введите обьем работ (0 - 10000): ");
	rep.common_cost = rep.cost*rep.scope_of_work;

	return rep;
}

// функция вывода структуры "компания" на консоль
void ReportWork::OutputScreenReportWork(ReportWork c)
{
	cout << setw(15) << setiosflags(ios::left) << c.company_name << "|";
	cout << setw(15) << setiosflags(ios::left) << c.type_of_work << "|";
	cout << setw(10) << setiosflags(ios::left) << c.unit << "|";
	cout << setw(15) << setiosflags(ios::left) << c.cost << "|";
	cout << setw(15) << setiosflags(ios::left) << c.exec_date << "|";
	cout << setw(15) << setiosflags(ios::left) << c.scope_of_work << "|";
	cout << setw(17) << setiosflags(ios::left) << c.common_cost << endl;
}

// запись в бинарный файл
void ReportWork::WriteReportWorkToFile(ReportWork a, ofstream& os)
{
	StringInBinFile(os, a.company_name);
	StringInBinFile(os, a.type_of_work);
	StringInBinFile(os, a.unit);
	os.write((char*)&a.cost, sizeof(double));
	StringInBinFile(os, a.exec_date);
	os.write((char*)&a.scope_of_work, sizeof(double));
	os.write((char*)&a.common_cost, sizeof(double));
}

// считывание из бинарного файла
ReportWork ReportWork::ReadReportWorkFile(ifstream& in)
{
	ReportWork a;

	a.company_name = StringFromBinFile(in);
	a.type_of_work = StringFromBinFile(in);
	a.unit = StringFromBinFile(in);
	in.read((char*)&a.cost, sizeof(double));
	a.exec_date = StringFromBinFile(in);
	in.read((char*)&a.scope_of_work, sizeof(double));
	in.read((char*)&a.common_cost, sizeof(double));

	return a;
}

// вывод на консоль заголовка
void ReportWork::OutputScreenHeaderReportWork()
{
	cout << setw(4) << setiosflags(ios::left) << "№" << "|";
	cout << setw(15) << setiosflags(ios::left) << "Клиент" << "|";
	cout << setw(15) << setiosflags(ios::left) << "Тип работы" << "|";
	cout << setw(10) << setiosflags(ios::left) << "ЕИ" << "|";
	cout << setw(15) << setiosflags(ios::left) << "Стоимость ЕИ" << "|";
	cout << setw(15) << setiosflags(ios::left) << "Дата работы" << "|";
	cout << setw(15) << setiosflags(ios::left) << "Обьем работы" << "|";
	cout << setw(17) << setiosflags(ios::left) << "Общая стоимость" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
}

// изменение отчета о работе
void ReportWork::ChangeReportWork(ReportWork &result)
{
	MyDate d;
	if (InputNumber(0, 1, "Вы хотите изменить имя  " + result.company_name + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
		result.company_name = InputInformation("Введите новое имя: ");
	if (InputNumber(0, 1, "Вы хотите изменить тип работы " + result.type_of_work + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
		result.type_of_work = InputInformation("Введите новый тип работы: ");
	if (InputNumber(0, 1, "Вы хотите изменить единицу измерения " + result.unit + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
		result.unit = InputInformation("Введите новую единицу измерения: ");
	if (InputNumber(0, 1, "Вы хотите изменить стоимость единицы выполнения работ " + to_string(result.cost) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
		result.cost = InputNumberToDouble(0.0, 1000000.0, "Введите новую стоимость (0 - 1000000): ");
	if (InputNumber(0, 1, "Вы хотите изменить дату исполнения (0 - нет, 1 - да) \nВыш выбор: ") == 1)
	{
		d.InputDate();
		result.exec_date = d.ToString();
	}
	if (InputNumber(0, 1, "Вы хотите изменить обьем работ " + to_string(result.cost) + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
		result.scope_of_work = InputNumberToDouble(0.0, 100000.0, "Введите обьем работ (0 - 100000): ");
}

// поиск равного элемента по выбранному критерию
bool ReportWork::EqualsReportWork(ReportWork m, ReportWork n, int type_search)
{
	switch (type_search)
	{
	case 1:
		return (m.company_name == n.company_name);
	case 2:
		return (m.type_of_work == n.type_of_work);
	case 3:
		return (m.exec_date == n.exec_date);
	default:
		return false;
	}
}

// ввод критерия поиска в зависимости от выбранного типа 
ReportWork ReportWork::InputCriteriaSearchReportWork(int type_search)
{
	ReportWork result;
	MyDate d;
	switch (type_search)
	{
	case 1:
		result.company_name = InputInformation("Введите имя ( наименование компании ): ");
		return result;
	case 2:
		result.type_of_work = InputInformation("Введите тип работы: ");
		return result;
	case 3:
		d.InputDate();
		result.exec_date = d.ToString();
		return result;
	default:
		return result;
	}
}

// сравнения структур в зависимости от выбранного поля для сортировки
int ReportWork::CompareReportWork(ReportWork n, ReportWork m, int type_search)
{
	switch (type_search)
	{
	case 1:
		if (n.company_name > m.company_name) return 1;
		else if (n.company_name < m.company_name) return -1;
		else return 0;
	case 2:
		if (n.type_of_work > m.type_of_work) return 1;
		else if (n.type_of_work < m.type_of_work) return -1;
		else return 0;
	case 3:
		if (n.exec_date > m.exec_date) return 1;
		else if (n.exec_date < m.exec_date) return -1;
		else return 0;
	default:
		return -2;
	}
}