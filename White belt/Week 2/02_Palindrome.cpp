/*
#include <iostream>
#include <string>

using namespace std;


bool IsPalindrom (string str);


int main ()
{
	string str;
	cin >> str;

	if (IsPalindrom (str))
	{
		cout << str << " is a palindrome" << endl;
	}
	else
	{
		cout << str << " is not a palindrome" << endl;
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