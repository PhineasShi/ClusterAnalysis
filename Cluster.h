#pragma once
#include <vector>
#include "Distance.h"

using namespace std;
 
class Cluster
{
public:
	Cluster();
	Cluster( vector<vector<double> > &vecs, DistType distType = euclidean) :vecs(vecs), distType(distType) {};
	~Cluster();
	void miniMax();				//最大最小距离法
	void cMean();				//C均值法


private:
	vector<vector<double> > vecs;
	vector<vector<double> > result;
	DistType distType;
};