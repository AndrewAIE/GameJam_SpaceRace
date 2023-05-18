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
	void CheckCollision();

private:
	
	int m_paddleHeightRatio = 45;
	int m_paddleWidthRatio = 15;
	int m_paddleSpeedRatio = 15;
	int m_paddleGapRatio = 15;

	int m_brickHeightRatio = 44;
	int m_brickWidthRatio = 16;
	int m_brickHeightOffset = 4;
	int m_brickWidthOffset = 5;
	int m_screenWidthOffset = 25;
	int m_topWindowGap = GetScreenHeight() / 6;

	float m_paddleGap = (float)(GetScreenHeight() - (GetScreenHeight() / m_paddleGapRatio));
	float m_screenCentreX = (float)((GetScreenWidth() / 2) - m_screenWidthOffset);
	float m_screenCentreY = (float)(GetScreenHeight() / 2);
	float m_brickPosX = (float)(GetScreenWidth() / brickCols);
	float m_brickPosY = (float)(GetScreenHeight() / m_brickHeightRatio);

	float m_ballSpeed = 2.0f;
	Vector2 m_ballDirection = { 0, 2 };

	Paddle m_player;
	Ball m_ball;
	Brick m_bricks[brickCols][brickRows];
};

