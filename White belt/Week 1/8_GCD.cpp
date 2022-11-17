#include <iostream>
#include <algorithm>

using namespace std;



int main ()
{
	int a, b;
	cin >> a >> b;


	while (b != 0)
	{
		a = a % b;

		swap (a, b);
	}

	cout << a;


	return 0;
}