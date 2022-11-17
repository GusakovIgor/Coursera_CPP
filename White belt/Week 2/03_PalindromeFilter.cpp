/*
#include <iostream>
#include <string>
#include <vector>

using namespace std;



bool IsPalindrom (string str);

vector <string> PalindromFilter (vector <string> words, int minLength);



int main ()
{
	int N, min_length;
	cin >> N >> min_length;

	string word;
	vector <string> words;
	for (int i = 0; i < N; i++)
	{
		cin >> word;
		words.push_back (word);
	}


	vector <string> filtered_words = PalindromFilter (words, min_length);

	int size = filtered_words.size();

	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << " " << filtered_words[i] << endl;
	}


	return 0;
}
*/


bool IsPalindrom (string str)
{
	int length = str.size();

	int begin = 0;
	int end   = length - 1;

	while (end > begin)
	{
		if (str[begin++] != str[end--])
		{
			return false;
		}
	}

	return true;
}


vector <string> PalindromFilter (vector <string> words, int minLength)
{
	vector <string> filtered_words;

	for (auto str : words)
	{
		if (IsPalindrom (str) && str.size() >= minLength)
		{
			filtered_words.push_back (str);
		}
	}

	return filtered_words;
}