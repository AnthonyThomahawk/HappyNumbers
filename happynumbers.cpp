#include <iostream>
#include <string>
#include <math.h>
#include <limits>

long long int LOOP_SIZE;

using namespace std;

bool isHappy(long long int num)
{
	string digits = to_string(num);

	if (digits.length() == 1)
	{
		num = pow(digits[0] - '0', 2);
		digits = to_string(num);
	}

	while (digits.length() > 1)
	{
		num = 0;
		for (int j = 0; j < digits.length(); j++)
		{
			num += pow(digits[j] - '0', 2);
		}
		digits = to_string(num);
	}

	return num == 1;
}

int main()
{
	cout << "Options : " << endl;
	cout << "1 - Search for all happy numbers up to a limit" << endl;
	cout << "2 - Check if a number is happy" << endl;

	int choice;
	cin >> choice;

	while (cin.fail() || (choice != 1 && choice != 2))
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Incorrect option, please try again : " << endl;
		cin >> choice;
	}

	if (choice == 1)
	{
		cout << "Enter limit for search : " << endl;
		cin >> LOOP_SIZE;
		while (cin.fail() || LOOP_SIZE <= 0)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Incorrect input, please try again : " << endl;
			cin >> choice;
		}

		for (long long int i = 1; i <= LOOP_SIZE; i++)
		{
			if (isHappy(i))
				cout << i << " is a happy number" << endl;
		}
	}
	else
	{
		cout << "Enter number to check : " << endl;
		int n;
		cin >> n;
		while (cin.fail() || n <= 0)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Incorrect input, please try again : " << endl;
			cin >> n;
		}

		if (isHappy(n))
			cout << n << " is a happy number!" << endl;
		else
			cout << n << " is a sad number :( " << endl;
	}

	cout << "Hit enter to exit" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
}