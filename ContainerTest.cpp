#include <iostream>
#include<vector> //��̬���� �ɱ�����
#include<algorithm> //�㷨
using namespace std;

//�����ж�ȡ
#if 0
cin.get(buf, 256); //����������
cin.getline() //����ж���
#endif 

/*STL Hello World����
Vectorʹ�ã����ڱ��������ͼ��Զ����������͡�ָ��ȣ�
Vector��Ԫ�ر�����ʹ�õ�������for_each���ַ���
*/
namespace ContainerTest
{
	void PrintVector(int v) {
		cout << v << " ";
	}

	//STL�����﷨
	void test01() {
		//����һ��������������ָ�����������ŵ�Ԫ��������Int
		vector<int> v;
		v.push_back(10);
		v.push_back(20);
		v.push_back(30);
		v.push_back(40);

		//ͨ��STL�ṩ��for_each�㷨
		//�����ṩ�ĵ�����
		//vector<int>::iterator ����������
		vector<int>::iterator pBegin = v.begin();
		vector<int>::iterator pEnd = v.end();

		//�����п��ܴ�Ż������������ͣ�Ҳ���ܴ���Զ�����������
		for_each(pBegin, pEnd, PrintVector);
	}

	//����Ҳ���Դ���Զ�����������
	class Person {
	public:
		Person(int age, int id) :age(age), id(id) {}
	public:
		int age;
		int id;
	};

	void test02() {

		//��������������ָ��������Ԫ��������Person
		vector<Person> v;
		Person p1(10, 20), p2(30, 40), p3(50, 60);
		v.push_back(p1);
		v.push_back(p2);
		v.push_back(p3);

		//����
		for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
			cout << (*it).age << " " << (*it).id << endl;
		}
	}

	//�������Perosn����ָ�룬���� ��������ʽ��ӡ
	void test03()
	{
		//��������������ָ��������Ԫ��������Person*
		vector<Person*> v;
		Person p1(10, 20), p2(30, 40), p3(50, 60);
		v.push_back(&p1);
		v.push_back(&p2);
		v.push_back(&p3);

		vector<Person*>::iterator it;
		for (it = v.begin(); it != v.end(); it++)
		{
			cout << " Age: " << (*(*it)).age << " ID: " << (*(*it)).id << endl;
		}
	}

}

/*string����
string�ĳ�ʼ����ȡֵ��ƴ�ӣ����ң�ɾ�����滻���Ƚϵȳ��ò���
*/
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
#include<string>
namespace StringTest {
	using namespace std;

	//��ʼ��
	void test01() {

		string s1; //�����޲ι���
		string s2(10, 'a');
		string s3("abcdefg");
		string s4(s3); //��������

		cout << "*********  string init  *********";
		cout << s1 << endl;
		cout << s2 << endl;
		cout << s3 << endl;
		cout << s4 << endl;
		cout << endl;
}

	//��ֵ����
	void test02() {

		string s1;
		string s2("appp");
		s1 = "abcdef";
		cout << endl << "*********  string copy  *********" << endl;
		cout << s1 << endl;
		s1 = s2;
		cout << s1 << endl;
		s1 = 'a';
		cout << s1 << endl;

		//��Ա����assign
		s1.assign("jkl");
		cout << s1 << endl;
	}

	//ȡֵ����
	void test03() {

		cout << endl << "*********  string []  *********" << endl;
		string s1 = "abcdefg";

		//����[]������
		//�������Խ��ͱ�����
		for (int i = 0; i < s1.size(); i++) {
			cout << s1[i] << " ";
		}
		cout << endl;

		//at��Ա����
		//�������Խ�磬���׳��쳣
		for (int i = 0; i < s1.size(); i++) {
			cout << s1.at(i) << " ";
		}
		cout << endl;

		//����[]��ʽ �������Խ�磬ֱ�ӹ���
		//at��ʽ ����Խ�� ���쳣out_of_range

		try {
			//cout << s1[100] << endl;
			cout << s1.at(100) << endl;
		}
		//�ܹ������κ��쳣�� catch ���
		catch (...) {
			cout << "Խ��!" << endl;
		}

	}

