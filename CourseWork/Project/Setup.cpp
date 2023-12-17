#include "Setup.h"

void Setup(int& x, int& y, int& viewX, int& viewY, SomeObject* (*space)[9]) {
	start_time = clock();
	delay_time = 0;
	timer = 0;
	gameOver = false;
	ResetInput();
	x = 5;
	y = 4;
	viewX = x;
	viewY = y;
	space[2][1] = new FruitBasket<Apple>("�������� � ��������", "������� F, ����� ����� ������ �� �������", 'A');
	space[4][1] = new FruitBasket<Orange>("�������� � �����������", "������� F, ����� ����� �������� �� �������", 'O');
	space[6][1] = new FruitBasket<Banana>("�������� � ��������", "������� F, ����� ����� ����� �� �������", 'B');
	space[8][1] = new FruitBasket<Watermelon>("����� �������", "������� F, ����� ����� �����\n\n����� ������ ����� ����� � ����� ���������!", 'W');
	space[5][7] = new Juicer("�������������", "������� F, ����� �������� ����� � �������������\n\n�� ������� ����� � ��������� �������������� ����� �� ���� ������!", 'F');
	space[8][6] = new Juicer("����", "������� F, ����� ��������� ����� � ����\n\n�� ������� ����� ������ �� ������ ����������� �����!", 'U');
}