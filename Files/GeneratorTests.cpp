#include "GeneratorTests.h"

GeneratorTests::~GeneratorTests() = default;

GeneratorTests::GeneratorTests()
{
    srand(time(nullptr));
    _countOfRectangles_N = Randomizator(MIN_COUNT, MAX_COUNT);
    _countOfCoating_K = Randomizator(MIN_COUNT, _countOfRectangles_N);
    _rectanglesRoster = createRectanglesRoster(_countOfRectangles_N);
}

GeneratorTests::GeneratorTests(int n, int k)
{
    _countOfRectangles_N = n;
    _countOfCoating_K = k;
    _rectanglesRoster = createRectanglesRoster(_countOfRectangles_N);
}

int GeneratorTests::Randomizator(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

std::vector<Rectangle> GeneratorTests::createRectanglesRoster(int countRectangles)
{
    std::vector<Rectangle> newRectanlesRoster;
    for (int i = 0; i < countRectangles; i++)
    {
        newRectanlesRoster.push_back(createNewRectangle());
    }
    return newRectanlesRoster;
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


int GeneratorTests::getCountOfRectangles_N()
{
    return _countOfRectangles_N;
}

int GeneratorTests::getCountOfCoating_K()
{
    return _countOfCoating_K;
}

std::vector<Rectangle> GeneratorTests::getRectanglesRoster()
{
    return _rectanglesRoster;
}