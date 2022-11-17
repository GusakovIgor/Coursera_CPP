#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;



int main ()
{
	ifstream input ("input.txt");


	cout << fixed << setprecision (3);

	double number = 0.0;

	while (input >> number;)		// as like getline returning stream, that we can convert to bool
	{
		cout << number << endl;
	}


	return 0;
}