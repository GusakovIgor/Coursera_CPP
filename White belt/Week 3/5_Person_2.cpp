#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;



vector <string> GetNameHistory (int year, map <int, string>& names_to_year);

string ArrangeNameHistory (vector <string>& history, bool with_history);



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
		return GetName (year, false);
	}


	string GetFullNameWithHistory (int year)
	{
		return GetName (year, true);
	}


	string GetName (int year, bool with_history)
	{
		vector <string> first_name_history = GetNameHistory (year, first_names_to_year);

		vector <string> last_name_history  = GetNameHistory (year, last_names_to_year);

	
		string first_names = ArrangeNameHistory (first_name_history, with_history);
		string last_names  = ArrangeNameHistory (last_name_history, with_history);


		if (first_names == "" && last_names == "")
		{
			return "Incognito";
		}
		
		if (first_names == "")
		{
			return last_names + " with unknown first name";
		}
		
		if (last_names == "")
		{
			return first_names + " with unknown last name";
		}

		return first_names + " " + last_names;
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
  person.ChangeFirstName(1965, "Appolinaria");

  person.ChangeLastName(1965, "Sergeeva");
  person.ChangeLastName(1965, "Volkova");
  person.ChangeLastName(1965, "Volkova-Sergeeva");

  for (int year : {1964, 1965, 1966}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

	return 0;
}
*/



// Not using class members, so don't need to a part of it

string ArrangeNameHistory (vector <string>& history, bool with_history)
{
	if (history.empty())
	{
		return "";
	}


	string result = history.back();
	history.pop_back();

	if (!with_history)
	{
		return result;
	}
	

	int num_names = history.size();
	
	if (num_names > 0)
	{
		result += " (";

		for (int i = num_names - 1; i > 0; --i)
		{
			result += history[i] + ", ";
		}

		result += history[0];
		result += ")";
	}


	return result;
}


vector <string> GetNameHistory (int year, map <int, string>& names_to_year)
{
	vector <string> history;

	for (const auto& [change_year, name] : names_to_year)
	{
		if (change_year > year)
		{
			break;
		}

		if (history.empty() || name != history.back())
		{
			history.push_back(name);
		}
	}

	return history;
}