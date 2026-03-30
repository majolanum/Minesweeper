#include "Cell.h"

void initialize(Cell* cell)
{
	cell->ContaineMine = false;
	cell->ContaineFlague = false;
	cell->IsReavel = false;
	cell->Selected = false;
	cell->adjMineCount = 0;
}