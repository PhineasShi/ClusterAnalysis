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
	void miniMax();				//�����С���뷨
	void cMean();				//C��ֵ��

	void showResult();

private:
	vector<vector<double> > vecs;
	vector<vector<vector<double> > > result;		//vector<vector<double> >���ÿһ�������vec�����еĵ�һ��vector<double>Ϊ����ľ������� 
	double ratio;				//�����С���뷨����ı�������
	DistType distType;

	void getMax(list<vector<double> > lists,vector<double> &maxVec,double &maxDist);				//Get the vec whose min distance to centers is the max among all the vecs, and get the distance too

};