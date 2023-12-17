#include <algorithm>
#include "Draw.h"
#include <iomanip>

void Draw(int x, int y, int questCount, int score, const int width, const int height, double timer, std::string text, std::vector<Fruit> bag, std::map<short, int> quest, SomeObject* (*space)[9]) {
	system("cls");

	for (int i = 0; i < width; i++) {
		std::cout << "#";
	}
	std::cout << std::endl;

	for (int i = 1; i < height - 1; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 1) {
				std::cout << "#";
			}

			else if (i == y && j == x) {
				std::cout << "0";
			}

			else if (space[j][i] != nullptr) {
				std::cout << space[j][i]->GetSymbol();
			}

			else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < width; i++) {
		std::cout << "#";
	}
	std::cout << std::endl << std::endl << "КВЕСТ" << std::endl;
	std::cout << std::setw(3) << std::left << "A" << std::setw(3) << std::left << quest[0] << std::endl;
	std::cout << std::setw(3) << std::left << "O" << std::setw(3) << std::left << quest[1] << std::endl;
	std::cout << std::setw(3) << std::left << "B" << std::setw(3) << std::left << quest[2] << std::endl;
	std::cout << std::setw(3) << std::left << "W" << std::setw(3) << std::left << quest[3] << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(17) << std::left << "Инвентарь";
	std::for_each(bag.begin(), bag.end(), [](Fruit f) { std::cout << f.GetSymbol(); });
	std::cout << std::endl;
	std::cout << std::setw(17) << std::left << "Доступный вес" << std::setw(3) << std::left << Fruit::remainingWeight << std::endl;
	std::cout << std::setw(17) << std::left << "Квесты" << std::setw(3) << std::left << questCount << std::endl;
	std::cout << std::setw(17) << std::left << "Баллы" << std::setw(3) << std::left << score << std::endl;
	std::cout << std::setw(17) << std::left << "Штраф" << std::setw(3) << std::left << timer << std::endl;
	std::cout << std::setw(17) << std::left << "___________________________________" << std::endl << text;
}