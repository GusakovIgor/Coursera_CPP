#include <iostream>
#include <string>

using namespace std;



int main ()
{
	string first, second, third;

	cin >> first >> second >> third;

	string result;


	if (first <= second && first <= third)
	{
		result = first;
	}
	else if (second <= first && second <= third)
	{
		result = second;
	}
	else
	{
		result = third;
	}

	cout << result;


	return 0;
}