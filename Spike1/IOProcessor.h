#pragma once
#include "DataResources.h"
#include <list>
#include <iostream>
#include <ctype.h>

class IOProcessor
{
public:
	Move GetMove();

	void DisplayMoves(list<Move> aMoves);

	void DisplayStart();
	void DisplayWin();
	void DisplayLoss();
};