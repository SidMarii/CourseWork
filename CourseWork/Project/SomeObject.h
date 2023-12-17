#include <iostream>
#include <vector>
#include "Fruit.h"
#ifndef SOMEOBJECT_H
#define SOMEOBJECT_H

class SomeObject {
	std::string name;
	std::string description;
	char symbol;

public:
	SomeObject(std::string n, std::string d, char s) {
		name = n;
		description = d;
		symbol = s;
	}

	SomeObject() {};
	std::string WriteAbout();
	char GetSymbol();
	virtual void RemoveFruit(std::vector<Fruit>&) = 0;
};

template<typename T>
class FruitBasket : public SomeObject {
	T fruit;

public:
	FruitBasket(std::string n, std::string d, char s) : SomeObject(n, d, s) {};	

	void FruitBasket<T>::RemoveFruit(std::vector<Fruit>& v) {
		if (Fruit::remainingWeight >= fruit.GetWeight()) {
			v.push_back(fruit);
			fruit.TakeUpSpace();
		}
	}
};

class Juicer : public SomeObject {
public:
	Juicer(std::string n, std::string d, char s) : SomeObject(n, d, s) {};
	void RemoveFruit(std::vector<Fruit>&);
};

#endif