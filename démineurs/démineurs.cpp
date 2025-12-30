#include <iostream>
#include "GameManager.h"

int main()
{
	srand(time(NULL));
	bool run = true;
	int gamestate = -1;

	while (run)
	{
		if (gamestate == -1)
		{
			GameManager::get()->initializeGame();
			gamestate = 1;
		}

		while (gamestate == 1)
		{
			GameManager::get()->gameloop(&gamestate);
		}

		if (gamestate == 0)
		{
			GameManager::get()->GetGrid()->printendtable();
			std::cout << "Vous avez toucher une mine" << std::endl;			
		}

		if (gamestate == 2)
		{
			GameManager::get()->GetGrid()->printendtable();
			std::cout << "Vous avez trouver toute les mines" << std::endl;			
		}

		run = GameManager::get()->askint("Voulez vous rejouer ? (0/1)", 0, 1);
		if (run == 1)
		{
			gamestate = 1;
			GameManager::get()->GetGrid()->freeelement();
		}
	}
	return 0;
}

