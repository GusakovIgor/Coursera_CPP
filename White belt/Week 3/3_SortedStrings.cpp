#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

// DO NOT GET IT SO COMPLICATED!
/*
class SortedStrings 
{

public:
	
	void AddString (const string& s)
	{
		strings[s]++;
	}


	vector <string> GetSortedStrings ()
	{
		vector <string> sorted_strings;

		for (const auto& [string, number] : strings)
		{
			for (int i = 0; i < number; i++)
			{
				sorted_strings.push_back(string);
			}
		}

		return sorted_strings;
	}



private:

	map <string, int> strings;

};
*/


class SortedStrings
{

public:

	void AddString (const string& s)
	{
		strings.push_back(s);
	}


	vector <string> GetSortedStrings ()
	{
		sort (begin(strings), end(strings));

		return strings;
	}


private:

	vector <string> strings;

};




void PrintSortedStrings(SortedStrings& strings)
{
	for (const string& s : strings.GetSortedStrings())
	{
		cout << s << " ";
	}
	
	cout << endl;
}

int main()
{
	SortedStrings strings;

	strings.AddString("first");
	strings.AddString("third");
	strings.AddString("second");
	PrintSortedStrings(strings);

	strings.AddString("second");
	PrintSortedStrings(strings);

	return 0;
}