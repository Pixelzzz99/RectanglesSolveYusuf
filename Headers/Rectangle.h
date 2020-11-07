#pragma once
#include "Segment.h"
#include <vector>
#include <iostream>

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
    void print();
    Rectangle(Point leftDownPoint, Point rightUpperPoint);
    ~Rectangle() = default;
};
