#include "Fruit.h"

char Fruit::GetSymbol() {
	return symbol;
};

void Fruit::TakeUpSpace() {
	remainingWeight -= weight;
}

void Fruit::MakeSpace() {
	remainingWeight += weight;
}

unsigned int Fruit::GetWeight() {
	return weight;
}

short Fruit::GetIndex() {
	return index;
}