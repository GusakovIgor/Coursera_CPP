/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;



void Reverse (vector <int>& v);



int main ()
{
	int vector_size = 0;
	cin >> vector_size;

	vector <int> numbers;

	
	int number = 0;

	for (int i = 0; i < vector_size; i++)
	{
		cin >> number;
		numbers.push_back (number);
	}


	Reverse (numbers);


	for (int i = 0; i < vector_size; i++)
	{
		cout << i + 1 << ": " << numbers[i] << endl;		
	}


	return 0;
}
*/

void Reverse (vector <int>& v)
{
	int length = v.size();

	int begin = 0;
	int end   = length - 1;

	while (end > begin)
	{
		swap (v[begin++], v[end--]);
	}
}