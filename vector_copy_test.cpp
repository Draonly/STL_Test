#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//���������������ͨ����һ������
//���������������ͨ�����������ղ���
//�������󳬳��˺����ĸ������������Ա��溯�����õ�״̬
struct MyPrint {
	MyPrint() {
		mNum = 0;
	}
	void operator()(int val) {
		mNum++;
		cout << val << endl;
	}
public:
	int mNum;
};

/*
int num = 0; //�������У���������ȥʹ��ȫ�ֱ��� ��������
void MyPrint02(int val) {
	num++;
	cout << val << endl;
}
*/

void test02() {

	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//���㺯�����ô���
#if 0
	MyPrint02(10);
	MyPrint02(20);
	cout << num << endl;

	MyPrint print;
	print(10);
	print(20);
	cout << print.mNum << endl;
#endif

	MyPrint print;
	MyPrint print02 = for_each(v.begin(), v.end(), print);

	cout << "print���ô���:" << print.mNum << endl;
	//print02 �����������ص�����Ҫ��ӡ�ĵ��ô�����
	cout << "print���ô���:" << print02.mNum << endl;
}

int main(void) {

	test02();

	return 0;
}