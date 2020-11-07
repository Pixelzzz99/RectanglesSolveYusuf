#pragma once
#include <vector>
#include "Point.h"
#include "Segment.h"
#include "Rectangle.h"

class RectanglesSolve
{
private:
    int _countOfRectangles_N;
    int _countOfCoating_K;   
public:
    int getCountOfRectangle_N();
    void setCountOfRectangle_N(int);

    int getCountOfCoating_K();
    void setCountOfRectangle_K(int);

    virtual int solve(std::vector<Rectangle> &) = 0;
};

