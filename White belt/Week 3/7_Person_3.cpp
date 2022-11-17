#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;



vector <string> GetNameHistory (int year, const map <int, string>& names_to_year);

string ArrangeNameHistory (vector <string>& history, bool with_history);



class Person
{

public:

	Person (const string& first_name, const string& last_name, int year)
	{
		birth_year = year;
		ChangeFirstName (year, first_name);
		ChangeLastName  (year, last_name);
	}



	void ChangeFirstName (int year, const string& first_name)
	{
		if (year >= birth_year)
		{
			first_names_to_year[year] = first_name;
		}
	}


	void ChangeLastName (int year, const string& last_name)
	{
		if (year >= birth_year)
		{
			last_names_to_year[year] = last_name;
		}
	}


	string GetFullName (int year) const
	{
		return GetName (year, false);
	}


	string GetFullNameWithHistory (int year) const
	{
		return GetName (year, true);
	}


	string GetName (int year, bool with_history) const
	{
		vector <string> first_name_history = GetNameHistory (year, first_names_to_year);

		vector <string> last_name_history  = GetNameHistory (year, last_names_to_year);

	
		string first_names = ArrangeNameHistory (first_name_history, with_history);
		string last_names  = ArrangeNameHistory (last_name_history, with_history);


		if (first_names.empty() || last_names.empty())
		{
			return "No person";
		}

		return first_names + " " + last_names;
	}



private:

	map <int, string> first_names_to_year;
	map <int, string> last_names_to_year;

	int birth_year;

};



// Not using class members, so don't need to a part of it

string ArrangeNameHistory (vector <string>& history, bool with_history)
{
	if (history.empty())
	{
		return {};
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


vector <string> GetNameHistory (int year, const map <int, string>& names_to_year)
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



/*
int main ()
{
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
*/