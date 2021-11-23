// Lab_08_1_Rec.cpp
// Вольвенко Іван
// Лабораторна робота № 8.1(Rec)
// Пошук та заміна символів у літерному рядку
// Варіант 13

#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int Count(char* str, int i)
{
	if (strlen(str) < 3)
		return -1;
	if (str[i + 1] != 0)
		if (str[i - 1] == '!' && str[i] == '!' && str[i + 1] == '!')
			return 1 + Count(str, i + 1);
		else
			return Count(str, i + 1);
	else
		return 0;
}

char* Change(char* dest, const char* str, char* t, int i)
{
	if (str[i + 2] != 0)
	{
		if (str[i] == '!' && str[i + 1] == '!' && str[i + 2] == '!')
		{
			strcat(t, "**");
			return Change(dest, str, t + 2, i + 3);
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
			return Change(dest, str, t, i);
		}
	}
	else
	{
		*t++ = str[i++];
		*t++ = str[i++];
		*t = '\0';
		return dest;
	}
}

int main()
{
	char str[228];

	cout << "Enter string:" << endl;
	cin.getline(str, 227);

	if (Count(str, 1) == -1)
		cerr << "Enter more characters" << endl;
	else
	{
		cout << "String conteined " << Count(str, 1) << " groups of '!!!'" << endl;

		char* dest1 = new char[228];
		dest1[0] = '\0';

		char* dest2;

		dest2 = Change(dest1, str, dest1, 0);

		cout << "Modified string (param): " << dest1 << endl;
		cout << "Modified string (result): " << dest2 << endl;
	}

	return 0;
}