#pragma once

struct Cell
{
	bool ContaineMine = false;
	bool ContaineFlague = false;
	bool IsReavel = false;
	int adjMineCount = 0;
};

void initialize(Cell* cell);
