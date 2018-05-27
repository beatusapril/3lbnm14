#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
using namespace std;

// ввод числа в диапозоне (int)
int InputNumber(int min, int max, string message);

// ввод информации
string InputInformation(string messge);

// проверка символа на корректность в имени файла
bool CorrectSymbol(char c);

// проверка имени файла на коректность
bool CorrectName(string name);

// ввод имени файла
string InputFileName();

// ввод числа в диапозоне (double)
double InputNumberToDouble(double min, double max, string message);

// string из бинарного файла
string StringFromBinFile(ifstream& in);

// string в бинарный файл
void StringInBinFile(ofstream& os, string str);




