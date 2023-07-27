#pragma once
#include <iostream>
#include <string>
#include "Polygon.h"
using namespace std;

class Pentagon : public Polygon {
protected:
	// Variables
	int apothemL;
	int sideL;

public:
	// Constructors
	Pentagon();
	Pentagon(int apothemL, int sideL);

	// Getters
	int getApothemL();
	int getSideL(); 
	int getArea();
	int getPerimeter();

	// Setters
	void setApothemL(int newApothemL);
	void setSideL(int newSideL);


	// Calculates Area
	int getArea(void)
	{
		return ((2.5 * sideL) * apothemL);
	}
};

// Constructors
Pentagon::Pentagon()
{

}

Pentagon::Pentagon(int sideL, int apothemL) : Polygon("Pentagon","Description",1,15)
{
	this->apothemL = apothemL;
	this->sideL = sideL;
}

Pentagon operator+(const Pentagon P) {
	Pentagon Pen;
	Pen.getApothemL = getApothemL() + P.getApothemL();
	Pen.getSideL = getSideL() + P.getSideL();

}

// Getters
int Pentagon::getSideL()
{
	return sideL;
}
int Pentagon::getApothemL()
{
	return apothemL;
}

// Setters
void Pentagon::setSideL(int newSideL)
{
	this->sideL = newSideL;
}
void Pentagon::setApothemL(int newApothemL)
{
	this->apothemL = newApothemL;
}

// Calculates Perimeter
int Pentagon::getPerimeter() {
	return sideL * 5;
}