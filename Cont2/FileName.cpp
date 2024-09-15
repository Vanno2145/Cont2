#include <iostream>
#include <string.h>

using namespace std;

class Herbivore {
public:
	virtual void Eat() = 0;
	virtual int Getweight() = 0;
	virtual string Getlive() = 0;
	virtual void Die() = 0;
};

class Bizon : public Herbivore {
	int weight;
	string live;
public:
	Bizon() {
		weight = 50;
	}
	Bizon(int w) {
		weight = w;
	}
	Bizon(int w, string l) :Bizon(w) {
		live = "alive";
	}

	int Getweight() override {
		return weight;
	}
	string Getlive() override {
		return live;
	}
	void Eat() {
		weight += 10;
	}
	void Die() {
		live = "died";
	}
	
};

class Wildebeest : public Herbivore {
	int weight;
	string live;
public:
	Wildebeest() {
		weight = 50;
	}
	Wildebeest(int w) {
		weight = w;
	}
	Wildebeest(int w, string l) :Wildebeest(w) {
		live = "alive";
	}

	int Getweight() override {
		return weight;
	}
	string Getlive() override {
		return live;
	}
	void Eat() override {
		weight += 10;
	}
	void Die() {
		live = "died";
	}

};

class Carnivor {
public:
	virtual void Eat(Herbivore * h) = 0;
	virtual int Getpower() = 0;
};

class Lion : public Carnivor {
	int power;
public:
	Lion() {
		power = 50;
	}
	Lion(int w) {
		power = w;
	}

	int Getpower() override {
		return power;
	}
	void Eat(Herbivore * h) override {
		if (h->Getlive() != "died") {
			if (h->Getweight() <= power) {
				h->Die();
				power += 10;
			}
			else{
				power -=10;
			}
		}
		else {
			cout << "This animal died, you cant bite it";
		}
	}
};

class Wolf : public Carnivor {
	int power;
public:
	Wolf() {
		power = 50;
	}
	Wolf(int w) {
		power = w;
	}
	int Getpower() override {
		return power;
	}
	void Eat(Herbivore* h) override {
		if (h->Getlive() != "died") {
			if (h->Getweight() <= power) {
				h->Die();
				power += 10;
			}
			else {
				power-=10;
			}
		}
		else {
			cout << "This animal died, you cant bite it";
		}
	}
};



class continent {
public:
	virtual void addanimals() = 0;
	virtual void Show() = 0;
	virtual void dellanimals() = 0;
};

class Africa : public continent {
	int animals;   
public:
	Africa() {
		animals = 0;
	}
	void addanimals() override{
		animals += 1;
	}
	void dellanimals() override{
		animals -= 1;
	}
	void Show() {
		cout << animals;
	}
};

class NorthAmerica : public continent {
	int animals;
public:
	NorthAmerica() {
		animals = 0;
	}
	void addanimals() override {
		animals += 1;
	}
	void dellanimals() override {
		animals -= 1;
	}
	void Show() {
		cout << animals;
	}
};


int main() {
	Bizon bizon;
	Lion lion;
	Wolf wolf;

	cout << "Power wolf: " << wolf.Getpower() << endl << "Weight bizon: " << bizon.Getweight() << endl;

	wolf.Eat(&bizon);
	bizon.Eat();

	cout << "Power wolf: " << wolf.Getpower() << endl << "Weight bizon: " << bizon.Getweight() << endl;

	Africa africa;
	africa.addanimals();
	africa.addanimals();
	africa.addanimals();

	africa.Show();
}