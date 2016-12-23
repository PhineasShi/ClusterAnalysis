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
	Cluster( vector<vector<double> > &vecs, DistType distType = euclidean, double ratio = 0.5, int m = 2) :vecs(vecs), distType(distType), ratio(ratio), m(m) {};
	~Cluster();
	void miniMax();				//最大最小距离法
	void cMean();				//C均值法

	void showResult();
	void showInClassDist();		//显示类内距离
	void showInterClassDist();	//显示类间距离
	vector<vector<vector<double> > > getResult() { return result; };	//result的getter方法
private:
	vector<vector<double> > vecs;	//输入的数据集
	vector<vector<vector<double> > > result;		//vector<vector<double> >存放每一类的所有vec，其中的第一个vector<double>为该类的聚类中心 
	double ratio;				//最大最小距离法所需的比例参数
	int m;						//闵氏距离所需的参数
	DistType distType;			//距离的类型

	//Show functions
	void showVec(const vector<double> &vec);		//显示节点信息
	void showCenterFound(const vector<double> &vec,const double &dist);	//显示类心信息
	void showVecClustered(const vector<double> &center, const vector<double> &vec, const double &minDist);	//显示每个被聚类的节点

	void getMax(list<vector<double> > lists,vector<double> &maxVec,double &maxDist);				//Get the vec whose min distance to centers is the max among all the vecs, and get the distance too

};