
#include "Game.h"


void Game::Initialize() 
{
	m_player = Paddle{ GetScreenHeight() / m_paddleHeightRatio, GetScreenWidth() / m_paddleWidthRatio, m_paddleSpeedRatio, 
				{GetScreenWidth() / 2, GetScreenHeight() - GetScreenHeight() / m_paddleGapRatio}};

	m_ball = Ball{ 4, m_ballSpeed, {GetScreenWidth() / 2, (GetScreenHeight() / 2) + m_topWindowGap}, WHITE };

	for (int x = 0; x < brickCols; x++) 
	{
		for (int y = 0; y < brickRows; y++) 
		{
			m_bricks[x][y] = Brick((GetScreenHeight() / m_brickHeightRatio) - m_brickHeightOffset, (GetScreenWidth() / brickCols) - m_brickWidthOffset, 
								{ x * (GetScreenWidth() / brickCols) + m_brickWidthOffset, (y * (GetScreenHeight() / m_brickHeightRatio)) + m_topWindowGap });
			m_bricks[x][y].AssignColor(y);
		}
	}
	
}

void Game::Update() 
{
	PlayerControl();
}
void Game::Draw() 
{
	m_player.Draw();
	m_ball.Draw();
	for (int x = 0; x < brickCols; x++) 
	{
		for (int y = 0; y < brickRows; y++) 
		{
			m_bricks[x][y].Draw();
		}
	}
}

void Game::PlayerControl() 
{
	if (IsKeyDown(KEY_LEFT)) 
	{
		m_player.MoveLeft();
	}

	if (IsKeyDown(KEY_RIGHT)) 
	{
		m_player.MoveRight();
	}

}



