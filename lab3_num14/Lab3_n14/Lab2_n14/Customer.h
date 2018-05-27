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

// класс пользователя ( заказчика )
class Customer : public User
{
private:
	// тип указателя на ф-ю
	typedef void (Customer::*DynamicFunction)();

	// вектор ссылок на методы класса
	vector<DynamicFunction> menuFunctions;

	// вектор имен методов
	vector<string> menuNames;

	// регистрация метода
	void Register(string _nmFunction, DynamicFunction _function);

	// вызов метода по индексу
	void Invoke(int index);
protected:
	// статус пользователя
	bool status;
public:
	// конструкткор
	Customer(string _name, bool _status, string _file_client, string _file_report_work, string _file_type_work);

	// добавить заказ
	void AddOrder();

	// посмотреть все отчеты
	void ReadAllReportWork();

    // меню
	void Menu();

};
