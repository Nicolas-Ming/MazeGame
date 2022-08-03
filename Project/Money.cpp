#include <iostream>
#include "Money.h"
#include "AudioManager.h"
#include "Player.h"

Money::Money(int x, int y, int worth)
	: PlacableActor(x, y)
	, m_worth(worth)
{

}

void Money::Draw()
{
	std::cout << "$";
}

void Money::gotCollided(PlacableActor &player)
{
	Player* activePlayer = dynamic_cast<Player*>(&player);
	AudioManager::GetInstance()->PlayMoneySound();
	Remove();
	activePlayer->AddMoney(GetWorth());
	player.SetPosition(GetXPosition(), GetYPosition());
}
