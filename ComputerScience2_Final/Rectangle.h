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


	// Calculates Area
	int getArea(void)
	{
		return width * height;
	}
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

Rectangle operator+(const Rectangle R) {
	Rectangle Rec;
	Rec.getWidth = this->getwidth() + R.getWidth();
	Rec.getHeight = this->getHeight() + R.getHeight();
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