#include <iostream>
#include <vector>

using namespace std;



int  ReadTempreture   (int num_days, vector <int>& tempreture);
void FilterTempreture (int num_days, int average, vector <int>& tempreture);

void PrintVector (const vector <int>& v);



int main ()
{
	int num_days;

	cin >> num_days;


	vector <int> tempreture (num_days);

	int average = ReadTempreture (num_days, tempreture);

	FilterTempreture (num_days, average, tempreture);


	PrintVector (tempreture);


	return 0;
}



int ReadTempreture (int num_days, vector <int>& tempreture)
{
	int average = 0;

	int value;

	for (int i = 0; i < num_days; i++)
	{
		cin >> value;
		average += value;
		tempreture[i] = value;
	}

	return average / num_days;
}


void FilterTempreture (int num_days, int average, vector <int>& tempreture)
{
	int high_temp_ptr = 0;

	for (int i = 0; i < num_days; i++)
	{
		if (tempreture[i] > average)
		{
			tempreture[high_temp_ptr++] = i;
		}
	}

	tempreture.resize(high_temp_ptr);
}


void PrintVector (const vector <int>& v)
{
	cout << v.size() << endl;
	
	for (auto elem : v)
	{
		cout << elem << " ";
	}
}