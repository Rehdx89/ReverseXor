#include <iostream>
#include <chrono>
#include <conio.h>

using std::cout;
using std::endl;



int reversingXor(int result, int operand)
{
	unsigned int mask = 0x80000000, missingOperand = 0;

	while (mask)
	{
		if (result & mask)										//if the bit result is 1 we take the not of 
			missingOperand |= mask & ~(operand & mask);			//the operand bit bc 1 ^ 0 = 1 and 0 ^ 1 = 1
		else
			missingOperand |= operand & mask;					//0 ^ 0 = 0 and 1 ^ 1 = 0
		mask = mask >> 1;
	}

	return missingOperand;
}


int main()
{
	int result, operand;
	do {
		system("cls");
		system("color c");
		cout << "[!] If the hex option is bugging, convert the hex to dec [!]" << endl;

		cout << "You want to enter in hex or dec: d/h" << endl;
		if (_getch() == 'h')
		{
			cout << "Enter the result of the XOR operation in hex: ";
			std::cin >> std::hex >> result;
			cout << endl;

			cout << "Enter the operand of the XOR operation in hex: ";
			std::cin >> std::hex >> operand;
			cout << endl;

			std::cin >> std::dec;


			cout << std::hex << reversingXor(result, operand) << endl;
			cout << std::dec;
		}
		else if (_getch() == 'd')
		{
			cout << "Enter the result of the XOR operation in hex: ";
			std::cin >> result;
			cout << endl;

			cout << "Enter the operand of the XOR operation in hex: ";
			std::cin >> operand;
			cout << endl;

			cout << std::hex << reversingXor(result, operand) << endl;
			cout << std::dec;
		}
		else
			cout << "[!] Choose a character between d = decimal or h = hexadecimal [!]" << endl;

		cout << "\n\n\n\nAPUUYEZ ECHAPPE POUR SORTIR DU PROGRAMME..." << endl;
		std::cin.clear();					//sometimes some values were keeping the users from entering input even 
	} while (_getch() != 27);				//at the next loop so eveyrtime we reach here the stdin buffer is cleared 

	return 0;
}