	//ƴ�Ӳ���
	void test04() {
		string s = "abcd";
		string s2 = "1111";
		s += "abcd";
		s += s2;
		cout << endl << "*********  string append  *********" << endl;
		cout << "s = " << s << endl;

		//append ��ӵ�β��
		string s3 = "2222";
		s2.append(s3);
		cout << "s2 = " << s2 << endl;


		string s4 = s2 + s3;
		cout << "s4 = " << s4 << endl;
	}

	//���Ҳ���
	void test05() {

		string s = "abcdefghjfgkl";
		//���ҵ�һ�γ��ֵ�λ��
		int pos = s.find("fg");
		cout << endl << "*********  string find  *********" << endl;
		cout << "pos:" << pos << endl;

		//�������һ�γ��ֵ�λ��
		pos = s.rfind("fg");
		cout << "pos:" << pos << endl;

	}

	//string�滻
	void test06() {
		string s = "abcdefg";
		s.replace(3, 2, "111");
		cout << endl << "*********  string replace  *********" << endl;
		cout << "string replace test: " << s << endl;
	}

	//string�Ƚ�
	void test07() {

		string s1 = "abcd";
		string s2 = "abce";
		cout << endl << "*********  string compare  *********" << endl;
		if (s1.compare(s2) == 0) {
			cout << "�ַ������!" << endl;
		}
		else {
			cout << "�ַ��������!" << endl;
		}

	}

	//�Ӵ�����
	void test08() {

		string s = "abcdefg";
		string mysubstr = s.substr(1, 7);
		cout << endl << "*********  string substr  *********" << endl;
		cout << mysubstr << endl;
	}

	//�����ɾ��
	void test09() {
		cout << endl << "*********  string insert and delete  *********" << endl;
		string s = "abcdefg";
		s.insert(3, "222");
		cout << s << endl;

		string ss = "kkk";
		s.insert(3, ss);
		cout << s << endl;

		s.erase(0, 2);
		cout << s << endl;
	}
}


/*Vector����
Vector�ĳ�ʼ������ֵ����ȡ����,�����ɾ�����ȳ��ò���
*/
#include<vector>
namespace VectorTest {
	

	void printVector(vector<int>& v) {
		for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}

	//��ʼ��
	void test01() {

		vector<int> vl;//Ĭ�Ϲ���

		//ʹ�������ʼ��vector
		int arr[] = { 10, 20, 30, 40 };
		vector<int> v2(arr, arr + sizeof(arr) / sizeof(int));
		//
		vector<int> v3(v2.begin(), v2.end());
		vector<int> v4(v3);    //��������

		printVector(v2);
		printVector(v3);
		printVector(v4);
	}

	//���ø�ֵ����
	void test02() {


		int arr[] = { 10, 20, 30, 40 };
		vector<int> vl1(arr, arr + sizeof(arr) / sizeof(int));//Ĭ�Ϲ���

		//��Ա������ʹ�õ�����
		vector<int> v2;
		v2.assign(vl1.begin(), vl1.end());

		//����=
		vector<int> v3;
		v3 = v2;

		int arr1[] = { 100, 200, 300, 400 };
		vector<int> v4(arr1, arr1 + sizeof(arr) / sizeof(int));//Ĭ�Ϲ���

		cout << "----------Vector ��ֵ--------" << endl;
		printVector(vl1);
		printVector(v2);
		printVector(v3);
		printVector(v4);

		cout << "------------------" << endl;

		//������ʵ���ǽ����ĸ��Ե�ָ���ڴ�ռ��ָ��
		v4.swap(vl1);
		printVector(vl1);
		printVector(v2);
		printVector(v3);
		printVector(v4);

	}

