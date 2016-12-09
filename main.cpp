#include <iostream>
#include <fstream>
#include <vector>
#include<string>

#include "Cluster.h"

using namespace std;

void loadTestdata(string path, vector<vector<double> > &vecs);
void  saveResult(Cluster cluster, string path);
void inputData(string path);

int main()
{
	while (true)
	{
		int select = 0;
		cout << "选择数据来源\t（1-文件\t2-手动输入）\t以'#'结束:" << endl;
		cin >> select;
		getchar();
		if (select == 2)
		{
			inputData("test.data");
		}

		string path = "test.data";
		vector<vector<double> > vecs;
		loadTestdata(path, vecs);

		cout << "输入最大最小距离法所需的比例参数:" << endl;
		double ratio;
		cin >> ratio;
		getchar();

		cout << "选择距离算法：" << endl;
		cout << "1-欧式距离" << endl;
		cout << "2-绝对值距离" << endl;
		cout << "3-切氏距离" << endl;
		cout << "4-闵氏距离" << endl;
		cin >> select;
		getchar();
		Cluster *cluster = nullptr;
		switch (select)
		{
		case 1:cluster = new Cluster(vecs, euclidean, ratio); break;
		case 2:cluster = new Cluster(vecs, manhattan, ratio); break;
		case 3:cluster = new Cluster(vecs, chebyshev, ratio); break;
		case 4:
			cout << "输入闵氏距离的参数:" << endl;
			int m;
			cin >> m;
			getchar();
			cluster = new Cluster(vecs, minkowski, ratio, m); break;
		}

		cluster->miniMax();
		cluster->showResult();
		saveResult(*cluster, "result.data");
		char continues = 'N';
		cout << "继续?(Y/N):";
		cin >> continues;
		cout << endl;
		getchar();
		if (continues != 'y'&&continues !='Y')
		{
			break;
		}
	}
	return 0;
}

void loadTestdata(string path, vector<vector<double> > &vecs)
{
	ifstream in;
	in.open(path);

	if (!in)
	{
		cerr << "file open failed!" << endl;
		exit(-1);
	}
	while (!in.eof())
	{
		vector<double> vec;
		double data;
		while (in.peek() != '\n' && !in.eof())
		{
			in >> data;
			vec.push_back(data);
		}
		vecs.push_back(vec);
		in.get();	//read \n
	}
}

void  saveResult(Cluster cluster, string path)
{
	ofstream output;
	output.open(path);
	vector<vector<vector<double> > > result = cluster.getResult();
	for (int i = 0; i < result.size(); i++)
	{
		vector<vector<double> > vecs = result[i];
		for (int j = 0; j < vecs.size(); j++)
		{
			vector<double> vec = vecs[j];
			output << "(" << vec[0];
			for (int k = 1; k < vec.size(); k++)
			{
				output << "," << vec[k];
			}
			output << ")";
			if (j == 0)
			{
				output << ":";
			}
		}
		output << endl;
	}
}


void inputData(string path)
{
	cout << "请输入：" << endl;

	ofstream output;
	output.open(path);
	string strtmp;
	getline(cin, strtmp);
	int line = 0;
	while (!strtmp.empty())
	{
		if (line == 0)
		{
			output << strtmp;
		}			
		else
		{
			output << "\n" << strtmp;
		}
		
		line++;

		getline(cin, strtmp);
		if (strtmp == "#")
		{
			break;
		}
			
	}
	output.flush();
	output.close();
}