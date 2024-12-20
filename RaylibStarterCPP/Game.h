#pragma once

#include "Paddle.h"
#include "Brick.h"
#include "GameDefines.h"
#include "Raylib.h"
#include "Ball.h"
#include <vector>


class Game
{
public:
	
	void Initialize();
	void Update();
	void Draw();
	void PlayerControl();
	void CheckCollision();
	void CheckGameOver();
	bool CheckIfRunning();

private:
	
	int m_gameScore = 0;
	int m_bricksLeft = brickCols * brickRows;
	int m_playerLives = 3;
	int m_highScore;
	
	
	int m_paddleHeightRatio = 45;
	int m_paddleWidthRatio = 15;
	int m_paddleSpeedRatio = 15;
	int m_paddleGapRatio = 15;

	int m_brickHeightRatio = 44;
	int m_brickWidthRatio = 16;
	int m_brickHeightOffset = 4;
	int m_brickWidthOffset = 5;
	int m_screenWidthOffset = 10;
	int m_topWindowGap = GetScreenHeight() / 6;

	float m_paddleGap = (float)(GetScreenHeight() - (GetScreenHeight() / m_paddleGapRatio));
	float m_screenCentreX = (float)((GetScreenWidth() / 2) - m_screenWidthOffset);
	float m_screenCentreY = (float)(GetScreenHeight() / 2);
	float m_brickPosX = (float)(GetScreenWidth() / brickCols);
	float m_brickPosY = (float)(GetScreenHeight() / m_brickHeightRatio);

	bool m_gameRunning = true;
	bool m_activeBall = false;
	
	float m_ballSpeed = 2.0f;
	Vector2 m_ballDirection = { 1, 2 };

	Paddle m_player;
	Ball m_ball;
	
	Brick m_bricks[brickCols][brickRows];
};

