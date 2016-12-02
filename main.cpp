#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void loadTestdata(string path, vector<vector<double> > &vecs);

int main()
{
	string path = "data.data";
	vector<vector<double> > vecs;
	loadTestdata(path, vecs);
	return 0;
}

void loadTestdata(string path, vector<vector<double> > &vecs)
{
	ifstream in;
	in.open(path);

	if (!in)
	{
		cerr << "file open failed!" << endl;
		exit(-1);
	}
	while (!in.eof())
	{
		vector<double> vec;
		double data;
		while (in.peek() != '\n' && !in.eof())
		{
			in >> data;
			vec.push_back(data);
		}
		vecs.push_back(vec);
		in.get();
	}
}
