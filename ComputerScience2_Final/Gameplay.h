#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "Polygon.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Pentagon.h"
using namespace std;

class Gameplay {
protected:
	// Variables
	string GameTitle;
	string GameDesc;
	int nbrOfSides;

public:
	// Constructor
	Gameplay();

	// Getters
	string getGameTitle();
	string getGameDesc();
	int getnbrOfSides();

	// Setters
	void setGameTitle(string newGameTitle);
	void setGameDesc(string newGameDesc);
	void setnbrOfSides(int newnbrOfSides);

	// Player Rolls dice
	int PlayerRoll(Player player);

	// Triangle Question Levels
	int QTriangleLevel1();
	int QTriangleLevel2();
	int QTriangleLevel3();

	// Rectangle Question Levels
	int QRectangleLevel1();
	int QRectangleLevel2();
	int QRectangleLevel3();

	// Pentagon Question Levels
	int QPentagonLevel1();
	int QPentagonLevel2();
	int QPentagonLevel3();

};

// Constructor
Gameplay::Gameplay()
{
	setGameTitle("Welcome to Geometry Math Game!");
	setGameDesc("Its a competive two player game where each player picks their own geometry math question "
		"to answer and depending on how difficult the question, depends on how much points you get!");
}

//Getters
// Title of the Game 
string Gameplay::getGameTitle()
{
	return GameTitle;
}
// The Description of the game
string Gameplay::getGameDesc()
{
	return GameDesc;
}
// Gets the amount of sides on a die
int Gameplay::getnbrOfSides()
{
	return nbrOfSides;
}

// Setters
// Sets the game title to whatever you like
void Gameplay::setGameTitle(string newGameTitle)
{
	this->GameTitle = newGameTitle;
}
// Set the game description
void Gameplay::setGameDesc(string newGameDesc)
{
	this->GameDesc = newGameDesc;
}
// Sets the amount of sides on the die
void Gameplay::setnbrOfSides(int newnbrOfSides)
{
	this->nbrOfSides = newnbrOfSides;
}

// Playera rolls the dice
int Gameplay::PlayerRoll(Player player)
{

	char Answer;
	bool isValid;

	do
	{
		isValid = false;

		try
		{
			cout << "Please roll to see who will go first.(Highest Goes First)" << endl;
			cout << player.getName() << " Roll First." << endl;
			cout << "(A) Roll" << endl;
			cin >> Answer;

			if (Answer != 'A')
			{
				throw invalid_argument("Invalid Letter\n");
			}
		}
		catch (invalid_argument& e)
		{
			cout << e.what();
			isValid = true;
		}

	} while (isValid == true);

	switch (Answer)
	{
	case 'A':
		player.RollDice(6);
		cout << player.getDiceNbr() << endl;
	default:
		break;
	}
	return player.getDiceNbr();
}

