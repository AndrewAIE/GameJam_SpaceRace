#pragma once

#include "Paddle.h"
#include "Brick.h"
#include "GameDefines.h"
#include "Raylib.h"
#include "Ball.h"


class Game
{
public:
	
	void Initialize();
	void Update();
	void Draw();
	void PlayerControl();
	
private:
	
	int m_paddleHeightRatio = 45;
	int m_paddleWidthRatio = 15;
	int m_paddleSpeedRatio = 15;
	int m_paddleGapRatio = 15;

	int m_brickHeightRatio = 50;
	int m_brickWidthRatio = 16;
	int m_brickHeightOffset = 5;
	int m_brickWidthOffset = 5;

	Vector2 m_ballSpeed = { 20, 20 };

	int m_topWindowGap = GetScreenHeight() / 6;

	Paddle m_player;
	Ball m_ball;
	Brick m_bricks[brickCols][brickRows];


};

