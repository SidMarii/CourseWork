#include "SomeObject.h"

std::string SomeObject::WriteAbout() {
	return ("\nИмя: " + name + "\nОписание: " + description);
}

char SomeObject::GetSymbol() {
	return symbol;
}

void Juicer::RemoveFruit(std::vector<Fruit>& v) {
	if (v.size() == 0) {
		return;
	}

	v.back().MakeSpace();
	v.pop_back();
}