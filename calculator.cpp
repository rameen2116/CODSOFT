#include<iostream>
using namespace std;
int main() {
	float num1, num2, result;
	int option;
	do {
		cout << "Which operation you would like to perform?" << endl;
		cout << "1-Addition" << endl;
		cout << "2-Subtraction" << endl;
		cout << "3-Multiplication" << endl;
		cout << "4-Division" << endl;
		cout << "5-Exit" << endl;
		cin >> option;
		if (option >= 1 && option <= 4)
		{
			cout << "Enter two numbers" << endl;
			cin >> num1 >> num2;
			if (option == 1)
			{
				result = num1 + num2;
				cout << result << endl;
			}
			else if (option == 2)
			{
				result = num1 - num2;
				cout << result << endl;
			}
			else if (option == 3)
			{
				result = num1 * num2;
				cout << result << endl;
			}
			else if (option == 4)
			{
				result = num1 / num2;
				cout << result << endl;
			}
		}
	} while (option != 5);
	return 0;
}