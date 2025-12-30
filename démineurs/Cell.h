#pragma once

struct Cell
{
	bool ContaineMine;
	bool ContaineFlague;
	bool IsReavel;
	int adjMineCount;
};

void initialize(Cell* cell);
