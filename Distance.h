#pragma once
#include <math.h>
#include <vector>
using namespace std;

typedef enum DistType			//��������ö��
{
	euclidean,		//ŷʽ����
	manhattan,		//����ֵ����
	chebyshev,		//���Ͼ���
	minkowski,		//���Ͼ���
	measure,		//ƥ����
};
class Distance
{
public:
	Distance();
	Distance(vector<double> &vec1, vector<double> &vec2, DistType distType = euclidean, int m = 2, double thr=0) :vec1(vec1), vec2(vec2), distType(distType), m(m), thr(thr) { dim = vec1.size(); };
	~Distance();

	double getDist();		//���㲢���ؾ���

private:
	double dist;			//����õ��ľ���
	int dim;				//������ά��
	vector<double> vec1;			//��Ҫ����������������
	vector<double> vec2;
	DistType distType;		//��������
	int m;					//���Ͼ����еĲ���
	double thr;				//ƥ��������Ķ�ֵ����ֵ

	//������־��뺯��
	void calEuDist();
	void calMaDist();
	void calChDist();
	void calMiDist();
	void calMeDist();		//TODO


	void threshold(vector<double> &vec,double threshold);		//��ֵ������ʹ���ܹ�����ƥ���ȼ���
};

