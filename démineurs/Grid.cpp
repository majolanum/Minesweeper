#include <cstdlib>
#include <iostream>
#include "Grid.h"

int Grid::srand(int min, int max)
{
	int r = min + (rand() % (max - min + 1));

	return r;
}

void Grid::initializevalue(int row, int col)
{
	rowCount = row;
	colCount = col;
	MineNumber = (row * col) * 0.15f;

	std::cout << "Grille de " << row << " par " << col << std::endl;
	std::cout << "Il y a " << MineNumber << " mines" << std::endl;
}

void Grid::initializegrid(Grid* grid)
{
	Cell** array2D = (Cell**)malloc(sizeof(Cell*) * grid->rowCount);
	for (int row = 0; row < grid->rowCount; ++row)
	{
		array2D[row] = (Cell*)malloc(sizeof(Cell) * grid->colCount);
		for (int col = 0; col < grid->colCount; ++col)
		{
			initialize(&array2D[row][col]);
		}
	}
	grid->cell = array2D;
}

void Grid::placemine(int rowExeption, int colExeption)
{
	int mineplaced = 0;
	while (mineplaced != MineNumber)
	{
		int row = srand(0, (rowCount - 1));
		int col = srand(0, (colCount - 1));
		if (rowExeption = row && colExeption == col) continue;

		if (cell[row][col].ContaineMine == true) continue;
		if (cell[row][col].IsReavel == true) continue;
		cell[row][col].ContaineMine = true;
		mineplaced++;
	}
}

void Grid::printcell(int row, int col)
{
	if (cell[row][col].ContaineFlague == true)
	{
		std::cout << RED << "F" << RESET << " | ";
		return;
	}
	if (cell[row][col].ContaineMine == true && cell[row][col].IsReavel == true)
	{
		std::cout << PURPLE << "*" << RESET << " | ";
		return;
	}
	if (cell[row][col].IsReavel == true)
	{
		printcellnumber(row, col);
		return;
	}
	if (cell[row][col].IsReavel == false)
	{
		std::cout << " " << RESET << " | ";
		return;
	}
}

void Grid::printcellnumber(int row, int col)
{
	int AdjMineCount = cell[row][col].adjMineCount;

	switch (AdjMineCount)
	{
	case 0: std::cout << RESET << "0" << RESET << " | "; break;
	case 1: std::cout << YELLOW << "1" << RESET << " | ";break;
	case 2: std::cout << RED << "2" << RESET << " | ";break;
	case 3: std::cout << GREEN << "3" << RESET << " | ";break;
	case 4: std::cout << BLUE << "4" << RESET << " | ";break;
	case 5: std::cout << CYAN << "5" << RESET << " | ";break;
	case 6: std::cout << PURPLE << "6" << RESET << " | ";break;
	case 7: std::cout << RESET << "7" << RESET << " | ";break;
	}
}

void Grid::printTable()
{
	std::cout << "  ";
	for (int i = 0; i <= (rowCount - 1); i++)
	{
		if (i < 10)
			std::cout << "   " << i;
		else
			std::cout << "  " << i;
	}

	std::cout << std::endl;
	for (int i = 0; i <= (colCount - 1); i++)
	{
		std::cout << "   ";

		for (int i = 0; i <= (rowCount - 1); i++)
		{
			std::cout << "+---";
		}

		std::cout << "+" << std::endl;
		if (i < 10)
			std::cout << i << "  | ";
		else
			std::cout << i << " | ";


		for (int n = 0; n <= (rowCount - 1); n++)
		{
			printcell(n, i);
		}
		std::cout << std::endl;

	}
	std::cout << "   ";
	for (int i = 0; i <= (rowCount - 1); i++)
	{

		std::cout << "+---";
	}

	std::cout << "+" << std::endl;
}

