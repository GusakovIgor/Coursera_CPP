

vector <int> Reversed (const vector <int>& v)
{
	vector <int> reversed;


	int length = v.size();

	for (int i = length - 1; i >= 0; --i)
	{
		reversed.push_back (v[i]);
	}


	return reversed;
}