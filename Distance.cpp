#include "Distance.h"



Distance::Distance()
{
}


Distance::~Distance()
{
}

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

void Distance::calEuDist()
{
	double var = 0;
	for (int i = 0; i < dim; i++)
	{
		var += pow(vec1[i] - vec2[i], 2);
	}
	dist = sqrt(var);
}

void Distance::calMaDist()
{
	double sum = 0;
	for (int i = 0; i < dim; i++)
	{
		sum += fabs(vec1[i]-vec2[i]);
	}
	dist = sum;
}

void Distance::calChDist()
{
	double max = 0;
	for (int i = 0; i < dim; i++)
	{
		max = (max > fabs(vec1[i] - vec2[i])) ? max : fabs(vec1[i] - vec2[i]);
	}
	dist = max;
}

void Distance::calMiDist()
{
	double var = 0;
	for (int i = 0; i < dim; i++)
	{
		var += pow(vec1[i] - vec2[i], m);
	}
	dist = pow(var,1.0/m);
}

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
