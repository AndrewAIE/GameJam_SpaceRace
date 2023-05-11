
#include "Game.h"






void Game::Initialize() 
{
	m_player.SetPosition(Point2D{ GetScreenWidth() / 2, 10 });
}

void Game::Update() 
{
	PlayerControl();
}
void Game::Draw() 
{
	m_player.Draw();
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



