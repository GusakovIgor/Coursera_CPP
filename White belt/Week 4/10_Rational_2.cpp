#include <iostream>
#include <numeric>

using namespace std;



class Rational
{

public:

	Rational()
	{
		numerator = 0;
		denominator = 1;
	}

	Rational(int init_numerator, int init_denominator)
	{
		int init_gcd = gcd (init_numerator, init_denominator);

		numerator = init_numerator / init_gcd;
		denominator = init_denominator / init_gcd;

		if (denominator < 0)
		{
			numerator   *= -1;
			denominator *= -1;
		}
	}

	int Numerator() const
	{
		return numerator;
	}

	int Denominator() const
	{
		return denominator;
	}



private:

	int numerator;
	int denominator;


};

	bool operator == (const Rational& l_op, const Rational& r_op)
	{
		return (l_op.Numerator() == r_op.Numerator()) && (l_op.Denominator() == r_op.Denominator());
	}

	Rational operator + (const Rational& l_op, const Rational& r_op)
	{
		int new_denominator = l_op.Denominator() * r_op.Denominator();
		
		int new_numerator = (l_op.Numerator() * r_op.Denominator()) + (r_op.Numerator() * l_op.Denominator());
		
		return Rational {new_numerator, new_denominator};
	}

	Rational operator - (const Rational& l_op, const Rational& r_op)
	{
		int new_denominator = l_op.Denominator() * r_op.Denominator();
		
		int new_numerator = (l_op.Numerator() * r_op.Denominator()) - (r_op.Numerator() * l_op.Denominator());
		
		return Rational {new_numerator, new_denominator};
	}



int main() {
	{
		Rational r1(4, 6);
		Rational r2(2, 3);
		bool equal = r1 == r2;
		if (!equal) {
			cout << "4/6 != 2/3" << endl;
			return 1;
		}
	}

	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a + b;
		bool equal = c == Rational(2, 1);
		if (!equal) {
			cout << "2/3 + 4/3 != 2" << endl;
			return 2;
		}
	}

	{
		Rational a(5, 7);
		Rational b(2, 9);
		Rational c = a - b;
		bool equal = c == Rational(31, 63);
		if (!equal) {
			cout << "5/7 - 2/9 != 31/63" << endl;
			return 3;
		}
	}

	cout << "OK" << endl;
	return 0;
}