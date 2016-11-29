#pragma once
#include <math.h>
typedef enum DistType
{
	euclidean,
	manhattan,
	chebyshev,
	minkowski,
	measure,
};
class Distance
{
public:
	Distance();
	Distance(int dim, double *vec1, double *vec2,DistType distType) :dim(dim),vec1(vec1),vec2(vec2),distType(distType) {};
	~Distance();

	double getDist();

private:
	double dist;
	int dim;
	double *vec1;
	double *vec2;
	DistType distType;		//距离类型
	int m;					//闵氏距离中的参数

	void calEuDist();
	void calMaDist();
	void calChDist();
	void calMiDist();
	void calMeDist();		//TODO
};

