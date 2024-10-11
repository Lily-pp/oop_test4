#include <iostream>
#include<cstring>
#include<assert.h>
#include "myString.h"
#define A 1024
#pragma warning(disable:4996)


myString::myString(const char* Base, long long Len) :base(NULL), len(Len) {

}

myString::myString(const myString& str) {
	base = new char[str.len + 1];
	strcpy(base, str.base);
	len = str.len;
}
/*void myString::Set(const char* p) {
	if (p == NULL) {
		base = new char[1];
		base = '\0';
	}
	else {
		base = new char[strlen(p) + 1];
		strcpy(base, p);
	}
	len = strlen(p);
}*/
void myString::Set(long long cont, char ch) {
	base = new char[cont + 1];
	for (int i = 0; i < cont; i++) {
		base[i] = ch;
	}
	base[cont] = '\0';
	len = cont;
}

void myString::Set(myString& str, int index, int cont) {
	base = new char[cont + 1];
	for (int i = index, j = 0; i < cont + index; i++) {
		base[j++] = str.base[i];
	}
}
myString::~myString() {
	if (len != 0) delete base;
}

myString& myString::operator=(const myString& str) {
	if (&str == this) return *this;
	delete[] base;
	base = new char[strlen(str.base) + 1];
	strcpy(base, str.base);
	return *this;
}

ostream& operator << (ostream& os, const myString& str) {
	return os << str.base;
}
istream& operator >> (istream& is, myString& str) {
	str.base = new char[A];
	return is >> str.base;
}

myString operator+(const myString& str1, const myString& str2) {
	myString str;
	str.base = new char[str1.len + str2.len + 1];
	strcpy(str.base, str1.base);
	strcat(str.base, str2.base);
	return str;
}

char& myString::operator[](int index) {
	return base[index];
}

/* bool operator ==(const myString& str1, const myString& str2) {
	 return strcmp(str1.base, str2.base)==0;
 }
*/

bool operator ==(const myString& str1, const myString& str2) {
	int result = strcmp(str1.base, str2.base);
	if (result != 0) { return false; }
	else { return true; }
}

bool operator >(const myString& str1, const myString& str2) {
	return strcmp(str1.base, str2.base) > 0;
}

bool operator <(const myString& str1, const myString& str2) {
	return strcmp(str1.base, str2.base) < 0;
}

bool operator >=(const myString& str1, const myString& str2) {
	return strcmp(str1.base, str2.base) >= 0;
}

bool operator <=(const myString& str1, const myString& str2) {
	return strcmp(str1.base, str2.base) <= 0;
}

bool operator !=(const myString& str1, const myString& str2) {
	return strcmp(str1.base, str2.base) != 0;
}

int myString::length() const {
	return strlen(base);
}

const char* myString::c_str() {
	return base;
}

void myString::Erase(size_t l_, int len_) {
	assert(l_>=len);
	int len1 = len_ + 1; 
	while (len1--)
	{
        base[l_] = base[l_ + len_ ]; 
	    l_++;
	}
	len = len - len_;
}