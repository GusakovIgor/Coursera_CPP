#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


int main ()
{
	int num_queries;
	cin >> num_queries;


	int num_routes = 1;

	map <vector <string>, int> routes;


	int num_stops;

	for (int i = 0; i < num_queries; i++)
	{
		cin >> num_stops;

		vector<string> stations (num_stops);
		
		for (string& : stations)
		{
			cin >> string;
		}


		if (routes.count(stations) != 0)
		{
			cout << "Already exists for " << routes[stations] << endl;
		}
		else
		{
			routes[stations] = num_routes;
			cout << "New bus " << num_routes << endl;

			num_routes++;
		}
	}

	return 0;
}