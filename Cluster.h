#pragma once
#include "Distance.h"
 
class Cluster
{
public:
	Cluster();
	Cluster(int dim, int num, DistType distType = euclidean) :dim(dim), num(num), distType(distType) {};
	~Cluster();
	void miniMax();
	void cMean();


private:
	double **vecs;
	int dim;
	int num;
	DistType distType;
};