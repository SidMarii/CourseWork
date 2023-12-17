#include <fstream>
#include "WorkWithFiles.h"

void WriteFile(int questCount, int score, int x, int y, int viewX, int viewY, int delay_time, std::map<short, int> quest, std::vector<Fruit> bag) {
	system("cls");

	char input;
	std::cout << "Сохранить игру перед выходом?\n   Y - сохранить прогресс\n   N - оставить прежние данные о прогрессе\n>> ";
	do {
		std::cin >> input;
		switch (input) {

		case 'y':
		case 'Y':
		{
			break;
		}

		case 'n':
		case 'N':
		{
			return;
		}

		default: std::cout << "\nНеверное значение\nПовторите попытку...\n>> ";
		}
	} while (input != 'y' && input != 'n' && input != 'Y' && input != 'N');

	std::ofstream out("Status.txt");
	if (out.is_open())
	{
		out << questCount << std::endl << score << std::endl;
		out << x << " " << y << " " << viewX << " " << viewY << std::endl;
		out << delay_time << std::endl;
		for (int i = 0; i < 4; i++) {
			out << quest[i] << " ";
		}
		out << std::endl << Fruit::remainingWeight << std::endl;
		for (int i = 0; i < bag.size(); i++) {
			out << bag[i].GetSymbol() << " ";
		}
		out << '.';
	}
	out.close();
}

void ReadFile(int& questCount, int& score, int& x, int& y, int& viewX, int& viewY, int& delay_time, std::map<short, int>& quest, std::vector<Fruit>& bag) {
	system("cls");

	std::fstream in("Status.txt");
	if (in.peek() == EOF) {
		in.close();
		return;
	}

	char input;
	std::cout << "Восстановить сохраненные данные об игре?\n   Y - продолжить игру\n   N - начать заново\n>> ";
	do {
		std::cin >> input;
		switch (input) {

		case 'y':
		case 'Y':
		{
			break;
		}

		case 'n':
		case 'N':
		{
			in.close();
			std::fstream in("Status.txt", std::ios::out | std::ios::trunc);
			in.close();
			return;
		}

		default: std::cout << "\nНеверное значение\nПовторите попытку...\n>> ";
		}
	} while (input != 'y' && input != 'n' && input != 'Y' && input != 'N');

	char fruitSymbol;
	if (in.is_open())
	{
		in >> questCount >> score;
		in >> x >> y >> viewX >> viewY;
		in >> delay_time;
		for (int i = 0; i < 4; i++) {
			in >> quest[i];
		}
		in >> Fruit::remainingWeight;
		while (!in.eof()) {
			in >> fruitSymbol;

			switch (fruitSymbol) {
			case 'A':
				bag.push_back(Apple());
				break;

			case 'O':
				bag.push_back(Orange());
				break;

			case 'B':
				bag.push_back(Banana());
				break;

			case 'W':
				bag.push_back(Watermelon());
				break;

			default:
				fruitSymbol = 0;
				break;
			}
		}
	}
	in.close();
}