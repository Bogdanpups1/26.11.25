#include <iostream>
#include <vector>
using namespace std;

class Employer
{
protected:
	string name;
	int age;
	string post;
public:
	Employer() {}
	Employer(string n, int a, string p)
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

class Manager :public Employer
{
public:
	Manager() {}
	Manager(string n, int a, string p) : Employer(n, a, p) {}
	double GetSalary()
	{
		return 15000 + rand() % 52001;
	}
	void Print()
	{
		cout << "===================Manager===================" << endl;
		Employer::Print();
	}
};

class Developer :public Employer
{
public:
	Developer() {}
	Developer(string n, int a, string p) : Employer(n, a, p) {}
	double GetSalary()
	{
		return 10000 + rand() % 25001;
	}
	void Print()
	{
		cout << "==================Developer==================" << endl;
		Employer::Print();
	}
};

int main()
{
	srand(unsigned(time(0)));

	vector<Employer*> arr;
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
