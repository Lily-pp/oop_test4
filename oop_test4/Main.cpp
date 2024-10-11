#include <iostream>
#include "myVector.h"
#include "myString.h"


int main() {
	int c1;
	cout << "\n选择测试对象" << endl;
	cout<<  "\n1--Vector类" << endl;
	cout << "2--String类" << endl;
	cin >> c1;
	switch (c1) 
	{
	case 1:
		void test_myVector();
		test_myVector(); break;
	case 2:
		void test_myString();
		test_myString(); break;
	}
	

	return 0;
}