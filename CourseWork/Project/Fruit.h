#ifndef FRUIT_H
#define FRUIT_H

class Fruit {
protected:
	short index;
	char symbol;
	unsigned int weight;
public:
	static int remainingWeight;
	Fruit() {};
	~Fruit() {};
	char GetSymbol();
	void TakeUpSpace();
	void MakeSpace();
	unsigned int GetWeight();
	short GetIndex();
};

class Apple : public Fruit {
public:
	Apple() : Fruit() {
		index = 0;
		symbol = 'A';
		weight = 2;
	}
	~Apple() {};
};

class Orange : public Fruit {
public:
	Orange() : Fruit() {
		index = 1;
		symbol = 'O';
		weight = 5;
	}
	~Orange() {};
};

class Banana : public Fruit {
public:
	Banana() : Fruit() {
		index = 2;
		symbol = 'B';
		weight = 3;
	}
	~Banana() {};
};

class Watermelon : public Fruit {
public:
	Watermelon() : Fruit() {
		index = 3;
		symbol = 'W';
		weight = 10;
	}
	~Watermelon() {};
};

#endif;