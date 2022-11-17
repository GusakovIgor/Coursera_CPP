#include <iostream>
#include <string>

using namespace std;



int main ()
{
	char check_symbol = 'f';
	int count = -2;

	string input;
	cin >> input;


	int length = input.size();

	for (int i = 0; i < length; i++)
	{
		if (input[i] == check_symbol)
		{
			++count;
			if (count == 0)
			{
				cout << i;
				break;
			}
		}
	}


	if (count < 0)
	{
		cout << count;
	}


	return 0;
}