// Triangle Question Levels
int Gameplay::QTriangleLevel1()
{
	string Answer;
	int highestNbr = 3;
	Triangle tri1;
	tri1.setSide1(tri1.randomNbr(highestNbr));
	tri1.setSide2(tri1.randomNbr(highestNbr));
	tri1.setSide3(tri1.randomNbr(highestNbr));

	string stg1 = to_string(tri1.getSide1());
	string stg2 = to_string(tri1.getSide2());
	string stg3 = to_string(tri1.getSide3());

	tri1.setPoints(100);
	tri1.setDescription("Calculate the area of the triangle with the given sides a = " + stg1 + ", b = " + stg2 +", c = " + stg3 +".");

	cout << tri1.getDescription() << endl;
	tri1.Answers(tri1.getArea(), tri1.getArea() + 12);
	//cout << tri1.getStgAnswer() << endl;

	cin >> Answer;


	if (Answer == tri1.getStgAnswer())
	{
		cout << "+" << tri1.getPoints() << "pts" << endl;
		return tri1.getPoints();
	}
	else
	{
		cout << "WRONG" << endl;
	}

	return 0;
}
int Gameplay::QTriangleLevel2()
{
	string Answer;
	int highestNbr = 6;
	Triangle tri1;
	tri1.setSide1(tri1.randomNbr(highestNbr));
	tri1.setSide2(tri1.randomNbr(highestNbr));
	tri1.setSide3(tri1.randomNbr(highestNbr));

	string stg1 = to_string(tri1.getSide1());
	string stg2 = to_string(tri1.getSide2());
	string stg3 = to_string(tri1.getSide3());

	tri1.setPoints(200);
	tri1.setDescription("Calculate the area of the triangle with the given sides a = " + stg1 + ", b = " + stg2 + ", c = " + stg3 + ".");

	cout << tri1.getDescription() << endl;
	tri1.Answers(tri1.getArea(), tri1.getArea() + 15);
	//cout << tri1.getStgAnswer() << endl;

	cin >> Answer;


	if (Answer == tri1.getStgAnswer())
	{
		cout << "+" << tri1.getPoints() << "pts" << endl;
		return tri1.getPoints();
	}
	else
	{
		cout << "WRONG" << endl;
	}

	return 0;
}
int Gameplay::QTriangleLevel3()
{
	string Answer;
	int highestNbr = 9;
	Triangle tri1;
	tri1.setSide1(tri1.randomNbr(highestNbr));
	tri1.setSide2(tri1.randomNbr(highestNbr));
	tri1.setSide3(tri1.randomNbr(highestNbr));

	string stg1 = to_string(tri1.getSide1());
	string stg2 = to_string(tri1.getSide2());
	string stg3 = to_string(tri1.getSide3());

	tri1.setPoints(300);
	tri1.setDescription("Calculate the area of the triangle with the given sides a = " + stg1 + ", b = " + stg2 + ", c = " + stg3 + ".");

	cout << tri1.getDescription() << endl;
	tri1.Answers(tri1.getArea(), tri1.getArea() + 18);
	//cout << tri1.getStgAnswer() << endl;

	cin >> Answer;


	if (Answer == tri1.getStgAnswer())
	{
		cout << "+" << tri1.getPoints() << "pts" << endl;
		return tri1.getPoints();
	}
	else
	{
		cout << "WRONG" << endl;
	}

	return 0;
}

// Rectangle Question Levels
int Gameplay::QRectangleLevel1()
{
	string Answer;
	int highestNbr = 3;
	Rectangle rec;

	rec.setHeight(rec.randomNbr(highestNbr));
	rec.setWidth(rec.randomNbr(highestNbr));

	string stgH = to_string(rec.getHeight());
	string stgW = to_string(rec.getWidth());

	rec.setPoints(100);
	rec.setDescription("Calculate the area of the Square with the given height and width H = " + stgH + ", W = " + stgW + ".");
	
	cout << rec.getDescription() << endl;
	rec.Answers(rec.getArea(), rec.getArea() + 12);
	//cout << rec.getStgAnswer() << endl;

	cin >> Answer;

	if (Answer == rec.getStgAnswer())
	{
		cout << "+" << rec.getPoints() << "pts" << endl;
		return rec.getPoints();
	}
	else
	{
		cout << "WRONG" << endl;
	}

	return 0;

}
int Gameplay::QRectangleLevel2()
{
	string Answer;
	int highestNbr = 6;
	Rectangle rec;

	rec.setHeight(rec.randomNbr(highestNbr));
	rec.setWidth(rec.randomNbr(highestNbr));

	string stgH = to_string(rec.getHeight());
	string stgW = to_string(rec.getWidth());

	rec.setPoints(200);
	rec.setDescription("Calculate the area of the Square with the given height and width H = " + stgH + ", W = " + stgW + ".");

	cout << rec.getDescription() << endl;
	rec.Answers(rec.getArea(), rec.getArea() + 15);
	/*cout << rec.getStgAnswer() << endl;*/

	cin >> Answer;

	if (Answer == rec.getStgAnswer())
	{
		cout << "+" << rec.getPoints() << "pts" << endl;
		return rec.getPoints();
	}
	else
	{
		cout << "WRONG" << endl;
	}

	return 0;
}
int Gameplay::QRectangleLevel3()
{
	string Answer;
	int highestNbr = 9;
	Rectangle rec;

	rec.setHeight(rec.randomNbr(highestNbr));
	rec.setWidth(rec.randomNbr(highestNbr));

	string stgH = to_string(rec.getHeight());
	string stgW = to_string(rec.getWidth());

	rec.setPoints(300);
	rec.setDescription("Calculate the area of the Square with the given height and width H = " + stgH + ", W = " + stgW + ".");

	cout << rec.getDescription() << endl;
	rec.Answers(rec.getArea(), rec.getArea() + 18);
	//cout << rec.getStgAnswer() << endl;

	cin >> Answer;

	if (Answer == rec.getStgAnswer())
	{
		cout << "+" << rec.getPoints() << "pts" << endl;
		return rec.getPoints();
	}
	else
	{
		cout << "WRONG" << endl;
	}

	return 0;
}

