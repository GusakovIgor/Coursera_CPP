#include <iostream>
#include <sstream>
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

	Rational operator * (const Rational& l_op, const Rational& r_op)
	{
		int new_denominator = l_op.Denominator() * r_op.Denominator();
		
		int new_numerator = l_op.Numerator() * r_op.Numerator();
		
		return Rational {new_numerator, new_denominator};
	}

	Rational operator / (const Rational& l_op, const Rational& r_op)
	{		
		return l_op * Rational (r_op.Denominator(), r_op.Numerator());
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



int main() {
	{
		ostringstream output;
		output << Rational(-6, 8);
		if (output.str() != "-3/4") {
			cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
			return 1;
		}
	}

	{
		istringstream input("5/7");
		Rational r;
		input >> r;
		bool equal = r == Rational(5, 7);
		if (!equal) {
			cout << "5/7 is incorrectly read as " << r << endl;
			return 2;
		}
	}

	{
		istringstream input("");
		Rational r;
		bool correct = !(input >> r);
		if (!correct) {
			cout << "Read from empty stream works incorrectly" << endl;
			return 3;
		}
	}

	{
		istringstream input("5/7 10/8");
		Rational r1, r2;
		input >> r1 >> r2;
		bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
			return 4;
		}

		input >> r1;
		input >> r2;
		correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
			return 5;
		}
	}

	{
		istringstream input1("1*2"), input2("1/"), input3("/4");
		Rational r1, r2, r3;
		input1 >> r1;
		input2 >> r2;
		input3 >> r3;
		bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
		if (!correct) {
			cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
				 << r1 << " " << r2 << " " << r3 << endl;

			return 6;
		}
	}

	cout << "OK" << endl;
	return 0;
}