#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
using namespace std;

void PrintDeque(deque<int>& d) {
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//deque��ʼ��
void test01() {

	deque<int> d1;
	deque<int> d2(10, 5);  //10��5
	deque<int> d3(d2.begin(), d2.end());
	deque<int> d4(d3);  //��������


	//��ӡd4
	PrintDeque(d4);

}

//��ֵ ��С����
void test02() {

	deque<int> d1;
	deque<int> d2;
	deque<int> d3;
	d1.assign(10, 5);  //ָ��N��Ԫ��
	d2.assign(d1.begin(), d1.end()); //������ָ�����丳ֵ
	d3 = d2; //�ȺŸ�ֵ

	d1.swap(d2); //���������ռ�Ԫ��

	if (d1.empty()) {
		cout << "��!" << endl;
	}
	else {
		cout << "size:" << d1.size() << endl;
	}

	d1.resize(5); //10��Ԫ�أ������Ԫ���ӵ�

}

//deque���������ɾ��
void test03() {

	deque<int> d1;
	d1.push_back(100);
	d1.push_front(200);
	d1.push_back(300);
	d1.push_back(400);
	d1.push_front(500);

	//500 200 100 300 400
	PrintDeque(d1);

	int val = d1.front(); //�õ���ɾ��������
	d1.pop_front(); //ɾ��

	val = d1.back();
	d1.pop_back(); //ɾ�����һ��Ԫ��

}

int main(void) {

	test01();
	test02();
	test03();


	return 0;
}