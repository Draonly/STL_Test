/* STL_Algorithm_Test.cpp : 
   1.AlgorithmTest: STL常用算法测试 包括：常用查找、计数等；
   2.MultimapDemoTest：multimap 案例-员工分组；
   3.DequeDemoTest： deque案例-选手打分，sort排序
*/

#include <iostream>
#include<algorithm>
#include<vector>
#include<functional>

using namespace std;

//transform，find,binary_search,adjacent_find,find_if,count,count_if使用
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


//multimap 案例
//公司今天招聘了 5 个员工， 5 名员工进入公司之后，需要指派员工在那个部门工作
//人员信息有: 姓名 年龄 电话 工资等组成
//通过 Multimap 进行信息的插入 保存 显示
//分部门显示员工信息 显示全部员工信息
#include <map>
#define SALE_DEPATMENT 1 //销售部门
#define DEVELOP_DEPATMENT 2 //研发部门
#define FINACIAL_DEPATMENT 3 //财务部门
namespace MultimapDemoTest {
	class Worker
	{
	public:
		Worker() { };
		Worker(string name, string tele, int age, int salary)
			:mName(name), mTele(tele), mAge(age), mSalary(salary) {}
	public:
		string mName;
		string mTele;
		int mAge;
		int mSalary;
	};

	//存放新员工信息
	void Create_Worker(vector<Worker>& worker) {
		string sName = "ABCDE_";
		for (int i = 0; i < 5; i++) {
			Worker w;
			w.mName = "员工";
			w.mName += sName[i];
			w.mAge = rand() % 10 + 20;//20-30
			w.mSalary = rand() % 5000 + 10000;
			w.mTele = "010-88888888";

			worker.push_back(w);
		}
	}


	///员工分组,把员工随机分配不同部门
	void WorkerByGroup(vector<Worker>& worker, multimap<int, Worker>& WorkerGroup) {
		for (auto it = worker.begin(); it != worker.end(); it++)
		{
			int department_No = rand() % 3 + 1;
			switch (department_No)
			{
			case(SALE_DEPATMENT):
				WorkerGroup.insert(make_pair(SALE_DEPATMENT, *it));
				break;
			case(DEVELOP_DEPATMENT):
				WorkerGroup.insert(make_pair(DEVELOP_DEPATMENT, *it));
				break;
			case(FINACIAL_DEPATMENT):
				WorkerGroup.insert(make_pair(FINACIAL_DEPATMENT, *it));
				break;
			default:
				break;
			}
		}
	}

	void ShowWorkerGroup(multimap<int, Worker>& WorkerGroup, int department_id) {
		multimap<int, Worker>::iterator pos = WorkerGroup.find(department_id);
		//当前部门员工总人数
		int count_num = WorkerGroup.count(department_id);
		int num = 0;
		for (auto it = pos; it != WorkerGroup.end() && num < count_num; it++, num++) {
			cout << "id: " << it->first << " Name: " << it->second.mName
				<< " Age: " << it->second.mAge << " Tele: " << it->second.mTele
				<< " Salary: " << it->second.mSalary << endl;
		}
	}

	//分部门显示
	void PrintWorkerByGroup(multimap<int, Worker>& WorkerGroup) {

		//1 销售部门
		cout << "打印销售部门人员信息：" << endl;
		ShowWorkerGroup(WorkerGroup, SALE_DEPATMENT);
		//2 研发部
		cout << "打印研发部人员信息：" << endl;
		ShowWorkerGroup(WorkerGroup, DEVELOP_DEPATMENT);
		//3 财务部
		cout << "打印财务部人员信息：" << endl;
		ShowWorkerGroup(WorkerGroup, FINACIAL_DEPATMENT);
	}

}

