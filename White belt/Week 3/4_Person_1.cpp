#include <iostream>
#include <string>
#include <map>

using namespace std;



string GetName (int year, map <int, string>& name_parts_to_year);



class Person
{

public:

	void ChangeFirstName (int year, const string& first_name)
	{
		first_names_to_year[year] = first_name;
	}


	void ChangeLastName (int year, const string& last_name)
	{
		last_names_to_year[year] = last_name;
	}


	string GetFullName (int year)
	{
		string first_name = GetName (year, first_names_to_year);

		string last_name  = GetName (year, last_names_to_year);


		if (first_name == "" && last_name == "")
		{
			return "Incognito";
		}
		
		if (first_name == "")
		{
			return last_name + " with unknown first name";
		}
		
		if (last_name == "")
		{
			return first_name + " with unknown last name";
		}

		return first_name + " " + last_name;
	}



private:

	map <int, string> first_names_to_year;
	map <int, string> last_names_to_year;

};


/*
int main ()
{
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990})
	{
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970})
	{
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970})
	{
		cout << person.GetFullName(year) << endl;
	}

	return 0;
}
*/



// Not using class members, so don't need to a part of it

string GetName (int year, map <int, string>& names_to_year)
{
	string result = "";

	for (const auto& [change_year, name] : names_to_year)
	{
		if (change_year > year)
		{
			break;
		}

		result = name;
	}

	return result;
}