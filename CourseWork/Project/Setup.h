#pragma once
#include <map>
#include "Input.h"
#include "SomeObject.h"

static bool gameOver;
static bool viewItem = false;
static int start_time;
static int curr_time;
static int delay_time;
static double timer;
static int questCount = 0;
static int score = 0;
static const int width = 11;
static const int height = 9;
static SomeObject* space[width][height];
static int x, y, viewX, viewY;
static std::string text;
static std::map<short, int> quest;
static std::vector<Fruit> bag(0);

void Setup(int&, int&, int&, int&, SomeObject* (*)[9]);