/*	
 评委打分案例(sort 算法排序)
 创建 5 个选手(姓名，得分) ， 10 个评委对 5 个选手进行打分
 得分规则：去除最高分，去除最低分，取出平均分
 按得分对 5 名选手进行排名
*/
#include<deque>
#include<time.h>
namespace DequeDemoTest{
//选手类
	class Player {
	public:
		Player() {}
		Player(string name, int score) :mName(name), mScore(score) {}
	public:
		string mName;
		int mScore;
	};

	//创建选手
	void Create_Player(vector<Player>& v) {

		string nameSeed = "ABCDE";
		for (int i = 0; i < 5; i++) {

			Player p;
			p.mName = "选手";
			p.mName += nameSeed[i];
			p.mScore = 0;

			v.push_back(p);
		}

	}

	void PrintScore(int val) {
		cout << val << " ";
	}

	//打分
	void Set_Score(vector<Player>& v) {
		//根据系统提供的种子值，从而可以使得每次调用rand函数生成的伪随机数序列不同
		srand(time(NULL));

		for (vector<Player>::iterator it = v.begin(); it != v.end(); it++) {

			//当前学生进行打分
			deque<int> dScore;
			for (int i = 0; i < 10; i++) {
				int score = rand() % 41 + 60;
				cout << score << " ";
				dScore.push_back(score);
			}
			cout << endl;

			//对分数排序 默认从小到大
			sort(dScore.begin(), dScore.end());
			//for_each(dScore.begin(), dScore.end(), PrintScore);
			//cout << endl;

			//去除最高分 去除最低分
			dScore.pop_front();
			dScore.pop_back();

			//求平均分
			int totalScore = 0;
			for (deque<int>::iterator dit = dScore.begin(); dit != dScore.end(); dit++) {
				totalScore += (*dit);
			}

			int avgScore = totalScore / dScore.size();
			//保存分数
			(*it).mScore = avgScore;
		}
	}

	//排序规则
	bool mycompare(Player& p1, Player& p2) {
		return p1.mScore > p2.mScore;
	}
	void print_Score(Player& p)
	{
		cout << "Player: " << p.mName << " Score:" << p.mScore << endl;
	}

	//根据选手分数排名 sort默认从小到大 希望从大到小
	void Print_Rank(vector<Player>& v) {

		//排序
		sort(v.begin(), v.end(), mycompare);
		//打印-- 通过for_each打印
		for_each(v.begin(), v.end(), print_Score);

		//通过迭代器打印
		/*
		for (vector<Player>::iterator it = v.begin(); it != v.end(); it++) {

			cout << "姓名:" << (*it).mName << "得分:" << (*it).mScore << endl;

		}*/
	}
}

void algorithm_test() {
	cout << "================ algorithm_test   ================  " << endl;
	AlgorithmTest::test01();
    AlgorithmTest::test03();
	AlgorithmTest::test04();
	cout << "================ =============== ================  " << endl << endl;
}
//multimap 案例--员工分组
void multimap_demo_test() {
	cout << "================  multimap_demo Test ================  " << endl;
	vector<MultimapDemoTest::Worker> vWorker;
	multimap<int, MultimapDemoTest::Worker> WorkerGroup;
	//存放新员工信息
	MultimapDemoTest::Create_Worker(vWorker);
	//员工分组
	MultimapDemoTest::WorkerByGroup(vWorker, WorkerGroup);
	//打印
	MultimapDemoTest::PrintWorkerByGroup(WorkerGroup);
	cout << "================ =============== ================  " << endl << endl;
}

//deque案例-选手打分，sort排序
void deque_demo_test() {
	cout << "================  deque_demo Test ================  " << endl;
	//定义vector容器，保存选手信息
	vector<DequeDemoTest::Player> vPlist;
	DequeDemoTest::Create_Player(vPlist);
	DequeDemoTest::Set_Score(vPlist);
	DequeDemoTest::Print_Rank(vPlist);
	cout << "================ =============== ================  " << endl << endl;

}

int main()
{
	algorithm_test();
	multimap_demo_test();
	deque_demo_test();
}

