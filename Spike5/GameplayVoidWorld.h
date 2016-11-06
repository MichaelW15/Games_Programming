#pragma once
#include "State.h"
class GameplayVoidWorld :
	public State
{
public:
	virtual States runState();

	States getNextState();
	void initialiseWorld();
};

