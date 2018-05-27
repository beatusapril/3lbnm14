#pragma once
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"
#include "TypeWork.h"
#include "Operation.h"
#include "Report.h"
#include "ClientFirmy.h"


class User {
protected:
	// имя файла пользователей
	string file_client;
	// имя файла отчет о работе
	string file_report_work;
	// имя файла типов работ
	string file_type_work;
	// имя пользователя
	string name;
	Operation<ClientFirmy> listClientFirmy;
	// список с отчетами о работах
	Operation<ReportWork> listReportWork;
	// список с доступными типами работами
	Operation<TypeWork> listTypeWork;

public:
	
	// конструктор
	User(string _name, string _file_client, string _file_report_work, string _file_type_work);

	// посмотреть доступные работы по выбранному критерию
	void SearchTypeWork();

	// посмотреть все доступные работы 
	void ReadAllTypeWork();

	// ЧИСТО виртуальная функция меню
	virtual void Menu() = 0;

	// выход
	void Close();
};
