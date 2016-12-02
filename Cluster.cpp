#include "Cluster.h"



Cluster::Cluster()
{

}

Cluster::~Cluster()
{
}

void Cluster::miniMax()
{
	//Make the first vec the first center of a class
	vector<double> center = vecs[0];
	vector<vector<double> > cl;
	cl.push_back(center);
	result.push_back(cl);			//Push the new class into the result

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
		}
		else
		{
			break;
		}
	}
	//Clustering with the centers found in minium dist method
	//TODO
}

void Cluster::getMax(list<vector<double> > lists, vector<double> &maxVec, double &maxDist)
{
	vector<double> center;
	for (list<vector<double> >::iterator i = lists.begin(); i != lists.end(); i++)	//Traverse every vecs which are not center
	{
		double minDist;
		for (int j = 0; j < result.size(); j++)	//Traverse every centers
		{
			center = result[j][0];
			Distance dist(*i, center, distType);
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
