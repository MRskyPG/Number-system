#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <string>
#include <cmath>

char convert(int);
std::string FromDecToR(long double, int, int);
long double FromRToDec(std::string, int);
void MathOperation(std::string, std::string, int, char);


int main() {

	setlocale(LC_ALL, "ru");

	long double float_dec;
	int radix, amount_of_sign, radixRtoDec;
	long double decNum = 0;
	std::string new_num = "", new_num_2 = "";
	std::string r_number, r_number_2;
	char sign = ' ';


	/*Ѕлок про переводы чисел из дес€тичной в r-ичную и обратно.
	 *std::cout << "¬ведите вещественное число в дес€тичной системе: ";
	std::cin >> float_dec;
	std::cout << "¬ведите основание системы счислени€ (2-36): ";
	std::cin >> radix;
	std::cout << "—колько знаков после зап€той сохранить при переводе в систему счислени€?: ";
	std::cin >> amount_of_sign;
	new_num = FromDecToR(float_dec, radix, amount_of_sign);


	std::cout << "¬ведите вещественное число через точку в R-ичной системе счислени€ дл€ перевода в дес€тичное: ";
	std::cin >> r_number;
	std::cout << "»з какой системы счислени€ переводим?: ";
	std::cin >> radixRtoDec;
	decNum = FromRToDec(r_number, radixRtoDec);*/

	std::cout << "¬ведите ѕервое вещественное число через точку в R-ичной системе счислени€: ";
	std::cin >> r_number;
	std::cout << "¬ведите ¬торое вещественное число через точку в R-ичной системе счислени€: ";
	std::cin >> r_number_2;
	std::cout << "”кажите систему счислени€ чисел (2-36): ";
	std::cin >> radixRtoDec;
	std::cout << "—ложить или умножить их? (напишите + или *): ";
	std::cin >> sign;

	MathOperation(r_number, r_number_2, radixRtoDec, sign);

}


char convert(int num)
{
	std::string out = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	return out[num];
}


std::string FromDecToR(long double flDec, int Radix, int amountOfSign)
{
	long double float_ostat;
	std::string new_num;

	float_ostat = flDec - (int)flDec;

	if ((int)flDec / Radix != 0) {

		// ѕока делитс€ нацело, остаток заносить справа налево.
		while ((int)flDec / Radix != 0)
		{
			new_num = convert((int)flDec % Radix) + new_num;
			flDec = (int)flDec / Radix;
		}
		new_num = convert((int)flDec) + new_num; // ѕоследнюю частное занести.
	}
	else new_num = convert((int)flDec);


	//For floating part of DEC number.
	if (float_ostat > 0.0 && amountOfSign > 0)
	{
		int count = 0;
		new_num += ".";
		while (count < amountOfSign)
		{
			float_ostat *= Radix;
			new_num += convert((int)float_ostat); //целую часть занести в получаемое число.

			float_ostat = float_ostat - (int)float_ostat; //избавитьс€ от целой части и продолжить алгоритм дальше.
			count += 1;
		}
		std::cout << "„исло в новой системе счислени€: " << new_num << std::endl;
	}
	else std::cout << "„исло в новой системе счислени€: " << new_num << std::endl;
	std::cout << "-----------------------------" << std::endl;

	return new_num;
}

long double FromRToDec(std::string rNum, int radix)
{
	int cToInt = 0;
	bool Point = false;
	long double floatDec = 0, decNum = 0;
	int step = 1;


	for (int i = 0; i < rNum.length(); i++)
	{

		if (rNum[i] == '.') {
			Point = true; i += 1;
		}

		if (!Point)
		{

			if (rNum[i] >= '0' && rNum[i] <= '9') cToInt = rNum[i] - '0';
			else if (rNum[i] >= 'A' && rNum[i] <= 'Z') cToInt = rNum[i] - 'A' + 10;
			//Ќайти разницу численную у символов и добавить 10. ј=10, ¬=11 и т.д
			decNum = radix * decNum + cToInt;
			//степень radixRtoDec дл€ крайнего левого символа вещ-ого числа будет на 1 меньше длины целой части этого числа.
			//и так далее по уменьшению степени до нул€, после зап€той в отрицательную степень.
		}
		else
		{
			if (rNum[i] >= '0' && rNum[i] <= '9') floatDec += (rNum[i] - '0') / pow(radix, step);
			else if (rNum[i] >= 'A' && rNum[i] <= 'Z') floatDec += (rNum[i] - 'A' + 10) / pow(radix, step);
			step += 1;

		}

	}

	std::cout << "„исло в дес€тичной системе счислени€: " << decNum + floatDec << std::endl;
	std::cout << "-----------------------------" << std::endl;

	return decNum + floatDec;
}

void MathOperation(std::string r_num_1, std::string r_num_2, int radix, char sign)
{
	long double decNum;
	std::string rNum;

	std::cout << "\nѕромежуточные данные\n(числа в дес€тичных системах, число после математической операции в R-ичной —„:" << std::endl;

	if (sign == '+')
	{
		decNum = FromRToDec(r_num_1, radix) + FromRToDec(r_num_2, radix);
		rNum = FromDecToR(decNum, radix, 1);
		std::cout << "ѕолученное число в " << radix << "-ичной системе счислени€: " << rNum << std::endl;
	}
	else if (sign == '*')
	{
		decNum = FromRToDec(r_num_1, radix) * FromRToDec(r_num_2, radix);
		rNum = FromDecToR(decNum, radix, 1);
		std::cout << "ѕолученное число в " << radix << "-ичной системе счислени€: " << rNum << std::endl;
	}

}