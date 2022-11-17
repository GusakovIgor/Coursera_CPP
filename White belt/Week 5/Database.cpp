#include <iostream>
#include <iomanip>
#include <sstream>

#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;


void CheckBoundaries (int value, int l_border, int r_border, string error_msg)
{
	if (value < l_border || value > r_border)
	{
		throw runtime_error (error_msg + to_string(value));
	}
}


class Date
{

	public:

		Date () {}

		Date (const int init_year, const int init_month, const int init_day)
		{
			CheckBoundaries (init_month, 1, 12, "Month value is invalid: ");
			CheckBoundaries (init_day,   1, 31, "Day value is invalid: ");
			
			year  = init_year;
			month = init_month;
			day   = init_day;
		}

		int GetYear() const
		{
			return year;
		}
		
		int GetMonth() const
		{
			return month;
		}

		int GetDay() const
		{
			return day;
		}


	private:

		int year;
		int month;
		int day;

};



bool operator < (const Date& l_op, const Date& r_op)
{
	int l_days = (l_op.GetYear() * 12 + l_op.GetMonth()) * 31 + l_op.GetDay();
	int r_days = (r_op.GetYear() * 12 + r_op.GetMonth()) * 31 + r_op.GetDay();

	if (l_days < r_days)
	{
		return true;
	}

	return false;
}


istream& operator >> (istream& input, Date& date)
{
	string user_date;

	input >> user_date;

	stringstream input_str (user_date);


	int init_year, init_month, init_day;
	bool correct = true;


	// Little part of code taken from solution, it's more readable, than my version
	
	correct = correct && (input_str >> init_year);
	correct = correct && (input_str.peek() == '-');
	input_str.ignore(1);
	
	correct = correct && (input_str >> init_month);
	correct = correct && (input_str.peek() == '-');
	input_str.ignore(1);

	correct = correct && (input_str >> init_day);
	correct = correct && input_str.eof();

	if (!correct)
	{
		throw runtime_error ("Wrong date format: " + user_date);
	}

	// Till this moment


	date = Date (init_year, init_month, init_day);

	return input;
}


ostream& operator << (ostream& output, const Date& date)
{
	output << setfill('0');

	output << setw(4) << date.GetYear();
	output << '-';
	output << setw(2) << date.GetMonth();
	output << '-';
	output << setw(2) << date.GetDay();

	return output;
}




class Database
{

	public:

		void AddEvent	 (const Date& date, const string& event)
		{
			events[date].insert(event);
		}


		bool DeleteEvent (const Date& date, const string& event)
		{
			if (events.count(date) != 0)
			{
				if (events[date].count(event) != 0)
				{
					events[date].erase(event);
					
					return true;
				}
			}

			return false;
		}
		
		int  DeleteDate	 (const Date& date)
		{
			int num_events = 0;

			if (events.count(date) != 0)
			{
				num_events = events[date].size();
				events.erase(date);
			}

			return num_events;
		}


		vector <string> Find (const Date& date) const
		{
			vector <string> result;

			if (events.count(date) != 0)
			{
				for (const string& event : events.at(date))
				{
					result.push_back(event);
				}
			}

			return result;
		}


		void Print() const
		{
			if (!events.empty())
			{
				for (const auto& [date, events_list] : events)
				{
					for (const string& event : events.at(date))
					{
						cout << date << ' ' << event << endl;
					}
				}
			}
		}


	private:

		map <Date, set <string>> events;

};



void ProcessCommand (istringstream& input, Database& database, string command);

void Add 	(istringstream& input, Database& database);

void Delete (istringstream& input, Database& database);

void DeleteEvent (Database& database, const Date& event_date, const string& event_name);

void Find 	(istringstream& input, Database& database);




int main()
{
	Database database;
	
	
	string line;

	string command;

	while (getline (cin, line))
	{
		if (line.empty())
		{
			continue;
		}

		istringstream input (line);

		input >> command;

		try
		{
			ProcessCommand (input, database, command);
		}
		catch (const exception& error)
		{
			cout << error.what() << endl;
		}
	}

	return 0;
}


void ProcessCommand (istringstream& input, Database& database, string command)
{
	if (command == "Add")
	{
		Add (input, database);
	}
	else if (command == "Del")
	{
		Delete (input, database);
	}
	else if (command == "Find")
	{
		Find (input, database);
	}
	else if (command == "Print")
	{
		database.Print();
	}
	else
	{
		cout << "Unknown command: " << command << endl;
	}
}


void Add (istringstream& input, Database& database)
{
	Date   event_date;
	string event_name;
	
	input >> event_date >> event_name;

	database.AddEvent (event_date, event_name);
}


void Delete (istringstream& input, Database& database)
{
	Date event_date;
	input >> event_date;

	if (!input.eof())
	{
		string event_name;
		input >> event_name;

		DeleteEvent (database, event_date, event_name);
	}
	else
	{
		cout << "Deleted " << database.DeleteDate (event_date) << " events" << endl;
	}
}

void DeleteEvent (Database& database, const Date& event_date, const string& event_name)
{
	if (database.DeleteEvent (event_date, event_name))
	{
		cout << "Deleted successfully" << endl;
	}
	else
	{
		cout << "Event not found" << endl;
	}
}


void Find (istringstream& input, Database& database)
{
	Date event_date;
	input >> event_date;

	for (const string& event : database.Find(event_date))
	{
		cout << event << endl;
	}
}