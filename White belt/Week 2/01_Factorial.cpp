/*
#include <iostream>

using namespace std;


int Factorial (int number);


int main ()
{
	int number;
	cin >> number;

	cout << Factorial (number);

	return 0;
}
*/

int Factorial (int number)
{
	if (number <= 0)
	{
		return 1;
	}

	return number * Factorial (number - 1);
}