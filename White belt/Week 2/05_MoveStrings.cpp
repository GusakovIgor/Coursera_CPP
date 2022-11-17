/*
#include <iostream>
#include <string>
#include <vector>

using namespace std;



void MoveStrings (vector<string>& source, vector<string>& destination);



int main ()
{
	int source_size, destination_size;
	cin >> source_size >> destination_size;

	vector<string> source;
	vector<string> destination;

	string str;
	for (int i = 0; i < source_size; i++)
	{
		cin >> str;
		source.push_back (str);
	}

	for (int i = 0; i < destination_size; i++)
	{
		cin >> str;
		destination.push_back (str);
	}

	
	MoveStrings (source, destination);


	source_size      = source.size();
	destination_size = destination.size();

	cout << endl;
	cout << "Source:" << endl;
	for (int i = 0; i < source_size; i++)
	{
		cout << i + 1 << ": " << source[i] << endl;		
	}

	cout << endl;
	cout << "Destination:" << endl;
	for (int i = 0; i < destination_size; i++)
	{
		cout << i + 1 << ": " << destination[i] << endl;		
	}


	return 0;
}
*/

void MoveStrings (vector<string>& source, vector<string>& destination)
{
	for (auto str : source)
	{
		destination.push_back (str);
	}

	source.clear();
}