/* STL_Algorithm_Test.cpp : 
   STL常用算法测试
   包括：常用查找、
*/

#include <iostream>
#include<algorithm>
#include<vector>
#include<functional>

using namespace std;

namespace AlgorithmTest {
	//transform 将一个容器的元素 搬运 到另一个容器中
	struct MyPlus {
		int operator()(int val) {
			return val + 100;
		}
	};

	void MyPrint(int val) {
		cout << val << " ";
	}

	void test01() {

		vector<int> v1;
		vector<int> v2;


		for (int i = 0; i < 10; i++) {
			v1.push_back(i);
		}

		v2.resize(v1.size()); //开辟空间
		cout << "tranform Test..." << endl;
		////transform(数据起始,结束,写入目标的起始,执行的操作)
		//遍历一个容器里面元素 然后执行一个操作
		transform(v1.begin(), v1.end(), v2.begin(), MyPlus()); 
		for_each(v2.begin(), v2.end(), MyPrint);
		cout << endl;
	}

	class Person {
	public:
		Person(int age, int id) :age(age), id(id) {}
		bool operator==(const Person& p) const {
			return p.id == this->id && p.age == this->age;
		}
	public:
		int id;
		int age;
	};

	void test03() {

		vector<Person> v1;

		Person p1(10, 20), p2(20, 30);

		v1.push_back(p1);
		v1.push_back(p2);

		vector<Person>::iterator ret = find(v1.begin(), v1.end(), p1);
		if (ret == v1.end()) {
			cout << "Person 么有找到!" <<  (*ret).id << endl;
		}
		else {
			cout << "Person 找到了: " << (*ret).id << endl;
		}

	}

	//binary_search 二分查找法
	bool MySearch(int val) {
		return val > 5;
	}
	bool MySearch2(int val) {
		return val > 5;
	}

	bool MySearch01(int val, int v) {
		return val > v;
	}
	void test04() {

		vector<int> v1;
		for (int i = 0; i < 10; i++) {
			v1.push_back(i);
		}
		v1.push_back(9);

		bool ret = binary_search(v1.begin(), v1.end(), 5);
		if (ret) {
			cout << "binary_search 找到！" << endl;
		}
		else {
			cout << "binary_search 没有找到!" << endl;
		}

		/*adjacent_find 查找相邻重复元素
		 @param beg 容器开始迭代器
		 @param end 容器结束迭代器
		 @param  callback 回调函数或则谓词（返回bool型的函数对象）
		 @return 返回相邻元素的第一个位置迭代器
		*/
		vector<int>::iterator it = adjacent_find(v1.begin(), v1.end());
		if (it != v1.end()) {
			cout << "adjacent_find 找到相邻重复元素:" << *it << endl;
		}
		else {
			cout << "adjacent_find 没有找打相邻重复元素" << endl;
		}

		//find_f 会根据我们的条件(函数) ，返回第一个满足条件的元素的迭代器
		//it = find_if(v1.begin(), v1.end(), not1(bind2nd(ptr_fun(MySearch01),4)));
		it = find_if(v1.begin(), v1.end(), MySearch);
		if (it != v1.end()) {
			cout << "find_if 找到:" << *it << endl;
		}
		else {
			cout << "find_if 没有找到" << endl;
		}

		//count count_if
		int num = count(v1.begin(), v1.end(), 9);
		cout << "9出现的次数:" << num << endl;
		num = count_if(v1.begin(), v1.end(), MySearch2);
		cout << "大于5的个数：" << num << endl;

	}
}



int main()
{
	//AlgorithmTest::test01();
	//AlgorithmTest::test03();
	AlgorithmTest::test04();
    //std::cout << "Hello World!\n";
}

