#include <iostream>
#include <map>
#include <string>

using namespace std;



void BuildLettersCounter (map <char, int>& counter, const string& word);

// bool IsAnagrams (map <char, int>& first_word, map <char, int>& second_word);



int main ()
{
	int num_pairs;
	cin >> num_pairs;


	map <char, int> first_word;
	map <char, int> second_word;

	string word;
	for (int i = 0; i < num_pairs; i++)
	{
		cin >> word;
		BuildLettersCounter (first_word, word);

		cin >> word;
		BuildLettersCounter (second_word, word);

		if (first_word == second_word)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}


	return 0;
}




void BuildLettersCounter (map <char, int>& counter, const string& word)
{
	counter.clear();

	for (char letter : word)
	{
		++counter[letter];
	}
}


/*
bool IsAnagrams (map <char, int>& first_word, map <char, int>& second_word)
{
	if (first_word.size() != second_word.size())
	{
		return false;
	}

	for (auto [letter, count] : first_word)
	{
		if (count != second_word[letter])
		{
			return false;
		}
	}

	return true;
}
*/