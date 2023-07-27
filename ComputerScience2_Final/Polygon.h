#pragma once
#include <iostream>
#include <string>
using namespace std;

class  Polygon {
protected:
	// variables
	string name;
	string description;
	int width, height;
	int difficulty;
	int points;
	string stgAnswer;

public:
	Polygon();
	Polygon(string name, string description, int difficulty, int points); // Constructor

	// Getters
	string getName();
	string getDescription();
	int getDifficulty();
	int getPoints();
	string getStgAnswer();

	// Setters
	void setName(string name);
	void setDescription(string description);
	void setDifficulty(int difficulty);
	void setPoints(int points);

	// Gets random numbers in a certain range
	int randomNbr(int highestNbr);
	// Randomly produces answers to the problem
	void Answers(int answer, int highestNbr);
};

// Constructors
Polygon::Polygon()
{

}

Polygon::Polygon(string name, string description, int difficulty, int points)
{
	this->name = name;
	this->description = description;
	this->difficulty = difficulty;
	this->points = points;
}

// Getters
string Polygon::getName()
{
	return name;
}
string Polygon::getDescription()
{
	return description;
}
int Polygon::getDifficulty()
{
	return difficulty;
}
int Polygon::getPoints()
{
	return points;
}

// Setters
void Polygon::setName(string name)
{
	this->name = name;
}
void Polygon::setDescription(string description)
{
	this->description = description;
}
void Polygon::setDifficulty(int difficulty)
{
	this->difficulty = difficulty;
}
void Polygon::setPoints(int points)
{
	this->points = points;
}

// Gets random numbers in a certain range
int Polygon::randomNbr(int highestNbr)
{
	return 	(rand() % (highestNbr + 1 - 1)) + 1;
}

// returns a string version of the answer
string Polygon::getStgAnswer()
{
	return stgAnswer;
}

// Randomly produces answers to the problem in a random way
void Polygon::Answers(int answer, int highestNbr)
{
	int counter = (rand() % (4 + 1 - 1)) + 1;


	if (counter == 1)
	{
		cout << "(A)" << answer << " (B)" << randomNbr(highestNbr) << " (C)" << randomNbr(highestNbr) << " (D)" << randomNbr(highestNbr) << endl;
		this->stgAnswer = "A";
	}
	else if (counter == 2)
	{
		cout << "(A)" << randomNbr(highestNbr) << " (B)" << answer << " (C)" << randomNbr(highestNbr) << " (D)" << randomNbr(highestNbr) << endl;
		this->stgAnswer = "B";
	}
	else if (counter == 3)
	{
		cout << "(A)" << randomNbr(highestNbr) << " (B)" << randomNbr(highestNbr) << " (C)" << answer << " (D)" << randomNbr(highestNbr) << endl;
		this->stgAnswer = "C";
	}
	else if (counter == 4)
	{
		cout << "(A)" << randomNbr(10) << " (B)" << randomNbr(10) << " (C)" << randomNbr(10) << " (D)" << answer << endl;
		this->stgAnswer = "D";
	}
	
}