	//��С����
	void test03() {

		int arr1[] = { 100, 200, 300, 400 };
		vector<int> v4(arr1, arr1 + sizeof(arr1) / sizeof(int));//Ĭ�Ϲ���

		cout << "size��" << v4.size() << endl;
		if (v4.empty() == true) {
			cout << "�գ�" << endl;
		}
		else {
			cout << "���գ�" << endl;
		}

		printVector(v4);
		//Ԫ�ظ�����Ϊ2�������ɾ��
		v4.resize(2);
		printVector(v4);
		//��Ԫ�ظ�����Ϊ8��������Ĭ��0���
		v4.resize(6);
		printVector(v4);
		//��Ԫ�ظ�����Ϊ8��������1���
		v4.resize(8, 1);
		printVector(v4);

		for (int i = 0; i < 10000; i++) {
			v4.push_back(i);
		}
		cout << "size��" << v4.size() << endl;  //Ԫ�صĸ��� 
		cout << "����:" << v4.capacity() << endl; //���� 


	}

	//vector��ȡ����
	void test04() {

		int arr1[] = { 100, 200, 300, 400 };
		vector<int> v4(arr1, arr1 + sizeof(arr1) / sizeof(int));//Ĭ�Ϲ���

		//ʹ���±�ȡ����
		for (int i = 0; i < v4.size(); i++) {
			cout << v4[i] << " ";
		}
		cout << endl;


		//ʹ��at
		for (int i = 0; i < v4.size(); i++) {
			cout << v4.at(i) << " ";
		}
		cout << endl;


		//����: at���쳣 []�����쳣
		try
		{
			cout << v4.at(1000) << " ";
		}
		catch (...)
		{
			cout << "Out of range..." << endl;
		}

		//front����Ԫ�صĵ�һ��Ԫ�أ�back�������һ��Ԫ��
		cout << "front:" << v4.front() << endl;
		cout << "back:" << v4.back() << endl;
	}

	//�����ɾ��
	void test05() {

		vector<int> v;
		v.push_back(10);
		v.push_back(20);

		v.insert(v.begin(), 30); //ͷ���� 30
		v.insert(v.end(), 40);  //ĩβ���� 40

		v.insert(v.begin() + 2, 100); //vector֧���������

		//֧�������±�ģ�һ�㶼֧���������
		//����������ֱ��+2 +3 -2 -5����
		printVector(v);

		//ɾ������
		v.erase(v.begin());  //ɾ����һ��Ԫ��
		printVector(v);
		v.erase(v.begin() + 1, v.end());
		printVector(v);
		v.clear();   //���
		cout << "size:" << v.size() << endl;
	}

	//����swap�����ռ�
	void test06() {

		//vector���Ԫ�� �����Զ����� ��ɾ��Ԫ��ʱ�򣬻��Զ�������

		vector<int> v;
		for (int i = 0; i < 100000; i++) {
			v.push_back(i);
		}

		cout << "size:" << v.size() << endl;
		cout << "capacity:" << v.capacity() << endl;

		v.resize(10);
		cout << "--------------" << endl;
		cout << "size:" << v.size() << endl;
		cout << "capacity:" << v.capacity() << endl;

		//�����ռ�
		//����ʹ��V��ʼ��һ���������󣬲������V��Ԫ�ظ�����ʼ�����Լ���Ȼ����v����
		vector<int>(v).swap(v);

		cout << "--------------" << endl;
		cout << "size:" << v.size() << endl;
		cout << "capacity:" << v.capacity() << endl;
	}

	//reserve Ԥ���ռ� resize����
	void test07() {
		int num = 0;
		int* address = NULL;

		vector<int> v;
		v.reserve(100000);
		for (int i = 0; i < 100000; i++) {
			v.push_back(i);
			//ͳ��һ�£������ڴ����ͷŵĴ���
			if (address != &(v[0])) {
				address = &(v[0]);
				num++;
			}
		}

		cout << "num:" << num << endl;

		//�����֪���������Ҫ�洢��Ԫ�ظ�������ô�������reserveԤ���ռ�
		//�����ڴ������ͷŵĴ�����

	}
}

#include <deque>
namespace DequeTest {
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;

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
		cout << "size:" << d1.size() << endl;

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
		PrintDeque(d1);
		val = d1.back();
		d1.pop_back(); //ɾ�����һ��Ԫ��

	}

}

