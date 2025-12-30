#include "Cell.h"

void initialize(Cell* cell)
{
	cell->ContaineMine = false;
	cell->ContaineFlague = false;
	cell->IsReavel = false;
	cell->adjMineCount = 0;
}


