#pragma once
#include <iostream>
#include <string>
using namespace std;

class Player {
private:
	// Variables
	string name;
	int diceNbr;
	int score;

public:
	// Constructors
	Player();
	Player(string name);

	// Getters
	string getName();
	int getScore();
	int getDiceNbr();

	// Setters
	void setName(string newName);
	void setScore(int newScore);
	void setDiceNbr(int newDiceNbr);

	// Rolls the dice
	void RollDice(int nbrOfSides);

};
// COnstructors
Player::Player()
{

}

Player::Player(string name)
{
	this->name = name;
}

// Getters
// Gets the name of the player
string Player::getName()
{
	return name;
}
// Gets the score of the player
int Player::getScore()
{
	return score;
}
// Gets the dice number
int Player::getDiceNbr()
{
	return diceNbr;
}

// Setters
// Set player name
void Player::setName(string newName)
{
	this->name = newName;
}
// Set the score of the player
void Player::setScore(int newScore)
{
	this->score = this->score + newScore;
}
// Sets the dice number
void Player::setDiceNbr(int newDiceNbr)
{
	this->diceNbr = newDiceNbr;
}
// Rolls dice
void Player::RollDice(int nbrOfSides)
{
	int newDiceNbr;
	srand(time(NULL));
	newDiceNbr = (rand() % (nbrOfSides + 1 - 1)) + 1;
	this->diceNbr = newDiceNbr;
}