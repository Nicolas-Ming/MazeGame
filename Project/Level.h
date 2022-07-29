#pragma once
#include <string>
#include <vector>
#include "PlacableActor.h"
#include "door.h"

class PlacableActor;

class Door;

class Level
{
	char* m_pLevelData;
	int m_height;
	int m_width;

	std::vector<PlacableActor*> m_pActors;

public:
	Level();
	~Level();

	bool Load(std::string levelName, int* playerX, int* playerY);
	void Draw();
	Door* FindDoor(ActorColor plateColor, int platePositionX, int platePositionY);
	bool isOn(int platePositionX, int platePositionY);

	PlacableActor* UpdateActors(int x, int y);

	bool IsSpace(int x, int y);
	bool IsWall(int x, int y);


	int GetHeight() { return m_height; }
	int GetWidth() { return m_width;  }

	static constexpr char WAL = (char)219;

private:
	bool ConvertLevel(int* playerX, int* playerY);
	int GetIndexFromCoordinates(int x, int y);

};