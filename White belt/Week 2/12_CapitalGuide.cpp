#include <iostream>
#include <map>
#include <string>

using namespace std;



void ChangeCapital (map <string, string>& guidebook, string country, string new_capital);

void RenameCountry (map <string, string>& guidebook, string old_country_name, string new_country_name);


void PrintInfo     (map <string, string>& guidebook, string country);

void DumpCapitals  (const map <string, string>& guidebook);



int main ()
{
	int num_queries;
	cin >> num_queries;


	map <string, string> guidebook;


	string command;

	for (int i = 0; i < num_queries; i++)
	{
		cin >> command;

		if (command == "CHANGE_CAPITAL")
		{
			string country, new_capital;
			cin >> country >> new_capital;

			ChangeCapital (guidebook, country, new_capital);
		}
		else if (command == "RENAME")
		{
			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;

			RenameCountry (guidebook, old_country_name, new_country_name);
		}
		else if (command == "ABOUT")
		{
			string country;
			cin >> country;

			PrintInfo (guidebook, country);
		}
		else if (command == "DUMP")
		{
			DumpCapitals (guidebook);
		}
		else
		{
			cout << "Unkown command :\"" << command << "\"" << endl;
		}
	}


	return 0;
}


void ChangeCapital (map <string, string>& guidebook, string country, string new_capital)
{
	if (guidebook.count(country) == 0)
	{
		guidebook[country] = new_capital;

		cout << "Introduce new country " << country << " with capital " << new_capital << endl;
	}
	else
	{
		const string& old_capital = guidebook[country];

		if (old_capital == new_capital)
		{
			cout << "Country " << country << " hasn't changed its capital" << endl;
		}
		else
		{
			guidebook[country] = new_capital;

			cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << endl;
		}
	}
}


void RenameCountry (map <string, string>& guidebook, string old_country_name, string new_country_name)
{
	if (old_country_name == new_country_name    ||
		guidebook.count (old_country_name) == 0 ||
		guidebook.count (new_country_name) == 1)
	{
		cout << "Incorrect rename, skip" << endl;
	}
	else
	{
		cout << "Country " << old_country_name << " with capital " << guidebook[old_country_name];
		cout << " has been renamed to " << new_country_name << endl;

		guidebook[new_country_name] = guidebook[old_country_name];
		guidebook.erase (old_country_name);
	}
}


void PrintInfo (map <string, string>& guidebook, string country)
{
	if (guidebook.count(country) == 0)
	{
		cout << "Country " << country << " doesn't exist" << endl;
	}
	else
	{
		cout << "Country " << country << " has capital " << guidebook[country] << endl;
	}
}


void DumpCapitals (const map <string, string>& guidebook)
{
	if (guidebook.empty())
	{
		cout << "There are no countries in the world" << endl;
	}
	else
	{
		for (const auto& [country, capital] : guidebook)
		{
			cout << country << '/' << capital << endl;
		}
	}
}