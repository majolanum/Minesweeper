#pragma once
#include "Cell.h"

class Grid
{
	Cell** cell;
	int rowCount = 0;
	int	colCount = 0;
	int MineNumber = 0;
	bool firstgrid = true;

	const char* RESET = "\033[0m";

	const char* RED = "\033[31m";
	const char* GREEN = "\033[32m";
	const char* BLUE = "\033[34";
	const char* PURPLE = "\033[35m";
	const char* CYAN = "\033[36m";
	const char* YELLOW = "\033[33m";

public:
	int srand(int min, int max);

	void initializevalue(int raw, int col);
	void initializegrid(Grid* grid);

	void placemine(int rowExeption, int colExeption);

	void printcell(int raw, int col);
	void printcellnumber(int raw, int col);
	void printTable();
	void printendtable();

	int countadjacentmine(int raw, int col);
	void checkadjcell(int row, int col);
	int checkcell(int row, int col);
	int countopencell();

	void placeflague(int row, int col);

	void freeelement();

	Cell** getcell() { return cell; }
};

