#include <iostream>
#include <thread>
#include <conio.h>

#include "MoveHandler.h"
#include "IOProcessor.h"
#include "DataResources.h"

using namespace std;

void WaitForInput(bool &aInputRequired, Move &aNextMove, IOProcessor &aIOProcessor)
{
	while (true)
	{
		if (aInputRequired)
		{
			aNextMove = aIOProcessor.GetMove();	
			aInputRequired = false;
		}

	}
}

int main()
{
	bool lInputRequired = true;

	IOProcessor lIOProcessor;
	MoveHandler lMoveHandler;
	Move lNextMove;
	GameState lGameState = Valid;

	thread lInputThread(WaitForInput, ref(lInputRequired), ref(lNextMove), ref(lIOProcessor));

	lIOProcessor.DisplayStart();
	lIOProcessor.DisplayMoves(lMoveHandler.GetValidMoves());

	while (true)
	{

		if (!lInputRequired) {
			

			if (!lMoveHandler.ValidateMove(lNextMove))
			{
				lIOProcessor.DisplayMoves(lMoveHandler.GetValidMoves());
				lInputRequired = true;
			}

			if (lNextMove == Quit)
				break;

			if (!lInputRequired) {
				lMoveHandler.UpdatePosition(lNextMove);
				lIOProcessor.DisplayMoves(lMoveHandler.GetValidMoves());
				lInputRequired = true;
			}

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
	
	}

	lInputThread.join();

	return 0;
}