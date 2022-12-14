#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


class ReversibleString
{

public:

	ReversibleString () {}

	ReversibleString (const string& init_value)
	{
		value = init_value;
	}


	void Reverse ()
	{
		// int length = value.size();
		
		// int begin = 0;
		// int end   = length - 1;

		// while (begin < end)
		// {
		// 	swap (value[begin++], value[end--]);
		// }


		// There is function in algorithms:

		reverse (begin(value), end(value));
	}


	string ToString () const
	{
		return value;
	}



private:

	string value;

};

/*
int main ()
{
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;
  
  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;
  
  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;
  
  return 0;
}
*/