#include <iostream>
#include "myString.h"
#pragma warning(disable:4996)

void test_myString() {
	myString s1;
	myString s2;
	myString s3;
	char c[1000];
	int choice,m,n,x,k;
	cout << "�����һ���ַ���:" << endl;
	cin >> s1;
	cout << "\n����ڶ����ַ�����" << endl;
	cin >> s2;
	while (true)
	{
		cout << "\n====================" << endl;
		cout << "1--ƴ���ַ���" << endl;
		cout << "2--��s3=s1��"<< endl;
		cout << "3--�ж�==" << endl;
		cout << "4--�ж�>" << endl;
		cout << "5--�ж�<" << endl;
		cout << "6--�ж�>=" << endl;
		cout << "7--�ж�<=" << endl;
		cout << "8--�ж�!=" << endl;
		cout << "9--���s1�ַ�������" << endl;
		cout << "10--����s1�еĵ�n���ַ�" << endl;
		cout << "11--ɾ��s1�е�x���ַ����k���ַ�" << endl;
		cout << "0--�˳�����" << endl;
		cout << "====================" << endl;
		cin >> choice;
		switch(choice)
		{
		case 1:cout << s1 + s2 << endl; break;
		case 2:s3 = s1;
			    cout << s3; break;
		case 3:if (s1 == s2)
			   cout << "yes"<< endl;
			   else cout << "no" << endl; break;
		case 4:if (s1 > s2)
			   cout << "yes" << endl;
			   else cout << "no" << endl; break;
		case 5:if (s1 < s2)
			   cout << "yes" << endl;
			   else cout << "no" << endl; break;
		case 6:if (s1 >= s2)
			   cout << "yes" << endl;
			   else cout << "no" << endl; break;
		case 7:if (s1 <= s2)
			   cout << "yes" << endl;
			   else cout << "no" << endl; break;
		case 8:if (s1 != s2)
			   cout << "yes" << endl;
			   else cout << "no" << endl; break;
		case 9:m = s1.length();
			   cout <<"����Ϊ��" << m << endl; break;
		case 10:cout << "������n��" << endl;
			   /*cin >> n;
			   n = n - 1;
			   strcpy(c, s1.c_str());
			   cout << c[n];*/
			cin >> n;
			try
			{
				n = n - 1;
				strcpy(c, s1.c_str());
				if (n >= 0 && n < strlen(c))
				{
					cout << c[n] << endl;
				}
				else
				{
					throw std::out_of_range("�±�Խ��");
				}
			}
			catch (const std::out_of_range& e)
			{
				cout << "����: " << e.what() << endl;
			}
			break;
		case 11:cout << "����x��" << endl;
			cin >> x;
			cout << "����k:" << endl;
			cin >> k;
			try {
				if ((x + k) > s1.length())
				{
					throw std::out_of_range("�����ַ�������");
				}
				else {
					s1.Erase(x, k);
					cout << s1.c_str() << endl;
				}
              
			}
			catch (const std::out_of_range& e)
			{
				cout << "����: " << e.what() << endl;
			}
			break;
		case 0:return;
		}

	}
	/*cout << "\nƴ���ַ���:" << s1 + s2;
	s3 = s1;
	cout << "\n��s3=s1�����s3��" << s3;
	if (s1 == s2)cout << "\ns1==s2";
	if (s1 > s2)cout << "\ns1>s2";
	if (s1 < s2)cout << "\ns1<s2";
	if (s1 >= s2)cout << "\ns1>=s2";
	if (s1 <= s2)cout << "\ns1<=s2";
	if (s1 != s2)cout << "\ns1!=s2";
	cout << "\n�ַ���s1�ĳ��ȣ�" << lenth(s1);
*/
}