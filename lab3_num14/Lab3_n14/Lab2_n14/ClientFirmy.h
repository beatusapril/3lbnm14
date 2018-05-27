#pragma once
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"
#include "TypeWork.h"



// класс клиент фирмы
class ClientFirmy
{
private:
	// имя
	string name_client;
	// является ли лицо юридическим
	bool status = true;
public:
	// конструктор
	ClientFirmy();

	// перегруженный конструктор
	ClientFirmy(string cl_name , bool _status);

	// св-во имени
	void set_Name_Client(string value);

	// св-во статуса
	void set_Status(bool value);

	// функция ввода структуры "клиент фирмы" с консоли
	static ClientFirmy InputScreenClientFirmy();

	//функция вывода структуры "клиент фирмы" на консоль
	static void OutputScreenClientFirmy(ClientFirmy c);

	//запись в бинарный файл
	static void WriteClientFirmyToFile(ClientFirmy a, ofstream& os);

	// считывание из бинарного файла
	static ClientFirmy ReadClientFromFile(ifstream& in);

	// вывод заголовка на экран
	static void OutputScreenHeaderClientFirmy();

	// перегруженный оператор равенства
	friend bool operator ==(const ClientFirmy  &a, const ClientFirmy &b); //перегрузка ==
};
