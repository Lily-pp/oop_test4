//myVector.cpp
#include <iostream>
#include "myVector.h"
#include <stdexcept>

myVector::myVector(int Dim, double defaultVal) : dim(Dim) {
	x.resize(Dim, defaultVal);
}//原有构造函数
myVector::myVector(const std::vector<double>& vec) :x(vec), dim(vec.size()) {};//新增构造
myVector::myVector(const myVector& a):dim(a.dim), x(a.x) {}


void myVector::Set(int Dim, double defaultVal) {
	dim = Dim;
	x.resize(Dim, defaultVal);
}
myVector::~myVector() {

}
// 向量加法
myVector myVector::operator+(const myVector& a) const {
	if (dim != a.dim) {
	    throw std::invalid_argument("向量加法：维度不匹配");
	}
	myVector result(*this);
	for (int i = 0; i < dim; ++i) {
		result.x[i] += a.x[i];
	}
	return result;
}
// 向量减法
myVector myVector::operator-(const myVector& a)const {
	if (dim != a.dim) {
	    throw std::invalid_argument("向量减法：维度不匹配");
	}
    myVector result(*this);
    for (int i = 0; i < dim; ++i) {
        result.x[i] -= a.x[i];
    }
    return result;
}

// 向量数乘
myVector myVector::operator*(double scalar) const {
    myVector result(*this);
    for (int i = 0; i < dim; ++i){
        result.x[i] *=scalar;
    }
    return result;
}

// 向量点乘
double myVector::operator*(const myVector& a)const {
    if (dim != a.dim) {
	    throw std::invalid_argument("向量点乘：维度不匹配");
	}
    double trm = 0.0;
    for (int i = 0; i < dim; ++i) {
        trm += x[i] * a.x[i];
    }
    return trm;
}

// 向量叉乘
myVector myVector::operator%(const myVector& a) const {
    myVector result(*this);
    if (dim != 3 || a.dim != 3) {
        throw std::invalid_argument("叉乘仅适用于三维向量");
    }
    return myVector(
        { x[1] * a.x[2] - x[2] * a.x[1],
        x[2] * a.x[0] - x[0] * a.x[2],
        x[0] * a.x[1] - x[1] * a.x[0] });
}

// 向量模大小函数
double myVector::length() const {
    double sq = 0.0;
    for (int i = 0; i < dim; ++i) {
       sq += x[i]*x[i];
    }
    
    return sqrt(sq);
}

//相等
bool myVector::operator==(const myVector& a) const {
    if (dim != a.dim) return false;
    for (int i = 0; i < dim; ++i) {
        if (x[i] != a.x[i]) return false;
    }
    return true;
}




// 输出运算符重载实现
std::ostream& operator<<(std::ostream& os, const myVector& a) {
    os << "(";
    for (size_t i = 0; i < a.dim; ++i) {
        os << a.x[i];
        if (i != a.dim - 1) {
            os << ", ";
        }
    }
    os << ")";
    return os;
}


// 输入运算符重载实现
std::istream& operator>>(std::istream& is, myVector& a) {
    std::vector<double> temp;
    double value;
    while (is >> value) {
        temp.push_back(value);
    }
    if (temp.empty()) {
	    throw std::length_error("输入的向量不能为空");
	}
    a.x = std::move(temp);
    a.dim = a.x.size();
    return is;
}



