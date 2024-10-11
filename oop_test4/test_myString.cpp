#include <iostream>
#include "myString.h"
#pragma warning(disable:4996)

void test_myString() {
	myString s1;
	myString s2;
	myString s3;
	char c[1000];
	int choice,m,n,x,k;
	cout << "输入第一个字符串:" << endl;
	cin >> s1;
	cout << "\n输入第二个字符串：" << endl;
	cin >> s2;
	while (true)
	{
		cout << "\n====================" << endl;
		cout << "1--拼接字符串" << endl;
		cout << "2--令s3=s1："<< endl;
		cout << "3--判断==" << endl;
		cout << "4--判断>" << endl;
		cout << "5--判断<" << endl;
		cout << "6--判断>=" << endl;
		cout << "7--判断<=" << endl;
		cout << "8--判断!=" << endl;
		cout << "9--输出s1字符串长度" << endl;
		cout << "10--查找s1中的第n个字符" << endl;
		cout << "11--删除s1中第x个字符后的k个字符" << endl;
		cout << "0--退出程序" << endl;
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
			   cout <<"长度为：" << m << endl; break;
		case 10:cout << "请输入n：" << endl;
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
					throw std::out_of_range("下标越界");
				}
			}
			catch (const std::out_of_range& e)
			{
				cout << "错误: " << e.what() << endl;
			}
			break;
		case 11:cout << "输入x：" << endl;
			cin >> x;
			cout << "输入k:" << endl;
			cin >> k;
			try {
				if ((x + k) > s1.length())
				{
					throw std::out_of_range("超出字符串长度");
				}
				else {
					s1.Erase(x, k);
					cout << s1.c_str() << endl;
				}
              
			}
			catch (const std::out_of_range& e)
			{
				cout << "错误: " << e.what() << endl;
			}
			break;
		case 0:return;
		}

	}
	/*cout << "\n拼接字符串:" << s1 + s2;
	s3 = s1;
	cout << "\n令s3=s1，输出s3：" << s3;
	if (s1 == s2)cout << "\ns1==s2";
	if (s1 > s2)cout << "\ns1>s2";
	if (s1 < s2)cout << "\ns1<s2";
	if (s1 >= s2)cout << "\ns1>=s2";
	if (s1 <= s2)cout << "\ns1<=s2";
	if (s1 != s2)cout << "\ns1!=s2";
	cout << "\n字符串s1的长度：" << lenth(s1);
*/
}