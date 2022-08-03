#include <iostream>
#include <windows.h>

#include "Key.h"
#include "Player.h"
#include "AudioManager.h"

void Key::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, (int)m_color);

	std::cout << "+";
	SetConsoleTextAttribute(console, (int)ActorColor::Regular);
}
void Key::gotCollided(PlacableActor& player) {
	Player* activePlayer = dynamic_cast<Player*>(&player);
	if (!activePlayer->HasKey())
	{
		activePlayer->PickupKey(this);
		Remove();
		player.SetPosition(GetXPosition(), GetYPosition());
		AudioManager::GetInstance()->PlayKeyPickupSound();
	}
}
