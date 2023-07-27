#pragma once
#include <iostream>
#include <string>
#include "Polygon.h"
using namespace std;

class Rectangle : public Polygon {
private:
	int width;
	int height;
public:
	//Constructors
	Rectangle();
	Rectangle(int width, int height);

	// Getters
	int getWidth();
	int getHeight();
	int getArea();
	int getPerimeter();

	// Setters
	void setWidth(int width);
	void setHeight(int height);

	Rectangle operator+(const Rectangle& R);
};

// Constructors
Rectangle::Rectangle()
{

}

Rectangle::Rectangle(int width, int height) : Polygon("Rectangle", "Description", 1, 10)
{
	this->width = width;
	this->height = height;
}

Rectangle Rectangle::operator+(const Rectangle& R) {
	Rectangle Rec;
	Rec.setWidth(getWidth() + R.width);
	Rec.setHeight(getHeight() + R.height);
	return Rec;
}

// Getters
int Rectangle::getWidth()
{
	return width;
}
int Rectangle::getHeight()
{
	return height;
}

// Calculates Area
int Rectangle::getArea()
{
	return this->width * this->height;
}

// Setters
void Rectangle::setWidth(int width)
{
	this->width = width;
}
void Rectangle::setHeight(int height)
{
	this->height = height;
}

// Calculates Perimeter
int Rectangle::getPerimeter() {
	return (width + height) * 2;
}