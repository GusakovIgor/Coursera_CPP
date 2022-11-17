#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;



void AddNewBus         (map <string, vector <string>>& buses_to_stop, 
                        map <string, vector <string>>& stops_to_bus, const string& bus, const int num_stops);

void PrintStopsForBus  (map <string, vector <string>>& buses_to_stop, 
                        map <string, vector <string>>& stops_to_bus, const string& bus);

void PrintBusesForStop (map <string, vector <string>>& buses_to_stop, const string& stop);


void PrintAllBuses     (const map <string, vector <string>>& stops_to_bus);



int main ()
{
    int num_queries;

    cin >> num_queries;


    map <string, vector<string>> stops_to_bus;      // pairs like "busname"  - "stop1", "stop2", ...
    map <string, vector<string>> buses_to_stop;     // pairs like "stopname" - "busname1", "busname2", ...


    string command;

    for (int i = 0; i < num_queries; i++)
    {
        cin >> command;

        if (command == "NEW_BUS")
        {
            string bus;
            int num_stops;

            cin >> bus >> num_stops;

            AddNewBus (buses_to_stop, stops_to_bus, bus, num_stops);
        }
        else if (command == "BUSES_FOR_STOP")
        {
            string stop;
            cin >> stop;

            PrintBusesForStop (buses_to_stop, stop);
        }
        else if (command == "STOPS_FOR_BUS")
        {
            string bus;
            cin >> bus;

            PrintStopsForBus (buses_to_stop, stops_to_bus, bus);
        }
        else if (command == "ALL_BUSES")
        {
            PrintAllBuses (stops_to_bus);
        }
        else
        {
            cout << "Unkown command :\"" << command << "\"" << endl;
        }
    }



    return 0;
}


void AddNewBus (map <string, vector <string>>& buses_to_stop, map <string, vector <string>>& stops_to_bus, const string& bus, const int num_stops)
{
    string stop;

    for (int i = 0; i < num_stops; i++)
    {
        cin >> stop;

        buses_to_stop[stop].push_back(bus);

        stops_to_bus[bus].push_back(stop);
    }
}


void PrintStopsForBus (map <string, vector <string>>& buses_to_stop, map <string, vector <string>>& stops_to_bus, const string& bus)
{
    if (stops_to_bus.count(bus) == 0)
    {
        cout << "No bus" << endl;
    }
    else
    {
        for (const string& stop : stops_to_bus[bus])
        {
            cout << "Stop " << stop << ": ";

            if (buses_to_stop[stop].size() == 1)
            {
                cout << "no interchange" << endl;
                continue;
            }

            for (const string& interchange_bus : buses_to_stop[stop])
            {
                if (interchange_bus != bus)
                {
                    cout << interchange_bus << ' ';
                }
            }

            cout << endl;
        }
    }
}


void PrintBusesForStop (map <string, vector <string>>& buses_to_stop, const string& stop)
{
    if (buses_to_stop.count(stop) == 0)
    {
        cout << "No stop" << endl;
    }
    else
    {
        for (const string& bus : buses_to_stop[stop])
        {
            cout << bus << " ";
        }

        cout << endl;
    }
}


void PrintAllBuses (const map <string, vector <string>>& stops_to_bus)
{
    if (stops_to_bus.empty())
    {
        cout << "No buses" << endl;
    }
    else
    {
        
        for (const auto& [bus, stops] : stops_to_bus)
        {
            cout << "Bus " << bus << ": ";
            
            for (const string& name : stops)
            {
                cout << name << ' ';
            }
            
            cout << endl;
        }
    }
}