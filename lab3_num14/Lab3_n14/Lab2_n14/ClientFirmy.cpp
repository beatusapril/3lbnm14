#include <stdio.h>
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include "HelpUtils.h"
#include "ClientFirmy.h"



// пустой конструктор
ClientFirmy::ClientFirmy()
{
	name_client = "";
	status = "";
}

// перегруженный конструктор
ClientFirmy::ClientFirmy(string cl_name, bool _status)
{
	name_client = cl_name;
	status = _status;
}


// св-во имени клиента
void ClientFirmy::set_Name_Client(string value)
{
	name_client = value;
}

// св-ва статуса
void ClientFirmy::set_Status(bool value)
{
	status = value;
}

// функция ввода структуры "клиент фирмы" с консоли
ClientFirmy ClientFirmy::InputScreenClientFirmy()
{
	ClientFirmy c;
	c.name_client = InputInformation("Введите клиента: ");
	c.status = (InputNumber(0, 1, "Вы являетесь юридическим лицом?(0 - нет, 1 - да)\nОтвет: ") == 1);

	return c;
}

// функция вывода структуры "клиент фирмы" на консоль
void ClientFirmy::OutputScreenClientFirmy(ClientFirmy c)
{
	cout << setw(15) << setiosflags(ios::left) << c.name_client << "|";
	if (c.status)
	   cout << setw(25) << setiosflags(ios::left) << "юридическое лицо" << "|"  << endl;
	else
		cout << setw(25) << setiosflags(ios::left) << "физическое лицо" << "|" << endl;
}

// запись в бинарный файл
void ClientFirmy::WriteClientFirmyToFile(ClientFirmy a, ofstream& os)
{
	StringInBinFile(os, a.name_client);
	os.write((char*)&a.status, sizeof(bool));	
}

// чтение из бинарного файла
ClientFirmy ClientFirmy::ReadClientFromFile(ifstream& in)
{
	ClientFirmy a;

	a.name_client = StringFromBinFile(in);
	in.read((char*)&a.status, sizeof(bool)); 

	return a;
}


// вывод на консоль заголовка таблицы с клиентами 
void ClientFirmy::OutputScreenHeaderClientFirmy()
{
	cout << setw(4) << setiosflags(ios::left) << "№" << "|";
	cout << setw(15) << setiosflags(ios::left) << "Клиент" << "|";
	cout << setw(25) << setiosflags(ios::left) << "Статус" << endl;
	cout << "------------------------------------------------" << endl;
}

// оператор равенства
bool operator ==(const ClientFirmy &a, const ClientFirmy &b)//перегрузка ==
{
	return ((a.name_client == b.name_client) && (a.status == b.status));
}


