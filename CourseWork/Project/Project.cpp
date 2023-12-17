#include <conio.h>
#include "Draw.h"
#include "StartMessage.h"
#include "WorkWithFiles.h"
#include "Logic.h"

int Fruit::remainingWeight = 15;
int main() {
	setlocale(0, "");
	StartMessage();
	Setup(x, y, viewX, viewY, space);
	quest = GetQuest();
	ReadFile(questCount, score, x, y, viewX, viewY, delay_time, quest, bag);
	Draw(x, y, questCount, score, width, height, timer, text, bag, quest, space);
	while (!gameOver) {
		if (_kbhit()) {
			Input(viewItem, gameOver);
			Logic(text,  x,  y, viewX,  viewY,  width,  height,  score,  questCount, quest,  space, bag);
			Draw(x, y, questCount, score, width, height, timer, text, bag, quest, space);
		}
	}
	WriteFile(questCount, score, x, y, viewX, viewY, delay_time, quest, bag);
	system("cls");
}