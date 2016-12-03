#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "Distance.h"

using namespace std;
 
class Cluster
{
public:
	Cluster();
	Cluster( vector<vector<double> > &vecs, DistType distType = euclidean, double ratio = 0.5) :vecs(vecs), distType(distType), ratio(ratio) {};
	~Cluster();
	void miniMax();				//最大最小距离法
	void cMean();				//C均值法

	void showResult();

private:
	vector<vector<double> > vecs;
	vector<vector<vector<double> > > result;		//vector<vector<double> >存放每一类的所有vec，其中的第一个vector<double>为该类的聚类中心 
	double ratio;				//最大最小距离法所需的比例参数
	DistType distType;

	void getMax(list<vector<double> > lists,vector<double> &maxVec,double &maxDist);				//Get the vec whose min distance to centers is the max among all the vecs, and get the distance too

};