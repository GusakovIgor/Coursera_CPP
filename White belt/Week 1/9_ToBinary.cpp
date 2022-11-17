#include <iostream>
#include <vector>

using namespace std;


int main ()
{
	int N;
	cin >> N;

	int base = 2;


	vector <char> number = {};

	while (N > 0)
	{
		number.push_back (N % base + '0');

		N /= base;
	}

	for (int i = number.size() - 1; i >= 0; i--)
	{
		cout << number[i];
	}


	return 0;
}