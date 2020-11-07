#pragma once
#include "Segment.h"
#include <vector>

class Rectangle
{
private:
    Point _leftDownPoint;
    Point _rightUpperPoint; 
public:
    Point getLeftDownPoint();
    Point getRightUpperPoint();

    int getLeftDownPoint_X();
    int getLeftDownPoint_Y();
    int getRightUpperPoint_X();
    int getRightUpperPoint_Y();
    
    Rectangle(Point leftDownPoint, Point rightUpperPoint);
    ~Rectangle();
};

Rectangle::Rectangle(Point leftDownPoint, Point rightUpperPoint)
{
    this->_leftDownPoint = leftDownPoint;
    this->_rightUpperPoint = rightUpperPoint;
}


