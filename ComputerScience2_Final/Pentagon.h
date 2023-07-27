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

	Pentagon operator+(const Pentagon& P);
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

Pentagon Pentagon::operator+(const Pentagon& P) {
	Pentagon Pen;
	Pen.setApothemL(getApothemL() + P.apothemL);
	Pen.setSideL(getSideL() + P.sideL);
	return Pen;
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

// Calculates Area
int Pentagon::getArea()
{
	return ((2.5 * sideL) * apothemL);
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