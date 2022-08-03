#pragma once
#include "PlacableActor.h"
#include "PressurePlate.h"

class Door : public PlacableActor
{
public:
	Door(int x, int y, ActorColor color, ActorColor closedColor);
	virtual void Draw() override;
	virtual void gotCollided(PlacableActor &player) override;

	virtual ActorType GetType() override { return ActorType::Door;  }
	bool IsOpen() { return m_isOpen;  }
	void Open() { m_isOpen = true; }
	void Close() { m_isOpen = false; }

private:
	bool m_isOpen;
	ActorColor m_closedColor;
};

