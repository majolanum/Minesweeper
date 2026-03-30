#pragma once

#define UPARROW 72
#define DOWNARROW 80
#define LEFTARROW 75
#define RIGHTARROW 77
#define ESCAPE 27
#define RETURN 13

#define KEY_H 104
#define KEY_E 101

class InputeManager
{
protected:
	int choice = 0;
	InputeManager() {}
	static InputeManager* instance;

public:
	static InputeManager* Get();

	int GetCodeImpute();
	~InputeManager();
};

