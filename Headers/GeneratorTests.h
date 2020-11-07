#pragma once
#include "Rectangle.h"
#include <ctime>
#include <cstdlib>

class GeneratorTests
{
private:
    int MIN_COUNT = 1;
    int MAX_COUNT = 100;

    int _countOfRectangles_N;
    int _countOfCoating_K;
    std::vector<Rectangle> _rectanglesRoster;
    int Randomizator(int min, int max);
    std::vector<Rectangle> createRectanglesRoster(int);
    Rectangle createNewRectangle();
    Point createNewPoint();

public:
    GeneratorTests();
    ~GeneratorTests();

    int getCountOfRectangles_N();
    int getCountOfCoating_K();
    std::vector<Rectangle> getRectanglesRoster();
};

