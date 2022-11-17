#include <iostream>

using namespace std;


int main ()
{
	double price;
	double a, b;
	double x, y;

	cin >> price >> a >> b >> x >> y;

	x /= 100;
	y /= 100;


	if (price > b)
	{
		price *= (1 - y);
	}
	else if (price > a)
	{
		price *= (1 - x);
	}

	cout << price << endl;


	return 0;
}