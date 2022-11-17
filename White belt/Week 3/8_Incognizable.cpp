#include <iostream>

using namespace std;


// DO NOT GET IT SO COMPLICATED!

/*
class Incognizable
{

public:
	Incognizable () {}

	Incognizable (int initial_x)
	{
		x = initial_x;
	}

	Incognizable (int initial_x, int initial_y)
	{
		x = initial_x;
		y = initial_y;
	}


private:

	int x;
	int y;

};
*/

struct Incognizable
{
	int x = 0;
	int y = 0;
}


/*
int main ()
{
	Incognizable a;
	Incognizable b = {};
	Incognizable c = {0};
	Incognizable d = {0, 1};

	return 0;
}
*/