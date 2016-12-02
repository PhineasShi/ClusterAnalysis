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
	void miniMax();				//�����С���뷨
	void cMean();				//C��ֵ��


private:
	vector<vector<double> > vecs;
	vector<vector<double> > result;
	DistType distType;
};