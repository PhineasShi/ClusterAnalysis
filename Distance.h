#pragma once
#include <math.h>
typedef enum DistType			//距离类型枚举
{
	euclidean,		//欧式距离
	manhattan,		//绝对值距离
	chebyshev,		//切氏距离
	minkowski,		//闵氏距离
	measure,		//匹配测度
};
class Distance
{
public:
	Distance();
	Distance(int dim, double *vec1, double *vec2,DistType distType) :dim(dim),vec1(vec1),vec2(vec2),distType(distType) {};
	~Distance();

	double getDist();		//计算并返回距离

private:
	double dist;			//计算得到的距离
	int dim;				//向量的维度
	double *vec1;			//需要计算距离的两个向量
	double *vec2;
	DistType distType;		//距离类型
	int m;					//闵氏距离中的参数

	//计算各种距离函数
	void calEuDist();
	void calMaDist();
	void calChDist();
	void calMiDist();
	void calMeDist();		//TODO
};

