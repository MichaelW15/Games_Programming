#include <iostream>
#include "MoveHandler.h"
#include "IOProcessor.h"
#include "DataResources.h"

using namespace std;

int main()
{
	IOProcessor lIOProcessor;
	MoveHandler lMoveHandler;
	Move lNextMove;
	GameState lGameState = Valid;

	lIOProcessor.DisplayStart();

	while (true)
	{
		lIOProcessor.DisplayMoves(lMoveHandler.GetValidMoves());
		lNextMove = lIOProcessor.GetMove();

		while (!lMoveHandler.ValidateMove(lNextMove))
		{
			lIOProcessor.DisplayMoves(lMoveHandler.GetValidMoves());
			lNextMove = lIOProcessor.GetMove();
		}

		if (lNextMove == Quit)
			break;

		lMoveHandler.UpdatePosition(lNextMove);

		lGameState = lMoveHandler.GetGameState();

		if (lGameState == Win)
		{
			lIOProcessor.DisplayWin();
			break;
		}
		else if (lGameState == Loss)
		{
			lIOProcessor.DisplayLoss();
			break;
		}

	}



	return 0;
}