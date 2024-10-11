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
    cout << "输入第一个向量的维度和坐标 eg:3 1 2 3:" << endl;
    cin >> dim;
    x.resize(dim);
    for (int i = 0; i < dim; ++i)
    {
        cin >> x[i];

    }
    a1 = myVector(x);
    cout << "输入第二个向量的维度和坐标:" << endl;
    cin >> dim;
    x.resize(dim);
    for (int i = 0; i < dim; ++i)
    {
        cin >> x[i];

    }
    a2 = myVector(x);

    while (true) {
        cout << "\n1--向量加法" << endl;
        cout << "2--向量减法" << endl;
        cout << "3--向量数乘" << endl;
        cout << "4--向量点乘" << endl;
        cout << "5--向量叉乘" << endl;
        cout << "6--向量模长" << endl;
        cout << "7--判断==" << endl;
        cout << "8--赋值操作" << endl;
        cout << "0--退出测试" << endl;
        cin >> choice;
        
        switch (choice) {
        case 1: {
            try {
                cout << "向量加法结果: " << a1 + a2 << endl;
            }
            catch (const std::invalid_argument& e) {
                cout << "错误：" << e.what() << endl;
            }
            test_myVector();
            break;
        }
        case 2:{
            try {
                cout << "向量减法结果：" << a1 - a2 << endl;
            }
            catch (const std::invalid_argument& e) {
                cout << "错误：" << e.what() << endl;
            }
            test_myVector();
            break;
        } 
        case 3:
            double x;
            cout << "请输入数乘的标量值: ";
            cin >> x;
            cout << "向量数乘结果: " << a1 * x << endl;
            break;
        case 4:
            cout << "向量点乘结果：" << a1 * a2 << endl;
            break;
        case 5:
            cout << "向量叉乘结果: " << a1 % a2 << endl;
            break;
        case 6:
            cout << "向量a1的模长: " << a1.length() << endl;
            break;
        case 7:
            if (a1 == a2)
                cout << "a1 == a2" << endl;
            else
                cout << "a1 != a2" << endl;
            break;
        
        case 8: {
            cout << "请输入新的向量的维度和坐标: ";
            cin >> dim;
            vector<double> y;
            y.resize(dim);
            for (int i = 0; i < dim; ++i)
            {
                cin >> y[i];

            }
            a3 = myVector(y);
            cout << "赋值后的向量a3: " << a3 << endl;
            break;
        }
        case 0:
            return;
        default:
            cout << "无效选项，请重新输入!" << endl;
        }

    }
}




