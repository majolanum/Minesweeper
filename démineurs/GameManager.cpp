#include <iostream>
#include "GameManager.h"

GameManager* GameManager::instance = nullptr;

GameManager* GameManager::get()
{
	if (instance == nullptr)
		instance = new GameManager();
	return instance;
}

int GameManager::askint(const char* msg, int min, int max)
{
	int value = -100;
	while (value > max || value < min)
	{
		std::cout << msg << std::endl;
		std::cout << "->";
		std::cin >> value;
	}
	return value;
}

void GameManager::initializeGame()
{
	grid = new Grid();
	askdificulty();
	grid->initializegrid(grid);
}

void GameManager::askdificulty()
{
	const char* msg = "Quelle difficulte voulez-vous choisir (1: Facile / 2: Moyen / 3: Difficile / 4: Personnalise)";
	int difficulty = askint(msg, 1, 4);

	switch (difficulty)
	{
	case 1:
	{
		grid->initializevalue(9, 9);
		rowCount = 9;
		colCount = 9;
		safeCase = (9 * 9) - ((9 * 9) * 0.15f);
		break;
	}
	case 2:
	{
		grid->initializevalue(16, 16);
		rowCount = 16;
		colCount = 16;
		safeCase = (16 * 16) - ((16 * 16) * 0.15f);
		break;
	}
	case 3:
	{
		grid->initializevalue(30, 16);
		rowCount = 30;
		colCount = 16;
		safeCase = (30 * 16) - ((30 * 16) * 0.15f);
		break;
	}
	case 4:
	{
		int row = askint("size of row", 0, 100);
		int col = askint("size of col", 0, 100);
		grid->initializevalue(row, col);
		rowCount = row;
		colCount = col;
		safeCase = (row * col) - ((row * col) * 0.15f);
		break;
	}
	}
}

void GameManager::gameloop(int* gamestate)
{
	grid->printTable();
	int row = askint("Coordonnee de la colonne ", 0, colCount);
	int col = askint("Coordonnee de la ligne ", 0, rowCount);

	int choice = askint("Que voulez vous faire (1: Reveler la case / 2: Placer un drapeau)", 1, 2);

	switch (choice)
	{
	case 1:
	{
		*gamestate = grid->checkcell(row, col);
		OpenCellCount = grid->countopencell();
		break;
	}
	case 2:
	{
		grid->placeflague(row, col);
		break;
	}
	}
	system("cls");

	if (OpenCellCount == safeCase)
		*gamestate = 2;
}

