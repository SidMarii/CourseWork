#pragma once
#include <iostream>
#include "Fruit.h"
#include <map>
#include <vector>

void WriteFile(int, int, int, int, int, int, int, std::map<short, int>, std::vector<Fruit>);
void ReadFile(int&, int&, int&, int&, int&, int&, int&, std::map<short, int>&, std::vector<Fruit>&);