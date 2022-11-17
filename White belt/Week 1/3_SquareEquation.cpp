#include <iostream>
#include <cmath>

using namespace std;



int main ()
{
	double a, b, c;

	cin >> a >> b >> c;


	if (a != 0 || b != 0)	// no printing when infinity or 0 roots
	{
		if (a == 0)			// not square at all
		{
			cout << -c / b;
		}
		else
		{
			double D = b*b - 4*a*c;

			if (D > 0)
			{
				double d = sqrt(D);
				cout << (-b + d) / (2*a) << ' ' << (-b - d) / (2*a);
			}
			else if (D == 0)
			{
				cout << -b / (2*a);
			}
		}
	}


	return 0;
}