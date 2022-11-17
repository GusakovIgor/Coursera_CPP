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
		if (init_denominator == 0)
		{
			throw (invalid_argument("Invalid argument"));
		}

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

	Rational operator * (const Rational& l_op, const Rational& r_op)
	{
		int new_denominator = l_op.Denominator() * r_op.Denominator();
		
		int new_numerator = l_op.Numerator() * r_op.Numerator();
		
		return Rational {new_numerator, new_denominator};
	}

	Rational operator / (const Rational& l_op, const Rational& r_op)
	{
		if (r_op.Numerator() == 0)
		{
			throw (domain_error("Division by zero"));
		}

		return l_op * Rational (r_op.Denominator(), r_op.Numerator());
	}


	bool operator < (const Rational& l_op, const Rational& r_op)
	{
		return l_op.Numerator() * r_op.Denominator() < r_op.Numerator() * l_op.Denominator();
	}


	istream& operator >> (istream& stream, Rational& fraction)
	{
		bool correct = true;

		int new_numerator;
		char separator = 0;
		int new_denominator;
		
		correct = correct && (stream >> new_numerator);
		correct = correct && (stream >> separator);
		correct = correct && (stream >> new_denominator);
		correct = correct && (separator == '/');
		
		if (correct)
		{
			fraction = Rational {new_numerator, new_denominator};
		}

		return stream;
	}

	ostream& operator << (ostream& stream, const Rational& fraction)
	{
		stream << fraction.Numerator() << "/" << fraction.Denominator();
		
		return stream;
	}





int main ()
{
	Rational left_fraction;
	Rational right_fraction;
	char operation;
	
    try
    {
		cin >> left_fraction >> operation >> right_fraction;
    }
    catch (const invalid_argument& error)
    {
    	cout << error.what();
    	return 1;
    }

	try
	{
		switch (operation)
		{
			case '+':
						cout << left_fraction + right_fraction;
						break;
		
			case '-':
						cout << left_fraction - right_fraction;
						break;

			case '*':
						cout << left_fraction * right_fraction;
						break;

			case '/':
						cout << left_fraction / right_fraction;
						break;
		}
    }
    catch (const domain_error& error)
    {
    	cout << error.what();
    	return 1;
    }


    return 0;
}