//myVector.h
#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
#include<cmath>
#include<vector>

class myVector{
public:
	myVector(int Dim = 0,double defaultVal=0.0);//���캯����ʼ��Ϊһ����ά����
    myVector(const std::vector<double>& vec);//�������캯��
	myVector(const myVector& a);//�������캯��
	void Set(int Dim, double defaultVal = 0.0);//��ֵ����
	~myVector();

    // �����ӷ�
    myVector  operator+(const myVector& other)const;

    // ��������
    myVector  operator-(const myVector& other)const;

    // ��������
    myVector  operator*(double scalar) const;

    // �������
    double  operator*(const myVector& other)const;

    // �������
    myVector operator%(const myVector& other) const;

    // ����ģ��С����
    double length() const;

    //�ж����
    bool operator==(const myVector& other) const;


       
    
    // ������������
    friend std::ostream& operator<<(std::ostream& os, const myVector& a);

    // �������������
    friend std::istream& operator>>(std::istream& is, myVector& a);


private:
    std::vector<double> x; //���ݳ�Ա�����Լ��������
	int dim;
};

#endif

