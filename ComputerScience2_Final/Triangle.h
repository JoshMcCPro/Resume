#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "Polygon.h"
using namespace std;

class Triangle : public Polygon {
protected:
	// variables
	int side1, side2, side3;
public:
	// Constructors
	Triangle();
	Triangle(int side1, int side2, int side3);

	// Getters
	int getSide1();
	int getSide2();
	int getSide3();
	int getArea();
	int getPerimeter();

	// Setters
	void setSide1(int side1);
	void setSide2(int side2);
	void setSide3(int side3);


	// Calculates Area
	int getArea(void) {
		int p = getPerimeter();
		return sqrt(p * (p - side1) * (p - side2) * (p - side3));
	}

};

// Constructors
Triangle::Triangle()
{

}

Triangle::Triangle(int side1, int side2, int side3) : Polygon("Triangle","Description", 1, 100)
{
	this->side1 = side1;
	this->side2 = side2;
	this->side3 = side3;
}

Triangle operator+(const Triangle t) {
	Triangle tri;
	tri.getSide1 = getSide1() + t.getSide1();
	tri.getSide2 = getSide2() + t.getSide2();
	tri.getSide3 = getSide3() + t.getSide3();
}

// Getters
int Triangle::getSide1()
{
	return side1;
}
int Triangle::getSide2()
{
	return side2;
}
int Triangle::getSide3()
{
	return side3;
}

// Setters
void Triangle::setSide1(int side1)
{
	this->side1 = side1;
}
void Triangle::setSide2(int side2)
{
	this->side2 = side2;
}
void Triangle::setSide3(int side3)
{
	this->side3 = side3;
}

// Calculates perimeter
int Triangle::getPerimeter() {
	return side1 + side2 + side3;
}