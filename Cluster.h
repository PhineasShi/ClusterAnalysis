#pragma once
#include "Distance.h"
 
class Cluster
{
public:
	Cluster();
	Cluster(int dim, int num, DistType distType = euclidean) :dim(dim), num(num), distType(distType) {};
	~Cluster();
	void miniMax();				//最大最小距离法
	void cMean();				//C均值法


private:
	double **vecs;
	int dim;
	int num;
	DistType distType;
};