void Grid::printendtable()
{
	std::cout << "  ";
	for (int i = 0; i <= (rowCount - 1); i++)
	{
		if (i < 10)
			std::cout << "   " << i;
		else
			std::cout << "  " << i;
	}

	std::cout << std::endl;
	for (int i = 0; i <= (colCount - 1); i++)
	{
		std::cout << "   ";

		for (int i = 0; i <= (rowCount - 1); i++)
		{
			std::cout << "+---";
		}

		std::cout << "+" << std::endl;
		if (i < 10)
			std::cout << i << "  | ";
		else
			std::cout << i << " | ";


		for (int n = 0; n <= (rowCount - 1); n++)
		{
			if (cell[n][i].ContaineMine == true)
				std::cout << PURPLE << "*" << RESET << " | ";
			else
				printcellnumber(n, i);
		}
		std::cout << std::endl;

	}
	std::cout << "   ";
	for (int i = 0; i <= (rowCount - 1); i++)
	{

		std::cout << "+---";
	}

	std::cout << "+" << std::endl;
}

int Grid::countadjacentmine(int row, int col)
{
	int MineCount = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int n = -1; n <= 1; n++)
		{
			int rowNeighbor = row + n;
			int colNeighbor = col + i;

			if (rowNeighbor < 0 || rowNeighbor >= rowCount)
				continue;
			if (colNeighbor < 0 || colNeighbor >= colCount)
				continue;

			if (cell[rowNeighbor][colNeighbor].ContaineMine)
				MineCount++;
		}
	}
	return MineCount;
}

void Grid::checkadjcell(int row, int col)
{
	int adjmine = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int n = -1; n <= 1; n++)
		{
			int rowCellNeighbor = row + n;
			int colCellNeighbor = col + i;

			if (rowCellNeighbor < 0 || rowCellNeighbor >= rowCount)
				continue;
			if (colCellNeighbor < 0 || colCellNeighbor >= colCount)
				continue;

			if (colCellNeighbor == row && rowCellNeighbor == col) continue;

			if (cell[rowCellNeighbor][colCellNeighbor].ContaineMine == true)
				continue;

			if (cell[rowCellNeighbor][colCellNeighbor].ContaineFlague == true)
				continue;

			if (cell[rowCellNeighbor][colCellNeighbor].IsReavel == true)
				continue;

			cell[rowCellNeighbor][colCellNeighbor].IsReavel = true;
			cell[rowCellNeighbor][colCellNeighbor].adjMineCount = countadjacentmine(rowCellNeighbor, colCellNeighbor);
			if (countadjacentmine(rowCellNeighbor, colCellNeighbor) == 0)
				checkadjcell(rowCellNeighbor, colCellNeighbor);
		}
	}
}

int Grid::checkcell(int row, int col)
{
	if (firstgrid == true)
	{
		placemine(row, col);
		firstgrid = false;
	}

	if (cell[row][col].ContaineFlague == true)
		return 1;

	if (cell[row][col].IsReavel == false)
	{
		cell[row][col].IsReavel = true;
		cell[row][col].adjMineCount = countadjacentmine(row, col);
		checkadjcell(row, col);
	}

	if (cell[row][col].ContaineMine == true && cell[row][col].IsReavel == true)
		return 0;

	return 1;
}

int Grid::countopencell()
{
	int cellCount = 0;
	for (int i = 0; i < colCount; i++)
	{
		for (int n = 0; n < rowCount; n++)
		{
			if (cell[n][i].IsReavel == true)
				cellCount++;
		}
	}
	return cellCount;
}

void Grid::placeflague(int row, int col)
{
	if (cell[row][col].ContaineFlague == false)
		cell[row][col].ContaineFlague = true;
	else
		cell[row][col].ContaineFlague = false;
}

void Grid::freeelement()
{
	for (int i = 0; i < rowCount; i++)
	{
		free(cell[i]);
		cell[i] = nullptr;
	}
	free(cell);
	cell = nullptr;
	rowCount = 0;
	colCount = 0;
	MineNumber = 0;

}
