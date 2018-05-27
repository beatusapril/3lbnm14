#pragma once
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"
#include "TypeWork.h"
#include "Operation.h"
#include "Report.h"
#include "User.h"

// класс администратор
class Administrator : public User
{
private:
	// тип указателя на метод класса администратор
	typedef void (Administrator::*DynamicFunction)();

	// вектор ссылок на методы класса
	vector<DynamicFunction> menuFunctions;

	// вектор имен методов
	vector<string> menuNames;

	// регистрация метода
	void Register(string _nmFunction, DynamicFunction _function);

	// вызов метода по индексу
	void Invoke(int index);
public:

	// конструктор
	Administrator(string _name, string _file_client, string _file_report_work, string _file_type_work);

	// добавление заказа
	void AddOrder();

	// добавление типа работ
	void AddTypeWork();

	// изменить доступные работы 
	void ChangeTypeWorking();

	// удалить доступные работы 
	void DeleteTypeWork();

	// посмотреть все отчеты
	void ReadAllReportWork();

	void SearchReportWork();

	// удалить отчеты
	void DeleteReportWork();

	// изменить отчеты
	void ChangeReportWorking();

	// посмотреть пользователей
	void ReadClients();

	// меню
	void Menu();

};
