#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include <cctype>

using namespace std;


int main ()
{
	int num_strings = 0;
	cin >> num_strings;


	vector <string> array (num_strings);


	for (auto& elem : array)
	{
		cin >> elem;
	}

	sort (begin(array), end(array),
			[](string left, string right)
			{
				// int min_len = min (left.size(), right.size());

				// for (int i = 0; i < min_len; i++)
				// {
				// 	char left_symbol  = tolower (left[i]);
				// 	char right_symbol = tolower (right[i]);

				// 	if (left_symbol == right_symbol)
				// 	{
				// 		continue;
				// 	}


				// 	return (left_symbol < right_symbol) ? true : false; 
				// }

				// return (left.size() < right.size()) ? true : false;

				return lexicographical_compare (begin(left), end(left), begin(right), end(right), 
													[](char left_symbol, char right_symbol)
													{
														return tolower(left_symbol) < tolower(right_symbol);
													}
											   );
			}
		 );


	for (const auto& elem : array)
	{
		cout << elem << ' ';
	}

	cout << endl;


	return 0;
}




/*

Классы входных строк:

- Равные по длине
	- true,  если первая буква left[i] != right[i] меньше чем right[i]
	- false, если все буквы равны
	- false, если первая буква left[i] != right[i] больше чем right[i]


- |left| > |right|
	- true,  если первая буква left[i] != right[i] меньше чем right[i]
	- false, если все буквы равны
	- false, если первая буква left[i] != right[i] больше чем right[i]

	- false, если все буквы из минимальной длины равны


- |left| < |right|
	- true,  если первая буква left[i] != right[i] меньше чем right[i]
	- false, если все буквы равны
	- false, если первая буква left[i] != right[i] больше чем right[i]

	- true,  если все буквы из минимальной длины равны

*/