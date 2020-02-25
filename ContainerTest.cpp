#include <iostream>
#include<vector> //动态数组 可变数组
#include<algorithm> //算法
using namespace std;

//面向行读取
#if 0
cin.get(buf, 256); //不会读最后换行
cin.getline() //最后换行丢弃
#endif 

/*STL Hello World测试
Vector使用：防节本数据类型及自定义数据类型、指针等；
Vector中元素遍历：使用迭代器和for_each两种方法
*/
namespace ContainerTest
{
	void PrintVector(int v) {
		cout << v << " ";
	}

	//STL基本语法
	void test01() {
		//定义一个容器，并且制指定这个容器存放的元素类型是Int
		vector<int> v;
		v.push_back(10);
		v.push_back(20);
		v.push_back(30);
		v.push_back(40);

		//通过STL提供的for_each算法
		//容器提供的迭代器
		//vector<int>::iterator 迭代器类型
		vector<int>::iterator pBegin = v.begin();
		vector<int>::iterator pEnd = v.end();

		//容器中可能存放基础的数据类型，也可能存放自定义数据类型
		for_each(pBegin, pEnd, PrintVector);
	}

	//容器也可以存放自定义数据类型
	class Person {
	public:
		Person(int age, int id) :age(age), id(id) {}
	public:
		int age;
		int id;
	};

