/*
#include <iostream>

using namespace std;


void UpdateIfGreater (int first, int& second);


int main ()
{
	int x, y;
	cin >> x >> y;

	UpdateIfGreater (x, y);

	cout << "x = " << x << endl;
	cout << "y = " << y << endl;

	return 0;
}
*/

void UpdateIfGreater (int first, int& second)
{
	if (first > second)
	{
		second = first;
	}
}