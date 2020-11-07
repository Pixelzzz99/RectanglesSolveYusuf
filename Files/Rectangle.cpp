#include "Rectangle.h"

Point Rectangle::getLeftDownPoint()
{
    return _leftDownPoint;
}

Point Rectangle::getRightUpperPoint()
{
    return _rightUpperPoint;
}

int Rectangle::getLeftDownPoint_X()
{
    return _leftDownPoint.x;
}

int Rectangle::getLeftDownPoint_Y()
{
    return _leftDownPoint.y;
}

int Rectangle::getRightUpperPoint_X()
{
    return _rightUpperPoint.x;
}

int Rectangle::getRightUpperPoint_Y()
{
    return _rightUpperPoint.y;
}

Rectangle::Rectangle(Point leftDownPoint, Point rightUpperPoint)
{
    this->_leftDownPoint = leftDownPoint;
    this->_rightUpperPoint = rightUpperPoint;
}


void Rectangle::print()
{
    std::cout << _leftDownPoint.x << " " << _leftDownPoint.y << " " << _rightUpperPoint.x << " " << _rightUpperPoint.y << std::endl;
}

