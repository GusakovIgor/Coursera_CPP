#include <iostream>
#include <sstream>
#include <numeric>

#include <vector>
#include <set>
#include <map>


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



int main() {
	{
	const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
		if (rs.size() != 3) {
			cout << "Wrong amount of items in the set" << endl;
			return 1;
		}

		vector<Rational> v;
		for (auto x : rs) {
			v.push_back(x);
		}
		if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
			cout << "Rationals comparison works incorrectly" << endl;
			return 2;
		}
	}

	{
		map<Rational, int> count;
		++count[{1, 2}];
		++count[{1, 2}];

		++count[{2, 3}];

		if (count.size() != 2) {
			cout << "Wrong amount of items in the map" << endl;
			return 3;
		}
	}

	cout << "OK" << endl;
	return 0;
}