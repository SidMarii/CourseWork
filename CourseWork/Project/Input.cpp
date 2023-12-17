#include <conio.h>
#include "Input.h"

void Input(bool& viewItem, bool& gameOver) {
	switch (_getch()) {
	case 'a':
	case 'A':
		dir = LEFT;
		break;

	case 'd':
	case 'D':
		dir = RIGTH;
		break;

	case 'w':
	case 'W':
		dir = UP;
		break;

	case 's':
	case 'S':
		dir = DOWN;
		break;

	case 13:
		viewItem = true;
		break;

	case 'x':
	case 'X':
		gameOver = true;
		break;

	case 'f':
	case 'F':
		done = DONE;
		break;
	}
}

void ResetInput() {
	dir = STOP;
	done = NONE;
}

eDirection GetDir() {
	return dir;
}

eDone GetDone() {
	return done;
}