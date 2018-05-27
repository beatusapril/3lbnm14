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
#include "ClientFirmy.h"


// класс "User"
// конструктор
User::User(string _name, string _file_client, string _file_report_work, string _file_type_work)
{
	name = _name;
	file_client = _file_client;
	file_report_work = _file_report_work;
	file_type_work = _file_type_work;	


	listClientFirmy.ReadFromFile(ClientFirmy::ReadClientFromFile, file_client);
	listReportWork.ReadFromFile(ReportWork::ReadReportWorkFile, file_report_work);
	listTypeWork.ReadFromFile(TypeWork::ReadTypeWorkFile, file_type_work);

}


// поиск типа работ
void User::SearchTypeWork() 
{
	if (listTypeWork.Is_empty())
		cout << "Ќет типов работ";
	else
	{
		int numb = InputNumber(1, 3, "¬ыберите тип поиска:\n 1 - по названию работы\n 2 - по единице измерени€\n 3 - по стоимости единицы измерени€ \n¬аш выбор: ");
		TypeWork search_elem = TypeWork::InputCriteriaSearchTypeWork(numb);
		vector<TypeWork> subset = listTypeWork.LinearySearch(search_elem, TypeWork::EqualsTypeWork, numb);
		if (subset.size() != 0)
			listTypeWork.OutputScreen(subset, TypeWork::OutputScreenTypeWork, TypeWork::OutputScreenHeaderTypeWork);
		else
			cout << "“ип работы не найден!" << endl;
	}
}

// посмотреть все типы работ
void User::ReadAllTypeWork()
{
	listTypeWork.OutputScreen(listTypeWork.vect, TypeWork::OutputScreenTypeWork, TypeWork::OutputScreenHeaderTypeWork);
}

// выход
void User::Close()
{
	listClientFirmy.OutputFile(listClientFirmy.vect, ClientFirmy::WriteClientFirmyToFile, file_client);
	listReportWork.OutputFile(listReportWork.vect, ReportWork::WriteReportWorkToFile, file_report_work);
	listTypeWork.OutputFile(listTypeWork.vect, TypeWork::WriteTypeWorkToFile, file_type_work);
}
