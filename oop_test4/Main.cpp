#include <iostream>
#include "myVector.h"
#include "myString.h"


int main() {
	int c1;
	cout << "\nѡ����Զ���" << endl;
	cout<<  "\n1--Vector��" << endl;
	cout << "2--String��" << endl;
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