// Pentagon Question Levels
int Gameplay::QPentagonLevel1()
{
	string Answer;
	int highestNbr = 3;
	Pentagon pen;

	pen.setApothemL(pen.randomNbr(highestNbr));
	pen.setSideL(pen.randomNbr(highestNbr));

	string stgA = to_string(pen.getApothemL());
	string stgS = to_string(pen.getSideL());

	pen.setPoints(100);
	pen.setDescription("Calculate the area of Penagon with the given apothem length and side length A = " + stgA + ", S = " + stgS + ".");

	cout << pen.getDescription() << endl;
	pen.Answers(pen.getArea(), pen.getArea() + 12);
	//cout << pen.getStgAnswer() << endl;

	cin >> Answer;

	if (Answer == pen.getStgAnswer())
	{
		cout << "+" << pen.getPoints() << "pts" << endl;
		return pen.getPoints();
	}
	else
	{
		cout << "WRONG" << endl;
	}

	return 0;

}
int Gameplay::QPentagonLevel2()
{
	string Answer;
	int highestNbr = 6;
	Pentagon pen;

	pen.setApothemL(pen.randomNbr(highestNbr));
	pen.setSideL(pen.randomNbr(highestNbr));

	string stgA = to_string(pen.getApothemL());
	string stgS = to_string(pen.getSideL());

	pen.setPoints(200);
	pen.setDescription("Calculate the area of Penagon with the given apothem length and side length A = " + stgA + ", S = " + stgS + ".");

	cout << pen.getDescription() << endl;
	pen.Answers(pen.getArea(), pen.getArea() + 15);
	//cout << pen.getStgAnswer() << endl;

	cin >> Answer;

	if (Answer == pen.getStgAnswer())
	{
		cout << "+" << pen.getPoints() << "pts" << endl;
		return pen.getPoints();
	}
	else
	{
		cout << "WRONG" << endl;
	}

	return 0;
}
int Gameplay::QPentagonLevel3()
{
	string Answer;
	int highestNbr = 9;
	Pentagon pen;

	pen.setApothemL(pen.randomNbr(highestNbr));
	pen.setSideL(pen.randomNbr(highestNbr));

	string stgA = to_string(pen.getApothemL());
	string stgS = to_string(pen.getSideL());

	pen.setPoints(300);
	pen.setDescription("Calculate the area of Pentagon with the given apothem length and side length A = " + stgA + ", S = " + stgS + ".");

	cout << pen.getDescription() << endl;
	pen.Answers(pen.getArea(), pen.getArea() + 18);
	//cout << pen.getStgAnswer() << endl;

	cin >> Answer;

	if (Answer == pen.getStgAnswer())
	{
		cout << "+" << pen.getPoints() << "pts" << endl;
		return pen.getPoints();
	}
	else
	{
		cout << "WRONG" << endl;
	}

	return 0;
}