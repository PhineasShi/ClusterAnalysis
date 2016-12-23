#include "Distance.h"



Distance::Distance()
{
}


Distance::~Distance()
{
}
//dist 成员的getter方法，用于计算并返回dist
double Distance::getDist()
{
	switch (distType)
	{
	case euclidean:
		calEuDist();
		break;
	case manhattan:
		calMaDist();
		break;
	case chebyshev:
		calChDist();
		break;
	case minkowski:
		calMiDist();
		break;
	case measure:
		calMeDist();
		break;
	default:
		break;
	}
	return this->dist;
}
//计算欧氏距离
void Distance::calEuDist()
{
	double var = 0;
	for (int i = 0; i < dim; i++)
	{
		var += pow(vec1[i] - vec2[i], 2);
	}
	dist = sqrt(var);
}
//计算绝对值距离
void Distance::calMaDist()
{
	double sum = 0;
	for (int i = 0; i < dim; i++)
	{
		sum += fabs(vec1[i]-vec2[i]);
	}
	dist = sum;
}
//计算切氏距离
void Distance::calChDist()
{
	double max = 0;
	for (int i = 0; i < dim; i++)
	{
		max = (max > fabs(vec1[i] - vec2[i])) ? max : fabs(vec1[i] - vec2[i]);
	}
	dist = max;
}
//计算闵氏距离
void Distance::calMiDist()
{
	double var = 0;
	for (int i = 0; i < dim; i++)
	{
		var += pow(vec1[i] - vec2[i], m);
	}
	dist = pow(var,1.0/m);
}
//计算匹配测度
void Distance::calMeDist()
{
	double var = 0,var1=0,var2=0;
	for (int i = 0; i < dim; i++)
	{
		var += vec1[i] * vec2[i];
		var1 += vec1[i] * vec1[i];
		var2 += vec2[i] * vec2[i];
	}

	dist = var / (var1+var2-var);
}
