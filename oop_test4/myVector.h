//myVector.h
#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
#include<cmath>
#include<vector>

class myVector{
public:
	myVector(int Dim = 0,double defaultVal=0.0);//构造函数初始化为一个三维向量
    myVector(const std::vector<double>& vec);//新增构造函数
	myVector(const myVector& a);//拷贝构造函数
	void Set(int Dim, double defaultVal = 0.0);//赋值函数
	~myVector();

    // 向量加法
    myVector  operator+(const myVector& other)const;

    // 向量减法
    myVector  operator-(const myVector& other)const;

    // 向量数乘
    myVector  operator*(double scalar) const;

    // 向量点乘
    double  operator*(const myVector& other)const;

    // 向量叉乘
    myVector operator%(const myVector& other) const;

    // 向量模大小函数
    double length() const;

    //判断相等
    bool operator==(const myVector& other) const;


       
    
    // 输出运算符重载
    friend std::ostream& operator<<(std::ostream& os, const myVector& a);

    // 输入运算符重载
    friend std::istream& operator>>(std::istream& is, myVector& a);


private:
    std::vector<double> x; //数据成员可以自己按需添加
	int dim;
};

#endif

