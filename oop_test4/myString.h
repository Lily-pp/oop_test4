//myString.h
#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
using namespace std;

class myString {
public:
	myString(const char* Base = "", long long len = 0);//默认构造
	myString(const myString& str);//拷贝构造
	//void Set(const char* p);
	void Set(long long cont, char ch);
	void Set(myString& str, int index, int count);
	~myString();//析构函数

	//主要为运算符重载
	//string的修改操作
	myString& operator=(const myString& str);

	friend ostream & operator << (ostream & os, const myString& str);
	friend istream & operator >> (istream & is, myString& str);//重载I/O流

	friend myString operator+(const myString& str1, const myString& str2);//拼接字符串

	char& operator[](int index);
	friend bool operator ==(const myString& str1, const myString& str2);
	friend bool operator >(const myString& str1, const myString& str2);
	friend bool operator <(const myString& str1, const myString& str2);
	friend bool operator >=(const myString& str1, const myString& str2);
	friend bool operator <=(const myString& str1, const myString& str2);
	friend bool operator !=(const myString& str1, const myString& str2);//重载关系运算符

	void Erase(size_t pos, int len);
	int length()const;
	const char* c_str();//其他成员函数

private:
	char* base;
	long long len;
};

#endif