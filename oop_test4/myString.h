//myString.h
#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
using namespace std;

class myString {
public:
	myString(const char* Base = "", long long len = 0);//Ĭ�Ϲ���
	myString(const myString& str);//��������
	//void Set(const char* p);
	void Set(long long cont, char ch);
	void Set(myString& str, int index, int count);
	~myString();//��������

	//��ҪΪ���������
	//string���޸Ĳ���
	myString& operator=(const myString& str);

	friend ostream & operator << (ostream & os, const myString& str);
	friend istream & operator >> (istream & is, myString& str);//����I/O��

	friend myString operator+(const myString& str1, const myString& str2);//ƴ���ַ���

	char& operator[](int index);
	friend bool operator ==(const myString& str1, const myString& str2);
	friend bool operator >(const myString& str1, const myString& str2);
	friend bool operator <(const myString& str1, const myString& str2);
	friend bool operator >=(const myString& str1, const myString& str2);
	friend bool operator <=(const myString& str1, const myString& str2);
	friend bool operator !=(const myString& str1, const myString& str2);//���ع�ϵ�����

	void Erase(size_t pos, int len);
	int length()const;
	const char* c_str();//������Ա����

private:
	char* base;
	long long len;
};

#endif