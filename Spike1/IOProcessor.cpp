#include "IOProcessor.h"


Move IOProcessor::GetMove()
{
	char lInput;

	cin >> lInput;
	lInput = toupper(lInput);

	switch (lInput)
	{
	default:
		return GetMove();
		break;
	case 'N':
		return North;
		break;
	case 'S':
		return South;
		break;
	case 'E':
		return East;
		break;
	case 'W':
		return West;
		break;
	case 'Q':
		return Quit;
		break;
	}
}

void IOProcessor::DisplayMoves(list<Move> aMoves)
{
	cout << "You can move ";

	for each (Move m in aMoves)
	{
		switch (m)
		{
		case North:
			cout << "North";
			break;
		case South:
			cout << "South";
			break;
		case East:
			cout << "East";
			break;
		case West:
			cout << "West";
			break;
		default:
			break;
		}

		cout << ", ";
	}

	cout << ":> ";

}

void IOProcessor::DisplayStart()
{
	cout << "Welcome to GridWorld : Quantised Excitement.Fate is waiting for You!" << endl;
	cout << "Valid commands : N, S, E and W for direction. Q to quit the game." << endl;
}

void IOProcessor::DisplayWin()
{
	cout << "Wow - you’ve discovered a large chest filled with GOLD coins!" << endl;
	cout << "YOU WIN!" << endl;
	cout << "Thanks for playing.There probably won’t be a next time." << endl;
}

void IOProcessor::DisplayLoss()
{
	cout << "Arrrrgh... you’ve fallen down a pit." << endl;
	cout << "YOU HAVE DIED!" << endl;
	cout << "Thanks for playing. Maybe next time." << endl;
}