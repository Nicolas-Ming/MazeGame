#include <iostream>
#include <windows.h>
#include "Door.h"
#include "PressurePlate.h"
#include "Player.h"
#include "AudioManager.h"

Door::Door(int x, int y, ActorColor color, ActorColor closedColor)
	: PlacableActor(x, y, color)
	, m_isOpen(false)
	, m_closedColor(closedColor)
{

}

void Door::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (m_isOpen)
	{
		SetConsoleTextAttribute(console, 16);
	}
	else
	{
		SetConsoleTextAttribute(console, (int)m_closedColor);
	}
	std::cout << "|";
	SetConsoleTextAttribute(console, (int)ActorColor::Regular);
}

void Door::gotCollided(PlacableActor& player) {
	Player* activePlayer = dynamic_cast<Player*>(&player);
	if (!IsOpen())
	{
		if (activePlayer->HasKey(GetColor()))
		{
			Open();
			Remove();
			activePlayer->UseKey();
			activePlayer->SetPosition(GetXPosition(), GetYPosition());
			AudioManager::GetInstance()->PlayDoorOpenSound();
		}
		else
		{
			AudioManager::GetInstance()->PlayDoorClosedSound();
		}
	}
	else
	{
		activePlayer->SetPosition(GetXPosition(), GetYPosition());
	}
}
