#include "GeneratorTests.h"

GeneratorTests::~GeneratorTests() = default;

GeneratorTests::GeneratorTests()
{
    srand(time(nullptr));
    _countOfRectangles_N = Randomizator(MIN_COUNT, MAX_COUNT);
    _countOfCoating_K = Randomizator(MIN_COUNT, MAX_COUNT);
    _rectanglesRoster = createRectanglesRoster(_countOfRectangles_N);
}

std::vector<Rectangle> GeneratorTests::createRectanglesRoster(int countRectangles)
{
    std::vector<Rectangle> newRectanlesRoster;
    for (int i = 0; i < countRectangles; i++)
    {
        newRectanlesRoster.push_back(createNewRectangle());
    }
}

Rectangle GeneratorTests::createNewRectangle()
{
    Point leftDownPoint = createNewPoint();
    Point rightUpperPoint = createNewPoint();
    return Rectangle(leftDownPoint, rightUpperPoint);
}

Point GeneratorTests::createNewPoint()
{
    Point newPoint;
    newPoint.x = Randomizator(MIN_COUNT, MAX_COUNT);
    newPoint.y = Randomizator(MIN_COUNT, MAX_COUNT);
    return newPoint;
}
