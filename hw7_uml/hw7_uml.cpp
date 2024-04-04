// hw7_uml.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
static int sum = 0;

class Component abstract //общий интерфейс
{
protected:
	string name;
	int price;

public:
	Component(string name, int price)
	{
		this->name = name;
		this->price = price;
	}
	Component(string name)
	{
		this->name = name;
	}

	

	int getPrice() {
		return price;
	}
	virtual  void Add(Component* c) abstract;
	virtual  void Remove(Component* c) abstract;
	virtual  void Display(int depth) abstract;
};


class Composite : public Component //коробка
{
	vector<Component*> components;

public:
	Composite(string name, int price) :Component(name, price) {	}
	Composite(string name) :Component(name) {	}

	void Add(Component* component) override
	{
		components.push_back(component);
	}
	void Remove(Component* component) override
	{
		auto iter = find(components.begin(), components.end(), component);
		components.erase(iter);
	}

	
	void Display(int depth) override
	{
		string s(depth, '-');
		cout << s + name << " " << price << endl;

		for (Component* component : components)
		{
			component->Display(depth + 2);
			sum += component->getPrice();
		}
	}

};



class Leaf : public Component //конкретный продукт
{
public:
	Leaf(string name, int price) : Component(name, price) {	}
	Leaf(string name) : Component(name) {	}

	void Add(Component* c) override
	{
		cout << "Cannot add to file\n";
	}
	void Remove(Component* c) override
	{
		cout << "Cannot remove from file\n";
	}
	void Display(int depth) override
	{
		string s(depth, '-');
		cout << s + name << " " << price << endl;
	}
};




int main()
{


	Component* reception = new Composite("Reception");

	Component* magazineTable = new Composite("Magazine table", 300);
	reception->Add(magazineTable);
	magazineTable->Add(new Leaf("gaming journals", 30));


	reception->Add(new Leaf("Soft sofa", 100));

	Component* secretaryTable = new Composite("Secretary table", 150);
	Component* computer = new Composite("computer", 150);
	secretaryTable->Add(computer);
	computer->Add(new Leaf("big SSD", 600));
	secretaryTable->Add(new Leaf("office instruments", 70));

	reception->Add(new Leaf("water", 80));
	reception->Display(1);

	cout << endl;

	Component* room1 = new Composite("Room 1");
	room1->Add(new Leaf("10 tables", 40));
	room1->Add(new Leaf("desk", 50));
	Component* teachersTable = new Composite("Teachers table", 200);
	room1->Add(teachersTable);
	teachersTable->Add(new Leaf("computer", 300));
	room1->Add(new Leaf("posters", 80));
	room1->Display(1);
	cout << endl;

	Component* room2 = new Composite("Room 2");
	Component* tables = new Composite("Tables", 40);
	room2->Add(tables);
	tables->Add(new Leaf("black tables", 50));
	tables->Add(new Leaf("tables in a circle", 0));
	room2->Add(new Leaf("desk", 120));
	room2->Add(new Leaf("soft sofa", 49));
	room2->Display(1);
	cout << endl;

	Component* computerRoom = new Composite("Computer room");
	Component* computerTables = new Composite("Computer tables", 50);
	computerRoom->Add(computerTables);
	computerTables->Add(new Leaf("a computer on every table", 456));
	computerTables->Add(new Leaf("processor 2.2GGrs", 435));
	computerTables->Add(new Leaf("Winchest 80GB", 657));
	computerTables->Add(new Leaf("RAM 1024MB", 767));
	computerRoom->Add(new Leaf("plug near every table", 50));
	Component* desk = new Composite("desk", 50);
	desk->Add(new Leaf("color markers", 45));
	computerRoom->Add(desk);
	computerRoom->Display(1);
	cout << endl;

	Component* dinningRoom = new Composite("Dinning room");
	dinningRoom->Add(new Leaf("Coffee Machine", 700));
	Component* table = new Composite("table", 30);
	dinningRoom->Add(table);
	table->Add(new Leaf("four chairs", 100));
	dinningRoom->Add(new Leaf("fridge", 500));
	dinningRoom->Add(new Leaf("wash basin", 150));
	dinningRoom->Display(1);
	cout << endl;
	cout << "total sum: " << sum << endl;
}