	void test02() {

		//创建容器，并且指定容器的元素类型是Person
		vector<Person> v;
		Person p1(10, 20), p2(30, 40), p3(50, 60);
		v.push_back(p1);
		v.push_back(p2);
		v.push_back(p3);

		//遍历
		for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
			cout << (*it).age << " " << (*it).id << endl;
		}
	}

	//容器存放Perosn类型指针，并且 迭代器方式打印
	void test03()
	{
		//创建容器，并且指定容器的元素类型是Person*
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

/*string测试
string的初始化，取值，拼接，查找，删除，替换，比较等常用操作
*/
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
#include<string>
namespace StringTest {
	using namespace std;

	//初始化
	void test01() {

		string s1; //调用无参构造
		string s2(10, 'a');
		string s3("abcdefg");
		string s4(s3); //拷贝构造

		cout << "*********  string init  *********";
		cout << s1 << endl;
		cout << s2 << endl;
		cout << s3 << endl;
		cout << s4 << endl;
		cout << endl;
}

	//赋值操作
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

		//成员方法assign
		s1.assign("jkl");
		cout << s1 << endl;
	}

	//取值操作
	void test03() {

		cout << endl << "*********  string []  *********" << endl;
		string s1 = "abcdefg";

		//重载[]操作符
		//如果访问越界就报错了
		for (int i = 0; i < s1.size(); i++) {
			cout << s1[i] << " ";
		}
		cout << endl;

		//at成员函数
		//如果访问越界，会抛出异常
		for (int i = 0; i < s1.size(); i++) {
			cout << s1.at(i) << " ";
		}
		cout << endl;

		//区别：[]方式 如果访问越界，直接挂了
		//at方式 访问越界 抛异常out_of_range

		try {
			//cout << s1[100] << endl;
			cout << s1.at(100) << endl;
		}
		//能够捕获任何异常的 catch 语句
		catch (...) {
			cout << "越界!" << endl;
		}

	}

	//拼接操作
	void test04() {
		string s = "abcd";
		string s2 = "1111";
		s += "abcd";
		s += s2;
		cout << endl << "*********  string append  *********" << endl;
		cout << "s = " << s << endl;

		//append 会加到尾部
		string s3 = "2222";
		s2.append(s3);
		cout << "s2 = " << s2 << endl;


		string s4 = s2 + s3;
		cout << "s4 = " << s4 << endl;
	}

	//查找操作
	void test05() {

		string s = "abcdefghjfgkl";
		//查找第一次出现的位置
		int pos = s.find("fg");
		cout << endl << "*********  string find  *********" << endl;
		cout << "pos:" << pos << endl;

		//查找最后一次出现的位置
		pos = s.rfind("fg");
		cout << "pos:" << pos << endl;

	}

	//string替换
	void test06() {
		string s = "abcdefg";
		s.replace(3, 2, "111");
		cout << endl << "*********  string replace  *********" << endl;
		cout << "string replace test: " << s << endl;
	}

	//string比较
	void test07() {

		string s1 = "abcd";
		string s2 = "abce";
		cout << endl << "*********  string compare  *********" << endl;
		if (s1.compare(s2) == 0) {
			cout << "字符串相等!" << endl;
		}
		else {
			cout << "字符串不相等!" << endl;
		}

	}

	//子串操作
	void test08() {

		string s = "abcdefg";
		string mysubstr = s.substr(1, 7);
		cout << endl << "*********  string substr  *********" << endl;
		cout << mysubstr << endl;
	}

	//插入和删除
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


/*Vector测试
Vector的初始化，赋值，存取数据,插入和删除，等常用操作
*/
#include<vector>
namespace VectorTest {
	

	void printVector(vector<int>& v) {
		for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}

	//初始化
	void test01() {

		vector<int> vl;//默认构造

		//使用数组初始化vector
		int arr[] = { 10, 20, 30, 40 };
		vector<int> v2(arr, arr + sizeof(arr) / sizeof(int));
		//
		vector<int> v3(v2.begin(), v2.end());
		vector<int> v4(v3);    //拷贝构造

		printVector(v2);
		printVector(v3);
		printVector(v4);
	}

	//常用赋值操作
	void test02() {


		int arr[] = { 10, 20, 30, 40 };
		vector<int> vl1(arr, arr + sizeof(arr) / sizeof(int));//默认构造

		//成员方法，使用迭代器
		vector<int> v2;
		v2.assign(vl1.begin(), vl1.end());

		//重载=
		vector<int> v3;
		v3 = v2;

		int arr1[] = { 100, 200, 300, 400 };
		vector<int> v4(arr1, arr1 + sizeof(arr) / sizeof(int));//默认构造

		cout << "----------Vector 赋值--------" << endl;
		printVector(vl1);
		printVector(v2);
		printVector(v3);
		printVector(v4);

		cout << "------------------" << endl;

		//交换：实际是交换的各自的指向内存空间的指针
		v4.swap(vl1);
		printVector(vl1);
		printVector(v2);
		printVector(v3);
		printVector(v4);

	}

	//大小操作
	void test03() {

		int arr1[] = { 100, 200, 300, 400 };
		vector<int> v4(arr1, arr1 + sizeof(arr1) / sizeof(int));//默认构造

		cout << "size：" << v4.size() << endl;
		if (v4.empty() == true) {
			cout << "空！" << endl;
		}
		else {
			cout << "不空！" << endl;
		}

		printVector(v4);
		//元素个数改为2，多余的删除
		v4.resize(2);
		printVector(v4);
		//将元素个数改为8，后面用默认0填充
		v4.resize(6);
		printVector(v4);
		//将元素个数改为8，后面用1填充
		v4.resize(8, 1);
		printVector(v4);

		for (int i = 0; i < 10000; i++) {
			v4.push_back(i);
		}
		cout << "size：" << v4.size() << endl;  //元素的个数 
		cout << "容量:" << v4.capacity() << endl; //容量 


	}

	//vector存取数据
	void test04() {

		int arr1[] = { 100, 200, 300, 400 };
		vector<int> v4(arr1, arr1 + sizeof(arr1) / sizeof(int));//默认构造

		//使用下标取数据
		for (int i = 0; i < v4.size(); i++) {
			cout << v4[i] << " ";
		}
		cout << endl;


		//使用at
		for (int i = 0; i < v4.size(); i++) {
			cout << v4.at(i) << " ";
		}
		cout << endl;


		//区别: at抛异常 []不抛异常
		try
		{
			cout << v4.at(1000) << " ";
		}
		catch (...)
		{
			cout << "Out of range..." << endl;
		}

		//front返回元素的第一个元素，back返回最后一个元素
		cout << "front:" << v4.front() << endl;
		cout << "back:" << v4.back() << endl;
	}

	//插入和删除
	void test05() {

		vector<int> v;
		v.push_back(10);
		v.push_back(20);

		v.insert(v.begin(), 30); //头插入 30
		v.insert(v.end(), 40);  //末尾插入 40

		v.insert(v.begin() + 2, 100); //vector支持随机访问

		//支持数组下标的，一般都支持随机访问
		//迭代器可以直接+2 +3 -2 -5操作
		printVector(v);

		//删除操作
		v.erase(v.begin());  //删除第一个元素
		printVector(v);
		v.erase(v.begin() + 1, v.end());
		printVector(v);
		v.clear();   //清空
		cout << "size:" << v.size() << endl;
	}

	//巧用swap缩减空间
	void test06() {

		//vector添加元素 他会自动增长 你删除元素时候，会自动减少吗？

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

		//收缩空间
		//这里使用V初始化一个匿名对象，并会根据V中元素个数初始化话自己，然后与v交换
		vector<int>(v).swap(v);

		cout << "--------------" << endl;
		cout << "size:" << v.size() << endl;
		cout << "capacity:" << v.capacity() << endl;
	}

	//reserve 预留空间 resize区别
	void test07() {
		int num = 0;
		int* address = NULL;

		vector<int> v;
		v.reserve(100000);
		for (int i = 0; i < 100000; i++) {
			v.push_back(i);
			//统计一下，进行内存与释放的次数
			if (address != &(v[0])) {
				address = &(v[0]);
				num++;
			}
		}

		cout << "num:" << num << endl;

		//如果你知道容器大概要存储的元素个数，那么你可以用reserve预留空间
		//减少内存申请释放的次数；

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

	//deque初始化
	void test01() {

		deque<int> d1;
		deque<int> d2(10, 5);  //10个5
		deque<int> d3(d2.begin(), d2.end());
		deque<int> d4(d3);  //拷贝构造


		//打印d4
		PrintDeque(d4);

	}

	//赋值 大小操作
	void test02() {

		deque<int> d1;
		deque<int> d2;
		deque<int> d3;
		d1.assign(10, 5);  //指定N个元素
		d2.assign(d1.begin(), d1.end()); //迭代器指定区间赋值
		d3 = d2; //等号赋值

		d1.swap(d2); //交换两个空间元素

		if (d1.empty()) {
			cout << "空!" << endl;
		}
		else {
			cout << "size:" << d1.size() << endl;
		}

		d1.resize(5); //10个元素，后五个元素扔掉
		cout << "size:" << d1.size() << endl;

	}

	//deque容器插入和删除
	void test03() {

		deque<int> d1;
		d1.push_back(100);
		d1.push_front(200);
		d1.push_back(300);
		d1.push_back(400);
		d1.push_front(500);

		//500 200 100 300 400
		PrintDeque(d1);

		int val = d1.front(); //拿到被删除的数据
		d1.pop_front(); //删除
		PrintDeque(d1);
		val = d1.back();
		d1.pop_back(); //删除最后一个元素

	}

}

#include<stack>
namespace StackTest {
	void test01() {


		//初始化
		stack<int> s1;
		stack<int> s2(s1);

		//stack操作
		s1.push(10);
		s1.push(20);
		s1.push(30);
		s1.push(100);
		cout << "栈顶元素:" << s1.top() << endl;
		s1.pop(); //删除栈顶元素

		//打印栈容器的数据
		while (!s1.empty()) {
			cout << s1.top() << " " <<endl;
			s1.pop();
		}

		cout << "size：" << s1.size() << endl;
		//作业2 栈容器存放对象

	}

	//作业1 栈容器存放对象指针
	void test02() {
		ContainerTest::Person p1(20, 30), p2(30, 40);
		stack<ContainerTest::Person*> s;
		s.push(&p1);
		s.push(&p2);

		cout << "stack point test: " << (*(s.top())).age << endl;
		s.pop();
		cout << "stack point test: " << (*(s.top())).age << endl;
		
	}

	//作业2 栈容器存放对象
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
		queue<int> q; //创建队列
		q.push(10);
		q.push(20);
		q.push(30);
		q.push(40);

		cout << "队尾：" << q.back() << endl;

		//输出顺序? 10 20 30 40
		while (q.size() > 0) {

			cout << q.front() << " "; //输出队头元素
			q.pop(); //删除队头

		}
		cout << endl;
		//作业1 queue容器存放对象指针
	}

	//queue容器存放stack容器
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

		cout << "queue容器存放stack容器 test..q.size = " <<q.size() << endl;
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
