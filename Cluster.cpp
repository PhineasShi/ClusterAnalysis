﻿#include "Cluster.h"



Cluster::Cluster()
{

}

Cluster::~Cluster()
{
}
//最大最小距离法进行聚类
void Cluster::miniMax()
{
	//Make the first vec the first center of a class
	vector<double> center = vecs[0];
	vector<vector<double> > cl;
	cl.push_back(center);
	result.push_back(cl);			//Push the new class into the result
	cout << "Default center:";
	showVec(center);
	//Transform the vecs to lists for better insert and remove performance
	list<vector<double> > lists;
	for (int i = 0; i < vecs.size(); i++)
	{
		lists.push_back(vecs[i]);
	}
	lists.remove(center);			//Remove the new center from the vecs
	//Find the second center
	double critDist;					//The distance of the first two centers
	getMax(lists, center, critDist);	//Find the second center 
	cout << endl << "Finding new centers:" << endl;
	showCenterFound(center, critDist);
	cl.clear();
	cl.push_back(center);
	result.push_back(cl);			//Push the new class into the result, with the new center as the first vec
	lists.remove(center);			//Remove the new center from the vecs
	//Find other centers
	while (true)
	{
		double dist;
		getMax(lists, center, dist);
		if (dist > critDist*ratio)	//If a new center found
		{
			cl.clear();
			cl.push_back(center);
			result.push_back(cl);	//Push the new class into the result, with the new center as the first vec
			lists.remove(center);	//Remove the new center from the vecs
			showCenterFound(center,dist);
		}
		else
		{
			break;
		}
	}
	//Clustering with the centers found in minium dist method
	cout << endl << "Clustering with the centers found:" << endl;
	for (list<vector<double> >::iterator i = lists.begin(); i != lists.end(); i++)	//Traverse all the free vecs
	{
		double minDist;
		int minInd=0;
		for (int j = 0; j < result.size(); j++)		//Traverse all the centers
		{
			center = result[j][0];
			Distance dist(*i,center,distType,m);
			double distance = dist.getDist();
			if (j == 0)
			{
				minDist = distance;
			}
			else
			{
				minDist = (minDist < distance) ? minDist : distance;
				minInd = (minDist < distance) ? minInd : j;
			}
		}
		result[minInd].push_back(*i);
		showVecClustered(result[minInd][0], *i, minDist);
	}
}
//将聚类后每个类的信息显示出来
void Cluster::showResult()
{
	cout << endl << "Results:" << endl;
	for (int i = 0; i < result.size(); i++)
	{
		vector<vector<double> > vecs = result[i];
		for (int j = 0; j < vecs.size(); j++)
		{
			vector<double> vec = vecs[j];
			showVec(vec);
			if (j == 0)
			{
				cout << ":";
			}
		}
		cout << endl;
	}
}
//显示每个类的类内距离
void Cluster::showInClassDist()
{
	int count = result.size();
	double *dists = new double[count];
	for (int i = 0; i < result.size(); i++)
	{
		double tmpdist = 0;

		vector<vector<double> > vecs = result[i];
		for (int j = 0; j < vecs.size(); j++)
		{
			vector<double> vec1 = vecs[j];
			for (int k = 0; k < vecs.size(); k++)
			{
				vector<double> vec2 = vecs[k];

				if (j != k)
				{
					int dim = vec2.size();
					double var = 0;
					for (int m = 0; m < dim; m++)
					{
						var += pow(vec1[m] - vec2[m], 2);
					}
					tmpdist = sqrt(var);
				}

			}
		}

		dists[i] = tmpdist / vecs.size();
		cout << "第" <<i+1<<"类类内距离为：";
		cout << dists[i] << endl;
	}
	free(dists);
}
//显示每两个类间的类间距离
void Cluster::showInterClassDist()
{
	int count = result.size();
	count = count*(count - 1) / 2;
	double *dists = new double[count];
	int index = 0;
	for (int i = 0; i < result.size(); i++)
	{
		double tmpdist = 0;
		vector<vector<double> > grp1 = result[i];

		for (int j = i; j < result.size(); j++)
		{
			double minDis = DBL_MAX;
			vector<vector<double> > grp2 = result[j];
			if (i != j)
			{
				for (int m = 0; m < grp1.size(); m++)
				{
					vector<double> pnt1 = grp1[m];
					for (int n = 0; n < grp2.size(); n++)
					{
						vector<double> pnt2 = grp2[n];
					
					
							int dim = pnt2.size();
							double var = 0;
							for (int k = 0; k < dim; k++)
							{
								var += pow(pnt1[k] - pnt2[k], 2);
							}
							double temp = sqrt(var);
							minDis = temp < minDis ? temp : minDis;
					}
				}
				dists[index++] = minDis;
				cout << "第" << i + 1 << "类和" << "第" << j + 1 << "类的类间距离是：" << minDis << endl;
			}
			
		}
	}
	free(dists);
}
//显示节点信息
void Cluster::showVec(const vector<double>& vec)
{
	cout << "(" << vec[0];
	for (int k = 1; k < vec.size(); k++)
	{
		cout << "," << vec[k];
	}
	cout << ")";
}
//显示类心信息
void Cluster::showCenterFound(const vector<double>& vec, const double & dist)
{
	cout << "New center found:";
	showVec(vec);
	cout << "\t" << "Max distance to the closest center:" << dist << endl;	
}
//显示每个被聚类的节点
void Cluster::showVecClustered(const vector<double>& center, const vector<double>& vec, const double& minDist)
{
	showVec(center);
	cout << "<<";
	showVec(vec);
	cout << "\t" << "Distance to the closest center:" << minDist << endl;
}
//Get the vec whose min distance to centers is the max among all the vecs, and get the distance too
void Cluster::getMax(list<vector<double> > lists, vector<double> &maxVec, double &maxDist)
{
	maxDist = 0;
	vector<double> center;
	for (list<vector<double> >::iterator i = lists.begin(); i != lists.end(); i++)	//Traverse every vecs which are not center, to get the max distance
	{
		double minDist;
		for (int j = 0; j < result.size(); j++)	//Traversing every centers to get the min distance 
		{
			center = result[j][0];
			Distance dist(*i, center, distType,m);
			double distance = dist.getDist();
			if (j == 0)
			{
				minDist = distance;
			}
			else
			{
				minDist = (minDist < distance) ? minDist : distance;
			}
		}
		if (i == lists.begin())
		{
			maxDist = minDist;
			maxVec = *i;
		}
		else
		{
			maxDist = (maxDist > minDist) ? maxDist : minDist;
			maxVec = (maxDist > minDist) ? maxVec : *i;
		}
	}
}
