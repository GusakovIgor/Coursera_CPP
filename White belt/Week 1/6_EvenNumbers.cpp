#include <iostream>

using namespace std;


int main ()
{
	int left, right;

	cin >> left >> right;


	for (int number = left; number <= right; number++)
	{
		if (number % 2 == 0)
		{
			cout << number << ' ';
		}
	}


	return 0;
}