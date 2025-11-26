#include <iostream>
#include <vector>
using namespace std;

class Employee
{
protected:
	string name;
	int age;
	string post;
public:
	Employee() {}
	Employee(string n, int a, string p)
	{
		name = n;
		age = a;
		post = p;
	}
	virtual double GetSalary()
	{
		return 0.0;
	}
	virtual void Print()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Post: " << post << endl;
		cout << "Salary: " << GetSalary() << endl;
	}
};

class Manager :public Employee
{
public:
	Manager() {}
	Manager(string n, int a, string p) : Employee(n, a, p) {}
	double GetSalary()
	{
		return 15000 + rand() % 52001;
	}
	void Print()
	{
		cout << "===================Manager===================" << endl;
		Employee::Print();
	}
};

class Developer :public Employee
{
public:
	Developer() {}
	Developer(string n, int a, string p) : Employee(n, a, p) {}
	double GetSalary()
	{
		return 10000 + rand() % 25001;
	}
	void Print()
	{
		cout << "==================Developer==================" << endl;
		Employee::Print();
	}
};

int main()
{
	srand(unsigned(time(0)));

	vector<Employee*> arr;
	arr.push_back(new Manager("Bogdan", 17, "Main manager"));
	arr.push_back(new Manager("Vova", 18, "Secondary manager"));
	arr.push_back(new Developer("Anton", 17, "Coder"));
	arr.push_back(new Developer("Logan", 89, "Designer"));

	for (auto ptr = arr.begin(); ptr != arr.end(); ptr++)
	{
		(*ptr)->Print();
	}
	cout << "=============================================" << endl;
}