#include <iostream>
#include <string>
#include <set>

using namespace std;


int main ()
{
	int num_strings;
	cin >> num_strings;


	string input;

	set <string> unique_strings;

	for (int i = 0; i < num_strings; i++)
	{
		cin >> input;
		unique_strings.insert(input);
	}


	cout << unique_strings.size();


	return 0;
}