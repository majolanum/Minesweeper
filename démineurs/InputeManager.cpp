#include <conio.h>
#include <iostream>
#include "InputeManager.h"

InputeManager* InputeManager::instance = nullptr;

InputeManager* InputeManager::Get()
{
	if (instance == nullptr)
	{
		instance = new InputeManager;
	}
	return instance;
}

int InputeManager::GetCodeImpute()
{
	choice = -1;
	do {
		choice = _getch();
	} while (choice == -1);

	if (choice == 0 || choice == 224)
	{
		choice = _getch();
		return choice;
	}
	return choice;
}

InputeManager::~InputeManager()
{
	choice = NULL;
	instance = nullptr;
}

