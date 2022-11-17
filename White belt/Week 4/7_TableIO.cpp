#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


int main ()
{
	ifstream input ("input.txt");

	int N, M;

	if (input)
	{
		input >> N >> M;
	}

	
	int element = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			input >> element;
			
			cout << setw(10) << element;

			if (j != M - 1)
			{
				cout << ' ';
				input.ignore(1);
			}

		}

		if (i != N - 1)
		{
			cout << endl;
		}
	}

	return 0;
}