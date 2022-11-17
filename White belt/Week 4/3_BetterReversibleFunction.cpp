/*
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;



struct Image
{
	double quality;
	double freshness;
	double rating;
};

struct Params
{
	double a;
	double b;
	double c;
};
*/



class ElementaryOperation
{

public:

	ElementaryOperation (char init_operation, double init_operand)
	{
		operation = init_operation;
		r_operand = init_operand;
	}


	double Apply (double l_operand) const
	{
		switch (operation)
		{
			case '+':	return l_operand + r_operand;

			case '-':	return l_operand - r_operand;

			case '*':	return l_operand * r_operand;

			case '/':	return l_operand / r_operand;
		}
	}


	void Invert ()
	{
		switch (operation)
		{
			case '+':	operation = '-';
						break;

			case '-':	operation = '+';
						break;

			case '*':	operation = '/';
						break;

			case '/':	operation = '*';
						break;
		}
	} 



private:
	char operation;
	double r_operand;

};


class Function
{

public:


	double Apply (double operand) const
	{
		for (const ElementaryOperation& operation : operations)
		{
			operand = operation.Apply (operand);
		}

		return operand;
	}


	void AddPart (char operation, double operand)
	{
		operations.push_back({operation, operand});		// Calling customized constructor, that we created for ElementaryOperation class
	}


	void Invert ()
	{
		for (ElementaryOperation& operation : operations)
		{
			operation.Invert();
		}

		reverse (begin(operations), end(operations));
	}



private:
	vector <ElementaryOperation> operations;

};


/*
Function MakeWeightFunction(const Params& params,
                            const Image& image) {
  Function function;
  function.AddPart('*', params.a);
  function.AddPart('-', image.freshness * params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}

int main() {
  Image image = {10, 2, 6};
  Params params = {4, 2, 6};
  cout << ComputeImageWeight(params, image) << endl;
  cout << ComputeQualityByWeight(params, image, 52) << endl;
  return 0;
}
*/