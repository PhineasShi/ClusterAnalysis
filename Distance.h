#pragma once
#include <math.h>
#include <vector>
using namespace std;

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
	Distance(vector<double> &vec1, vector<double> &vec2, DistType distType = euclidean) :vec1(vec1), vec2(vec2), distType(distType) { dim = vec1.size(); };
	~Distance();

	double getDist();		//计算并返回距离

private:
	double dist;			//计算得到的距离
	int dim;				//向量的维度
	vector<double> vec1;			//需要计算距离的两个向量
	vector<double> vec2;
	DistType distType;		//距离类型
	int m;					//闵氏距离中的参数

	//计算各种距离函数
	void calEuDist();
	void calMaDist();
	void calChDist();
	void calMiDist();
	void calMeDist();		//TODO
};

