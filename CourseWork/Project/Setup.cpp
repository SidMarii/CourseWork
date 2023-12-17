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
	space[2][1] = new FruitBasket<Apple>("Корзинка с яблоками", "Нажимте F, чтобы взять яблоко из корзины", 'A');
	space[4][1] = new FruitBasket<Orange>("Корзинка с апельсинами", "Нажимте F, чтобы взять апельсин из корзины", 'O');
	space[6][1] = new FruitBasket<Banana>("Корзинка с бананами", "Нажимте F, чтобы взять банан из корзины", 'B');
	space[8][1] = new FruitBasket<Watermelon>("Мешок арбузов", "Нажимте F, чтобы взять арбуз\n\nАрбуз займет много места в Вашем инвентаре!", 'W');
	space[5][7] = new Juicer("Соковыжималка", "Нажимте F, чтобы положить фрукт в соковыжималку\n\nВы теряете баллы и получаете дополнительный квест за свои ошибки!", 'F');
	space[8][6] = new Juicer("Урна", "Нажимте F, чтобы выбросить фрукт в урну\n\nВы теряете много баллов за каждый выброшенный фрукт!", 'U');
}