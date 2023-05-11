#pragma once

#include "Paddle.h"
#include "Raylib.h"

class Game
{
public:
	
	void Initialize();
	void Update();
	void Draw();
	void PlayerControl();
	



private:

	Paddle m_player;


};

