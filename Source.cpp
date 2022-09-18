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


	/*���� ��� �������� ����� �� ���������� � r-����� � �������.
	 *std::cout << "������� ������������ ����� � ���������� �������: ";
	std::cin >> float_dec;
	std::cout << "������� ��������� ������� ��������� (2-36): ";
	std::cin >> radix;
	std::cout << "������� ������ ����� ������� ��������� ��� �������� � ������� ���������?: ";
	std::cin >> amount_of_sign;
	new_num = FromDecToR(float_dec, radix, amount_of_sign);


	std::cout << "������� ������������ ����� ����� ����� � R-����� ������� ��������� ��� �������� � ����������: ";
	std::cin >> r_number;
	std::cout << "�� ����� ������� ��������� ���������?: ";
	std::cin >> radixRtoDec;
	decNum = FromRToDec(r_number, radixRtoDec);*/

	std::cout << "������� ������ ������������ ����� ����� ����� � R-����� ������� ���������: ";
	std::cin >> r_number;
	std::cout << "������� ������ ������������ ����� ����� ����� � R-����� ������� ���������: ";
	std::cin >> r_number_2;
	std::cout << "������� ������� ��������� ����� (2-36): ";
	std::cin >> radixRtoDec;
	std::cout << "������� ��� �������� ��? (�������� + ��� *): ";
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

		// ���� ������� ������, ������� �������� ������ ������.
		while ((int)flDec / Radix != 0)
		{
			new_num = convert((int)flDec % Radix) + new_num;
			flDec = (int)flDec / Radix;
		}
		new_num = convert((int)flDec) + new_num; // ��������� ������� �������.
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
			new_num += convert((int)float_ostat); //����� ����� ������� � ���������� �����.

			float_ostat = float_ostat - (int)float_ostat; //���������� �� ����� ����� � ���������� �������� ������.
			count += 1;
		}
		std::cout << "����� � ����� ������� ���������: " << new_num << std::endl;
	}
	else std::cout << "����� � ����� ������� ���������: " << new_num << std::endl;
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
			//����� ������� ��������� � �������� � �������� 10. �=10, �=11 � �.�
			decNum = radix * decNum + cToInt;
			//������� radixRtoDec ��� �������� ������ ������� ���-��� ����� ����� �� 1 ������ ����� ����� ����� ����� �����.
			//� ��� ����� �� ���������� ������� �� ����, ����� ������� � ������������� �������.
		}
		else
		{
			if (rNum[i] >= '0' && rNum[i] <= '9') floatDec += (rNum[i] - '0') / pow(radix, step);
			else if (rNum[i] >= 'A' && rNum[i] <= 'Z') floatDec += (rNum[i] - 'A' + 10) / pow(radix, step);
			step += 1;

		}

	}

	std::cout << "����� � ���������� ������� ���������: " << decNum + floatDec << std::endl;
	std::cout << "-----------------------------" << std::endl;

	return decNum + floatDec;
}

void MathOperation(std::string r_num_1, std::string r_num_2, int radix, char sign)
{
	long double decNum;
	std::string rNum;

	std::cout << "\n������������� ������\n(����� � ���������� ��������, ����� ����� �������������� �������� � R-����� ��:" << std::endl;

	if (sign == '+')
	{
		decNum = FromRToDec(r_num_1, radix) + FromRToDec(r_num_2, radix);
		rNum = FromDecToR(decNum, radix, 1);
		std::cout << "���������� ����� � " << radix << "-����� ������� ���������: " << rNum << std::endl;
	}
	else if (sign == '*')
	{
		decNum = FromRToDec(r_num_1, radix) * FromRToDec(r_num_2, radix);
		rNum = FromDecToR(decNum, radix, 1);
		std::cout << "���������� ����� � " << radix << "-����� ������� ���������: " << rNum << std::endl;
	}

}