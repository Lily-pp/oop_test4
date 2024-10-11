#include<iostream>
#include<cmath>
#include<vector>
#include "myVector.h"
using namespace std;

void test_myVector() {
    myVector a1;
    myVector a2;
    myVector a3;
    int dim;
    vector<double> x;
    int choice;
    cout << "�����һ��������ά�Ⱥ����� eg:3 1 2 3:" << endl;
    cin >> dim;
    x.resize(dim);
    for (int i = 0; i < dim; ++i)
    {
        cin >> x[i];

    }
    a1 = myVector(x);
    cout << "����ڶ���������ά�Ⱥ�����:" << endl;
    cin >> dim;
    x.resize(dim);
    for (int i = 0; i < dim; ++i)
    {
        cin >> x[i];

    }
    a2 = myVector(x);

    while (true) {
        cout << "\n1--�����ӷ�" << endl;
        cout << "2--��������" << endl;
        cout << "3--��������" << endl;
        cout << "4--�������" << endl;
        cout << "5--�������" << endl;
        cout << "6--����ģ��" << endl;
        cout << "7--�ж�==" << endl;
        cout << "8--��ֵ����" << endl;
        cout << "0--�˳�����" << endl;
        cin >> choice;
        
        switch (choice) {
        case 1: {
            try {
                cout << "�����ӷ����: " << a1 + a2 << endl;
            }
            catch (const std::invalid_argument& e) {
                cout << "����" << e.what() << endl;
            }
            test_myVector();
            break;
        }
        case 2:{
            try {
                cout << "�������������" << a1 - a2 << endl;
            }
            catch (const std::invalid_argument& e) {
                cout << "����" << e.what() << endl;
            }
            test_myVector();
            break;
        } 
        case 3:
            double x;
            cout << "���������˵ı���ֵ: ";
            cin >> x;
            cout << "�������˽��: " << a1 * x << endl;
            break;
        case 4:
            cout << "������˽����" << a1 * a2 << endl;
            break;
        case 5:
            cout << "������˽��: " << a1 % a2 << endl;
            break;
        case 6:
            cout << "����a1��ģ��: " << a1.length() << endl;
            break;
        case 7:
            if (a1 == a2)
                cout << "a1 == a2" << endl;
            else
                cout << "a1 != a2" << endl;
            break;
        
        case 8: {
            cout << "�������µ�������ά�Ⱥ�����: ";
            cin >> dim;
            vector<double> y;
            y.resize(dim);
            for (int i = 0; i < dim; ++i)
            {
                cin >> y[i];

            }
            a3 = myVector(y);
            cout << "��ֵ�������a3: " << a3 << endl;
            break;
        }
        case 0:
            return;
        default:
            cout << "��Чѡ�����������!" << endl;
        }

    }
}




