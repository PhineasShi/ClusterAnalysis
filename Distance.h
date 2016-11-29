#pragma once
#include <math.h>
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
	Distance(int dim, double *vec1, double *vec2,DistType distType) :dim(dim),vec1(vec1),vec2(vec2),distType(distType) {};
	~Distance();

	double getDist();		//���㲢���ؾ���

private:
	double dist;			//����õ��ľ���
	int dim;				//������ά��
	double *vec1;			//��Ҫ����������������
	double *vec2;
	DistType distType;		//��������
	int m;					//���Ͼ����еĲ���

	//������־��뺯��
	void calEuDist();
	void calMaDist();
	void calChDist();
	void calMiDist();
	void calMeDist();		//TODO
};