#include<stack>
namespace StackTest {
	void test01() {


		//��ʼ��
		stack<int> s1;
		stack<int> s2(s1);

		//stack����
		s1.push(10);
		s1.push(20);
		s1.push(30);
		s1.push(100);
		cout << "ջ��Ԫ��:" << s1.top() << endl;
		s1.pop(); //ɾ��ջ��Ԫ��

		//��ӡջ����������
		while (!s1.empty()) {
			cout << s1.top() << " " <<endl;
			s1.pop();
		}

		cout << "size��" << s1.size() << endl;
		//��ҵ2 ջ������Ŷ���

	}

	//��ҵ1 ջ������Ŷ���ָ��
	void test02() {
		ContainerTest::Person p1(20, 30), p2(30, 40);
		stack<ContainerTest::Person*> s;
		s.push(&p1);
		s.push(&p2);

		cout << "stack point test: " << (*(s.top())).age << endl;
		s.pop();
		cout << "stack point test: " << (*(s.top())).age << endl;
		
	}

	//��ҵ2 ջ������Ŷ���
	void test03() {
		ContainerTest::Person p1(20, 30), p2(30, 40);
		stack<ContainerTest::Person> s;
		s.push(p1);
		s.push(p2);
		cout << "stack  test: " << (s.top()).age << endl;
	}
}

#include <queue>
namespace QueueTest {
	void test01() {
		queue<int> q; //��������
		q.push(10);
		q.push(20);
		q.push(30);
		q.push(40);

		cout << "��β��" << q.back() << endl;

		//���˳��? 10 20 30 40
		while (q.size() > 0) {

			cout << q.front() << " "; //�����ͷԪ��
			q.pop(); //ɾ����ͷ

		}
		cout << endl;
		//��ҵ1 queue������Ŷ���ָ��
	}

	//queue�������stack����
	void test02() {
		stack<int> stk1, stk2;
		queue<stack<int>> q;
		stk1.push(10);
		stk1.push(29);
		stk1.push(203);

		stk2.push(120);
		stk2.push(229);
		stk2.push(2203);
		q.push(stk1);
		q.push(stk2);

		cout << "queue�������stack���� test..q.size = " <<q.size() << endl;
		cout<< q.front().top() << endl;
	}
}

//#include<list>
//namespace ListTest {
//	void test01() {
//		cout << "sss" << endl;
//	}
//}

void container_test() {
	ContainerTest::test01();
	ContainerTest::test02();
	ContainerTest::test02();
}

void string_test() {
	cout << "================  String  Test ================  " << endl;
	StringTest::test01();
	StringTest::test02();
	StringTest::test03();
	StringTest::test04();
	StringTest::test05();
	StringTest::test06();
	StringTest::test07();
	StringTest::test08();
	StringTest::test09();
	cout << "*================ ================ ================  " << endl;
}

void vector_test() {
	cout << "================  Vector Test ================  " << endl;
	VectorTest::test01();
	VectorTest::test02();
	VectorTest::test03();
	VectorTest::test04();
	VectorTest::test05();
	VectorTest::test06();
	VectorTest::test07();
	cout << "*================ ================ ================  " << endl;
}

void deque_test() {
	cout << "================  Deque  Test ================  " << endl;
	DequeTest::test01();
	DequeTest::test02();
	DequeTest::test03();
	cout << "*================ ================ ================  " << endl;
}

void stack_test() {
	cout << "================  Stack Test ================  " << endl;
	StackTest::test01();
	StackTest::test02();
	StackTest::test03();
	cout << "*================ ================ ================  " << endl;
}

void queue_test() {
	cout << "================  Queue Test ================  " << endl;
	QueueTest::test01();
	QueueTest::test02();
	cout << "*================ ================ ==========  " << endl;
}

//void list_test() {
//	cout << "================  List Test ================  " << endl;
//	//ListTest::test01();
//	//ListTest::test02();
//	cout << "*================ ================ ==========  " << endl;
//}
int main(void)
{
	//container_test();
	//string_test();
	//vector_test();
	//stack_test();
	//queue_test();
	//list_test();

	return 0;
}
