#include <iostream>
#include <windows.h>
#include "PressurePlate.h"

PressurePlate::PressurePlate(int x, int y, ActorColor color)
	: PlacableActor(x, y, color)
	, m_isPressured(false)
{

}

void PressurePlate::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (m_isPressured)
	{
		// Do not Draw the item if pressured
	}
	else
	{
		SetConsoleTextAttribute(console, (int)m_color);
		std::cout << (char)177;
	}
	
	SetConsoleTextAttribute(console, (int)ActorColor::Regular);
}
void checkPressure(Point* actorPosition) {

}
