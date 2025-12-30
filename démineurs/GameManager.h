#pragma once
#include "Grid.h"
class GameManager
{
private:
	static GameManager* instance;
	int OpenCellCount = 0;
	int safeCase = 0;
	int rowCount = 0;
	int colCount = 0;

	Grid* grid;

public:
	static GameManager* get();
	int askint(const char* msg,	int min, int max);

	void initializeGame();

	void askdificulty();

	void gameloop(int* gamestate);

	Grid* GetGrid() { return grid; }
};

