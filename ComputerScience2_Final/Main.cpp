// This is my Final project it is a game that will test your knowledge on geometry.
// By Joshua McCullough

#include <iostream>
#include <string>
#include <cstdlib>
#include "Gameplay.h"
#include "Player.h"
using namespace std;

// 
Gameplay GP;
Player player[2];

// Helps validate input
char Answer;
bool bArgument;

// Functions
int MainMenu();
void StartGame();
void PlayersNames();
void WhosFirst();
void GeometryChooser();
void GameBoard();
void WhoWon();

// What start the program
int main() {

	MainMenu();

	return 0;
}

// where the players start the game or quit the game
int MainMenu()
{
	string Title = GP.getGameTitle();
	string Descritption = GP.getGameDesc();

	cout << Title << endl;
	cout << Descritption << endl;

	do
	{
		bArgument = false;

		try
		{
			cout << "\nAre you ready to play?" << endl;
			cout << "(A) Play Game" << endl;
			cout << "(B) Quit Game" << endl;
			cin >> Answer;

			if (Answer != 'A' && Answer != 'B')
			{
				throw invalid_argument("Invalid Letter\n");
			}
		}
		catch (invalid_argument& e)
		{
			cout << e.what();
			bArgument = true;
		}

	} while (bArgument == true);

	switch (Answer)
	{
	case 'A':
		cout << "\nPlay Game!!!" << endl;
		system("cls");
		StartGame();
		break;
	case 'B':
		return 0;
	default:
		break;
	}
}

void StartGame()
{
	// Finds out the names of the players
	PlayersNames();

	// It finds out who is going first
	WhosFirst();

	// The Geometry Math Question Chooser
	GeometryChooser();

	// Finds out who won
	WhoWon();
}

// Finds out the names of the players
void PlayersNames()
{
	string playerName;
	cout << "Game Started!!!" << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << "Please state the " << 1 + i << " person name." << endl;
		cin >> playerName;

		player[i].setName(playerName);

	}
}

// It finds out who is going first
void WhosFirst()
{
	srand(time(NULL));

	do
	{
		bArgument = false;

		try
		{
			for (int i = 0; i < 2; i++)
			{
				int DiceNbr = GP.PlayerRoll(player[i]);
				player[i].setDiceNbr(DiceNbr);
			}

			if (player[0].getDiceNbr() > player[1].getDiceNbr())
			{
				cout << player[0].getName() + " is now player one!" << endl;
			}
			else if (player[0].getDiceNbr() < player[1].getDiceNbr())
			{
				string Player1Name = player[0].getName();
				string Player2Name = player[1].getName();

				player[0].setName(Player2Name); // player 2 is becoming player 1
				player[1].setName(Player1Name); // player 1 is becoming player 2

				cout << player[0].getName() + " is now player one!" << endl;


			}
			else if (player[0].getDiceNbr() == player[1].getDiceNbr())
			{
				throw invalid_argument("REROLL\n");
			}

		}
		catch (invalid_argument& e)
		{
			cout << e.what();
			bArgument = true;
		}


	} while (bArgument == true);
}

// The Geometry Math Question Chooser
void GeometryChooser()
{
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			GameBoard();
			cout << "(1) (2) (3) (4) (5) (6) (7) (8) (9)" << endl;
			cout << "Player: " << player[j].getName() << " Score: " << player[j].getScore() << endl;
			cin >> Answer;

			switch (Answer)
			{
			case '1':
				player[j].setScore(GP.QTriangleLevel1());
				break;
			case '2':
				player[j].setScore(GP.QRectangleLevel1());
				break;
			case '3':
				player[j].setScore(GP.QPentagonLevel1());
				break;
			case '4':
				player[j].setScore(GP.QTriangleLevel2());
				break;
			case '5':
				player[j].setScore(GP.QRectangleLevel2());
				break;
			case '6':
				player[j].setScore(GP.QPentagonLevel2());
				break;
			case '7':
				player[j].setScore(GP.QTriangleLevel3());
				break;
			case '8':
				player[j].setScore(GP.QRectangleLevel3());
				break;
			case '9':
				player[j].setScore(GP.QPentagonLevel3());
				break;
			default:
				break;
			}

		}

	}
}

// Makes the GameBoard
void GameBoard()
{
	int width = 3;
	int height = 3;
	int Points = 0;
	int nbrChoice = 1;

	cout << " Triangle   Rectangle   Pentagon" << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << "     " << nbrChoice++ << "    |";
		}
		Points = Points + 100;
		cout << Points << endl;
	}

}

// Finds out who won
void WhoWon() {
	if (player[0].getScore() > player[1].getScore())
	{
		cout << "***" << player[0].getName() << " WON!***" << endl;
	}
	else if (player[0].getScore() < player[1].getScore())
	{
		cout << "***" << player[1].getName() << " WON!***" << endl;
	}
	else
	{
		cout << "***IT IS A TIE!***" << endl;
	}

}
