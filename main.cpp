#include <iostream>
#include <fstream>
#include <vector>

#include "Cluster.h"

using namespace std;

void loadTestdata(string path, vector<vector<double> > &vecs);
void writeTestData(string fileName,const vector<vector<double> > &vecs);	//TODO: Write test Data set to file
void readTestDataFromKeyBoard(vector<vector<double> > &vecs);				//TODO: Get test Data set from keyboard

int main()
{
	string path = "data.data";
	vector<vector<double> > vecs;
	loadTestdata(path, vecs);
	Cluster cluster(vecs,euclidean,0.6);
	cluster.miniMax();
	cluster.showResult();
	system("pause");
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
		in.get();	//read \n
	}
}