#include<iostream>
using namespace std;
int main() {
	int num, num_2;
	bool guess = false;
	num = rand() % 100;
	do
	{

		cout << "Enter a number" << endl;
		cin >> num_2;
		if (num_2 == num)
		{
			cout << " Congrulations you have guessed it right" << endl;
			break;
		}
		else if (num_2 < num)
		{
			cout << " Your guess is too low" << endl;
		}
		else if (num_2 > num)
		{
			cout << " Your guess is too high" << endl;
		}

	} while (!guess);
	return 0;
}