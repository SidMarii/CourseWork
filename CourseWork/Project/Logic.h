#pragma once
#include <algorithm>
#include <iostream>
#include "windows.h"
#include "GetQuest.h"
#include "Setup.h"

void Logic(std::string& text, int& x, int& y, int& viewX, int& viewY, const int width, const int height, int& score, int& questCount, std::map<short, int>& quest, SomeObject* (*space)[9], std::vector<Fruit>& bag) {
	Fruit f;
	if (viewItem) {
		if (space[viewX][viewY] != nullptr) {
			if (text == "") {
				text = space[viewX][viewY]->WriteAbout();
			}

			else {
				text = "";
			}
		}
		viewItem = false;
	}

	else if (GetDone() && space[viewX][viewY] != nullptr && text != "") {
		if (bag.size()) {
			f = bag.back();
		}
		else if (space[viewX][viewY]->GetSymbol() == 'F' || space[viewX][viewY]->GetSymbol() == 'U') {
			ResetInput();
			return;
		}
		space[viewX][viewY]->RemoveFruit(bag);

		switch (space[viewX][viewY]->GetSymbol()) {
		case 'F':
			if (quest[f.GetIndex()] > 0) {
				quest[f.GetIndex()]--;
				score += f.GetWeight();
				if (quest[0] == quest[1] && quest[1] == quest[2] && quest[2] == quest[3] && quest[3] == 0) {
					score += 100;
					questCount++;
					delay_time -= 200;
					quest = GetQuest();
				}
			}

			else {
				quest[f.GetIndex()]++;
				score -= f.GetWeight() * 3;
				delay_time += 50;
			}
			break;

		case 'U':
			score -= f.GetWeight() * 10;
			delay_time += 100;
			break;

		default:
			std::sort(bag.begin(), bag.end(), [](Fruit f1, Fruit f2) {return f1.GetWeight() > f2.GetWeight();});
			break;
		}
	}

	else if (GetDir() && text == "") {
		switch (GetDir()) {
		case LEFT:
			if (x > 1 && space[x - 1][y] == nullptr) {
				x--;
			}
			viewX = x - 1;
			viewY = y;
			break;

		case RIGTH:
			if (x < width - 2 && space[x + 1][y] == nullptr) {
				x++;
			}
			viewX = x + 1;
			viewY = y;
			break;

		case UP:
			if (y > 1 && space[x][y - 1] == nullptr) {
				y--;
			}
			viewX = x;
			viewY = y - 1;
			break;

		case DOWN:
			if (y < height - 2 && space[x][y + 1] == nullptr) {
				y++;
			}
			viewX = x;
			viewY = y + 1;
			break;
		}
	}
	ResetInput();

	curr_time = clock();
	if (-delay_time > (double)(curr_time - start_time) / CLOCKS_PER_SEC * 5) {
		start_time = curr_time;
		delay_time = 0;
	}

	timer = (double)(curr_time - start_time) / CLOCKS_PER_SEC * 5 + delay_time;
	Sleep(timer);
	if (timer >= 500) {
		gameOver = true;
	}
}