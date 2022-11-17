#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;



void AddSynonyms     (map <string, set <string>>& synonyms_table, string word_1, string word_2);

int  CountSynonyms   (map <string, set <string>>& synonyms_table, string word);

bool CheckIfSynonyms (map <string, set <string>>& synonyms_table, string word_1, string word_2);



int main ()
{
	int num_queries;
	cin >> num_queries;


	map <string, set <string>> synonyms_table;


	string command;

	for (int i = 0; i < num_queries; i++)
	{
		cin >> command;

		if (command == "ADD")
		{
			string word_1;
			string word_2;

			cin >> word_1 >> word_2;

			AddSynonyms (synonyms_table, word_1, word_2);
		}
		else if (command == "COUNT")
		{
			string word;

			cin >> word;

			cout << CountSynonyms (synonyms_table, word) << endl;
		}
		else if (command == "CHECK")
		{
			string word_1;
			string word_2;

			cin >> word_1 >> word_2;

			bool result = CheckIfSynonyms (synonyms_table, word_1, word_2);

			cout << ((result) ? "YES" : "NO") << endl;
		}
		else
		{
			cout << "Unkown command : \"" << command << "\"" << endl;
		}
	}


	return 0;
}



void AddSynonyms (map <string, set <string>>& synonyms_table, string word_1, string word_2)
{
	synonyms_table[word_1].insert(word_2);

	synonyms_table[word_2].insert(word_1);
}


int CountSynonyms (map <string, set <string>>& synonyms_table, string word)
{
	if (synonyms_table.count(word) == 0)
	{
		return 0;
	}
	else
	{
		return synonyms_table[word].size();
	}
}


bool CheckIfSynonyms (map <string, set <string>>& synonyms_table, string word_1, string word_2)
{
	if (synonyms_table.count(word_1) == 0 || synonyms_table.count(word_2) == 0)
	{
		return false;
	}
	
	if (synonyms_table[word_1].count(word_2) != 0)
	{
		return true;
	}
	
	return false;
}