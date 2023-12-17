#include "GetQuest.h"

std::map<short, int> GetQuest() {
	std::map<short, int> quest;
	srand(time(0));
	quest[0] = quest[1] = quest[2] = quest[3] = 0;
	for (int i = 0; i < 3; i++) {
		quest[rand() % 4]++;
	}
	return quest;
}