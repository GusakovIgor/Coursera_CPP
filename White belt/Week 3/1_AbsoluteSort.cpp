#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


void PrintVector (const vector <int>& array);


int main ()
{
	int array_size = 0;

	cin >> array_size;


	vector <int> array (array_size, 0);

	for (auto& elem : array)
	{
		cin >> elem;
	}


	sort (begin(array), end(array), [](int a, int b){return abs(a) < abs(b);});

	PrintVector (array);


	return 0;
}


void PrintVector (const vector <int>& array)
{
	for (const auto& elem : array)
	{
		cout << elem << ' ';
	}

	cout << endl;
}