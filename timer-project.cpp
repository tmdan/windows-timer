// timer.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include "stdio.h"
#include "stdafx.h"
#include "locale.h"
#include "iostream"
#include <string.h>
#include <conio.h>
using namespace std;

char on[] = "shutdown /s /t ";
const char off[50] = "shutdown -a";
char buffer[200] = { 0 };


char* concat(int minutes)
{
	buffer[0] = '\0';
	int second = minutes * 60;//перевела в секунды
	char string[200] = { 0 };
	sprintf_s(string, "%d", second);//перевела секунды (int) в тип char
	strcat_s(buffer, on);//конкатенация строк
	strcat_s(buffer, string);//конкатенация строк
	return buffer;
}



void switcher(int minutes)
{
	if (minutes == 0) {
		system(off);
	}
	else {
		system(concat(minutes));
	}

}



int main()
{
	setlocale(LC_ALL, "Russian");
	int minutes = 0;

start:

	cout << "------------------------------------------------------------\n\n";
	cout << "                   ТАЙМЕР ВЫКЛЮЧЕНИЯ ПК                      \n\n";
	cout << "Справка:\n";
	cout << "-для отключения таймера введите колличество минут равное нулю\n";
	cout << "------------------------------------------------------------\n\n\n\n";
	cout << "Введите колличество минут: ";
	cin >> minutes;


	if (minutes == 0)
	{
		cout << "Таймер будет выключен: \n\n-ENTER для подтверждения\n-ESC для выхода";
		int code = _getch();
		if (code == 27) { system("cls"); goto start; }
		cout << "Таймер будет выключен" << endl;
		switcher(0);
		system("cls");
		goto start;

	}



	else if (minutes>0 && minutes <= 600)
	{
		printf("Таймер будет установлен на %i минут: \n\n-ENTER для подтверждения\n-ESC для выхода", minutes);
		int code = _getch();
		if (code == 27) { system("cls"); goto start; }
		cout << "Таймер будет установлен на - " << minutes << " минут " << endl;
		switcher(0);
		switcher(minutes);
		system("cls");
		goto start;

	}
	else {

		cout << "Вы ввыели слишком большое значение - максимально доступно 600 минут";
		system("cls");
		goto start;
	}




	system("pause");
	return 0;
}

