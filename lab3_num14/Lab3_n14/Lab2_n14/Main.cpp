// 3)14. создать смету работ
#include <stdio.h>
#include <string.h>
#include "HelpUtils.h"
#include "User.h"
#include "Customer.h"
#include "Administrator.h"
using namespace std;

void Process()
{
	string user_name = "";
	bool state;

	User *user;

	string filename_client = "files\\clu.dat";
	string filename_reports = "files\\rep.dat";
	string filename_typewk = "files\\type.dat";

	while (1)
	{
		cout << " --------------------Меню---------------------  " << endl;
		cout << "1 - Работа в режиме пользователя" << endl;
		cout << "2 - Работа в режиме администратора " << endl;
		cout << "0 - Выход" << endl;
		int changemenu = InputNumber(0, 2, "Ваш выбор: ");
		switch (changemenu)
		{
			case 1:
			    user_name = InputInformation("Режим пользователя\n Введите имя (или название компании): ");
				state = (InputNumber(0, 1, "Вы являетесь юридическим лицом?(0 - нет, 1 - да)\nОтвет: ") == 1);
				user = new Customer(user_name, state, filename_client, filename_reports, filename_typewk);
				user->Menu();
				break;

			case 2:
				user_name = InputInformation("Режим администратора\n Введите имя : ");
				user = new Administrator(user_name, filename_client, filename_reports, filename_typewk);
				user->Menu();
				break;

			default:
				exit(1);
			break;
		}
	}
}

void main()
{
	system("chcp 1251");
	Process();
}