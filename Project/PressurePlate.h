#pragma once
#include "PlacableActor.h"

class PressurePlate : public PlacableActor
{
public:
	PressurePlate(int x, int y, ActorColor color);
	virtual void Draw() override;
	virtual void gotCollided(PlacableActor &player) override;

	virtual ActorType GetType() override { return ActorType::PressurePlate; }
	bool IsPressured() { return m_isPressured; }
	void pressured() { m_isPressured = true; }
	void noPressure() { m_isPressured = false; }
	//void checkPressure( Point* actorPosition );

private:
	bool m_isPressured;
};