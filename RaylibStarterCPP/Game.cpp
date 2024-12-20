
#include "Game.h"


void Game::Initialize() 
{
	int m_bricksLeft = brickCols * brickRows;
	int m_playerLives = 3;
	m_gameRunning = true;

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
	if (m_activeBall) 
	{
		m_ball.Update();
		CheckCollision();
		m_playerLives = m_ball.GetLifeCount();
		CheckGameOver();

	}
	
	
}
void Game::Draw() 
{
	DrawText("Score: " + char(m_gameScore), 5, 15, 30, WHITE);
	DrawText("Lives: " + char(m_playerLives), 5, 55, 30, WHITE);
	
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
	if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) 
	{
		m_player.MoveLeft();
	}

	if (IsKeyDown(KEY_RIGHT) ||IsKeyDown(KEY_D)) 
	{
		m_player.MoveRight();
	}

	if (IsKeyPressed(KEY_SPACE))
	{
		m_activeBall = true;
	}
}

void Game::CheckCollision() 
{
	m_ball.CheckCollision(m_player.GetBoundBox());
	m_ball.EdgeCollision();
	m_activeBall = m_ball.BottomEdgeCollision();
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
					m_gameScore += m_ball.AddToScore();
					m_bricksLeft--;
				}
			}		
		}
	}
	
	
	
}



void Game::CheckGameOver() 
{
	if (m_bricksLeft == 0 || m_playerLives == 0) 
	{
		m_bricksLeft = brickCols * brickRows;
		m_playerLives = 3;
		m_gameRunning = false;
	}
}

bool Game::CheckIfRunning()
{
	return m_gameRunning;
}




