//myVector.cpp
#include <iostream>
#include "myVector.h"
#include <stdexcept>

myVector::myVector(int Dim, double defaultVal) : dim(Dim) {
	x.resize(Dim, defaultVal);
}//ԭ�й��캯��
myVector::myVector(const std::vector<double>& vec) :x(vec), dim(vec.size()) {};//��������
myVector::myVector(const myVector& a):dim(a.dim), x(a.x) {}


void myVector::Set(int Dim, double defaultVal) {
	dim = Dim;
	x.resize(Dim, defaultVal);
}
myVector::~myVector() {

}
// �����ӷ�
myVector myVector::operator+(const myVector& a) const {
	if (dim != a.dim) {
	    throw std::invalid_argument("�����ӷ���ά�Ȳ�ƥ��");
	}
	myVector result(*this);
	for (int i = 0; i < dim; ++i) {
		result.x[i] += a.x[i];
	}
	return result;
}
// ��������
myVector myVector::operator-(const myVector& a)const {
	if (dim != a.dim) {
	    throw std::invalid_argument("����������ά�Ȳ�ƥ��");
	}
    myVector result(*this);
    for (int i = 0; i < dim; ++i) {
        result.x[i] -= a.x[i];
    }
    return result;
}

// ��������
myVector myVector::operator*(double scalar) const {
    myVector result(*this);
    for (int i = 0; i < dim; ++i){
        result.x[i] *=scalar;
    }
    return result;
}

// �������
double myVector::operator*(const myVector& a)const {
    if (dim != a.dim) {
	    throw std::invalid_argument("������ˣ�ά�Ȳ�ƥ��");
	}
    double trm = 0.0;
    for (int i = 0; i < dim; ++i) {
        trm += x[i] * a.x[i];
    }
    return trm;
}

// �������
myVector myVector::operator%(const myVector& a) const {
    myVector result(*this);
    if (dim != 3 || a.dim != 3) {
        throw std::invalid_argument("��˽���������ά����");
    }
    return myVector(
        { x[1] * a.x[2] - x[2] * a.x[1],
        x[2] * a.x[0] - x[0] * a.x[2],
        x[0] * a.x[1] - x[1] * a.x[0] });
}

// ����ģ��С����
double myVector::length() const {
    double sq = 0.0;
    for (int i = 0; i < dim; ++i) {
       sq += x[i]*x[i];
    }
    
    return sqrt(sq);
}

//���
bool myVector::operator==(const myVector& a) const {
    if (dim != a.dim) return false;
    for (int i = 0; i < dim; ++i) {
        if (x[i] != a.x[i]) return false;
    }
    return true;
}




// ������������ʵ��
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


// �������������ʵ��
std::istream& operator>>(std::istream& is, myVector& a) {
    std::vector<double> temp;
    double value;
    while (is >> value) {
        temp.push_back(value);
    }
    if (temp.empty()) {
	    throw std::length_error("�������������Ϊ��");
	}
    a.x = std::move(temp);
    a.dim = a.x.size();
    return is;
}



