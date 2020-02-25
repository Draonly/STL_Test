// Multimap Demo.cpp : 
//multimap 案例
//公司今天招聘了 5 个员工， 5 名员工进入公司之后，需要指派员工在那个部门工作
//人员信息有: 姓名 年龄 电话 工资等组成
//通过 Multimap 进行信息的插入 保存 显示
//分部门显示员工信息 显示全部员工信息
//

#include <iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

#define SALE_DEPATMENT 1 //销售部门
#define DEVELOP_DEPATMENT 2 //研发部门
#define FINACIAL_DEPATMENT 3 //财务部门

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

int main()
{
	vector<Worker> vWorker;
	multimap<int, Worker> WorkerGroup;
	//存放新员工信息
	Create_Worker(vWorker);
	WorkerByGroup(vWorker, WorkerGroup);
	//员工分组

	//打印
	PrintWorkerByGroup(WorkerGroup);
}

