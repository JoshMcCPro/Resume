#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "Stack.h"
#include "tower.h"
using namespace std;

class GameFunctions {
private:
	int NbrOfLetters;
public:
	// constructor
	GameFunctions();
	// Displays Stacks
	void display(DynamicStack Stack[]);
	// Places the letters A B C in a random order
	void randomPlacement(DynamicStack Stack[]);
	// Main Menu of the game
	void Menu(DynamicStack Stack[]);
	// Check Menu
	void CheckMenu(DynamicStack Stack[]);
	// Stacks the letters
	void Stacking(DynamicStack Stack[], int from, int to);
	// Checks if the stack is correct
	void CheckIt(DynamicStack Stack[], int i);
	// First Stack Menu
	void FirstStack(DynamicStack Stack[]);
	// Second Stack Menu
	void SecondStack(DynamicStack Stack[]);
	// Third Stack Menu
	void ThirdStack(DynamicStack Stack[]);
	// set nbr of letters
	void setNbrOfLetters(int nbr);
	// gets nbr of letters
	int getNbrOfLetters();
};
// constructor
GameFunctions::GameFunctions()
{
	// Default nbr of letters
	NbrOfLetters = 3;
}
// Places the letters A B C in a random order
void GameFunctions::randomPlacement(DynamicStack Stack[])
{
	char fill[] = "ABCDEF";
	int Amount = 3;
	int count = 0;
	char menuSelect;
	bool quit;

	do
	{
		quit = true;

		cout << "----------------------------" << endl;
		cout << "How many letters will like to play with?" << endl;
		cout << "(A) 3" << endl;
		cout << "(B) 4" << endl;
		cout << "(C) 5" << endl;
		cout << "(D) 6" << endl;
		cout << "(E) Exit" << endl;
		cout << "----------------------------" << endl;

		cout << "What would you like to choose?" << endl;
		cin >> menuSelect;

		switch (menuSelect)
		{
		case 'A':
			Amount = 3;
			break;
		case 'B':
			Amount = 4;
			break;
		case 'C':
			Amount = 5;
			break;
		case 'D':
			Amount = 6;
			break;
		case 'E':
			exit(0);
			break;
		default:
			cout << "Invalid" << endl;
			quit = false;
			break;
		}

	} while (!quit);

	setNbrOfLetters(Amount);

	for (int i = 0; i < getNbrOfLetters(); i++)
	{
		if (count == 0)
		{
			Stack[0].push(fill[i]);
			count = rand() % 3;
		}
		else if (count == 1)
		{
			Stack[1].push(fill[i]);
			count = rand() % 3;
		}
		else if (count == 2)
		{
			Stack[2].push(fill[i]);
			count = rand() % 3;
		}

	}
}
// Main Menu of the game
void GameFunctions::Menu(DynamicStack Stack[])
{
	randomPlacement(Stack);

	char menuSelect;
	bool quit;

	cout << "The objective of the game is to make the letters in alphabetical order. (ABC....)" << endl;

	do
	{
		quit = false;

		display(Stack);

		cout << "----------------------------" << endl;
		cout << "What letter would like to move?" << endl;
		cout << "(A) First Stack" << endl;
		cout << "(B) Second Stack" << endl;
		cout << "(C) Third Stack" << endl;
		cout << "(D) Check If You Have Won!" << endl;
		cout << "(E) Exit" << endl;
		cout << "----------------------------" << endl;

		cout << "What would you like to choose?" << endl;
		cin >> menuSelect;

		switch (menuSelect)
		{
		case 'A':
			FirstStack(Stack);
			break;
		case 'B':
			SecondStack(Stack);
			break;
		case 'C':
			ThirdStack(Stack);
			break;
		case 'D':
			CheckMenu(Stack);
			break;
		case 'E':
			quit = true;
			break;
		default:
			cout << "Invalid" << endl;
			break;
		}

	} while (!quit);
}
// Check Menu
void GameFunctions::CheckMenu(DynamicStack Stack[])
{
	char menuSelect;
	bool quit = false;

	do
	{
		quit = false;

		display(Stack);

		cout << "----------------------------" << endl;
		cout << "What stack would you like to check?" << endl;
		cout << "(A) First Stack" << endl;
		cout << "(B) Second Stack" << endl;
		cout << "(C) Third Stack" << endl;
		cout << "(D) Back" << endl;
		cout << "----------------------------" << endl;

		cout << "What would you like to choose?" << endl;
		cin >> menuSelect;

		switch (menuSelect)
		{
		case 'A':
			CheckIt(Stack, 0);
			break;
		case 'B':
			CheckIt(Stack, 1);
			break;
		case 'C':
			CheckIt(Stack, 2);
			break;
		case 'D':
			quit = true;
			break;
		default:
			cout << "Invalid" << endl;
			break;
		}

	} while (!quit);
}
// Stacks the letters
void GameFunctions::Stacking(DynamicStack Stack[], int from, int to)
{
	try
	{
		Stack[to].push(Stack[from].getTop());
		Stack[from].pop();
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}


}
// Checks if the stack is correct
void GameFunctions::CheckIt(DynamicStack Stack[], int i)
{

	Stack[i].CheckStack(i, getNbrOfLetters());
	cout << endl;

}
// First Stack Menu
void GameFunctions::FirstStack(DynamicStack Stack[])
{
	char menuSelect;
	bool quit = false;

	do
	{
		quit = false;

		display(Stack);

		cout << "----------------------------" << endl;
		cout << "Where would you like to move the piece?" << endl;
		cout << "(A) Second Stack" << endl;
		cout << "(B) Third Stack" << endl;
		cout << "(C) Back" << endl;
		cout << "----------------------------" << endl;

		cout << "What would you like to choose?" << endl;
		cin >> menuSelect;

		switch (menuSelect)
		{
		case 'A':
			Stacking(Stack, 0, 1);
			break;
		case 'B':
			Stacking(Stack, 0, 2);
			break;
		case 'C':
			quit = true;
			break;
		default:
			cout << "Invalid" << endl;
			break;
		}

	} while (!quit);

}
// Second Stack Menu
void GameFunctions::SecondStack(DynamicStack Stack[])
{
	char menuSelect;
	bool quit = false;

	do
	{
		quit = false;

		display(Stack);

		cout << "----------------------------" << endl;
		cout << "Where would you like to move the piece?" << endl;
		cout << "(A) First Stack" << endl;
		cout << "(B) Third Stack" << endl;
		cout << "(C) Back" << endl;
		cout << "----------------------------" << endl;

		cout << "What would you like to choose?" << endl;
		cin >> menuSelect;

		switch (menuSelect)
		{
		case 'A':
			Stacking(Stack, 1, 0);
			break;
		case 'B':
			Stacking(Stack, 1, 2);
			break;
		case 'C':
			quit = true;
			break;
		default:
			cout << "Invalid" << endl;
			break;
		}

	} while (!quit);
}
// Third Stack Menu
void GameFunctions::ThirdStack(DynamicStack Stack[])
{
	char menuSelect;
	bool quit = false;

	do
	{
		quit = false;

		display(Stack);

		cout << "----------------------------" << endl;
		cout << "Where would you like to move the piece?" << endl;
		cout << "(A) Second Stack" << endl;
		cout << "(B) First Stack" << endl;
		cout << "(C) Back" << endl;
		cout << "----------------------------" << endl;

		cout << "What would you like to choose?" << endl;
		cin >> menuSelect;

		switch (menuSelect)
		{
		case 'A':
			Stacking(Stack, 2, 1);
			break;
		case 'B':
			Stacking(Stack, 2, 0);
			break;
		case 'C':
			quit = true;
			break;
		default:
			cout << "Invalid" << endl;
			break;
		}

	} while (!quit);
}
// Displays Stacks
void GameFunctions::display(DynamicStack Stack[]) {
	for (int i = 0; i < 3; i++)
	{
		Stack[i].printStack(i);
	}
	cout << "-----------------------------------" << endl;

}
// set nbr of letters
void GameFunctions::setNbrOfLetters(int nbr)
{
	this->NbrOfLetters = nbr;
}
// gets nbr of letters
int GameFunctions::getNbrOfLetters()
{
	return NbrOfLetters;
}