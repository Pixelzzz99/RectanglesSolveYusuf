#pragma once
#include "RectanglesSolve.h"
#include "GeneratorTests.h"
#include <utility>
#include <map>

class SolveVersion1 : public RectanglesSolve
{
private:
    int step = 0;
    std::map<std::pair<int, int>, int> _hasPoint;
    std::vector<Point> _allPoints;
    std::vector<Rectangle> _rectangles;
    void setRectanglesCoordinates(std::vector<Rectangle>);
    std::vector<Point> getIntersects(std::vector<Point>); 
    bool isIntersect(Segment a, Segment b);
    bool goodRectangle(Rectangle);
    bool CheckingForSuitablePointsOfRectangles(Rectangle, Rectangle);

public:
    SolveVersion1(GeneratorTests *);
    SolveVersion1(int, int, std::vector<Rectangle>);
    ~SolveVersion1() = default;
    int getSteps();
    void setSteps(int);
    int solve(std::vector<Rectangle> &) override;
};

