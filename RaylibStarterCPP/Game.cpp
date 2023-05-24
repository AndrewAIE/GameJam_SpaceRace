
#include "Game.h"


void Game::Initialize() 
{
	m_player = Paddle{ GetScreenHeight() / m_paddleHeightRatio, GetScreenWidth() / m_paddleWidthRatio, m_paddleSpeedRatio, 
				{m_screenCentreX, m_paddleGap}};

	m_ball = Ball{ 10, 5, m_ballSpeed, {m_screenCentreX, m_screenCentreY}, m_ballDirection, WHITE };

	for (int x = 0.0f; x < brickCols; x++) 
	{
		for (int y = 0.0f; y < brickRows; y++) 
		{
			m_bricks[x][y] = Brick((GetScreenHeight() / m_brickHeightRatio) - m_brickHeightOffset, (GetScreenWidth() / brickCols) - m_brickWidthOffset, 
								{ x * m_brickPosX + m_brickWidthOffset, y * m_brickPosY + m_topWindowGap });
			m_bricks[x][y].AssignColor(y);
		}
	}	
}

void Game::Update() 
{
	
	
	PlayerControl();
	m_ball.Update();
	CheckCollision();
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

void Game::CheckCollision() 
{
	m_ball.CheckCollision(m_player.GetBoundBox());
	m_ball.EdgeCollision();
	for (int x = 0; x < brickCols; x++)
	{
		for (int y = 0; y < brickRows; y++)
		{
			if (!m_bricks[x][y].GetDestroyed()) 
			{
				m_ball.CheckCollision(m_bricks[x][y].GetBoundBox());
				if (CheckCollisionRecs(m_ball.GetBoundBox(), m_bricks[x][y].GetBoundBox()))
				{
					m_bricks[x][y].Destroy();
				}
			}		
		}
	}
}

bool Game::CheckIfRunning()
{
	return m_gameRunning;
}





