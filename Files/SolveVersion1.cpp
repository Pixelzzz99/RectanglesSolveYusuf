#include "SolveVersion1.h"

SolveVersion1::SolveVersion1(GeneratorTests *test)
{
    setCountOfRectangle_N(test->getCountOfRectangles_N());
    setCountOfRectangle_K(test->getCountOfCoating_K());
    setRectanglesCoordinates(test->getRectanglesRoster());
}

SolveVersion1::SolveVersion1(int count_n, int count_k, std::vector<Rectangle> rectangles)
{
    setCountOfRectangle_N(count_n);
    setCountOfRectangle_K(count_k);
    setRectanglesCoordinates(rectangles);
}

void SolveVersion1::setRectanglesCoordinates(std::vector<Rectangle> rectanglesCoordinates)
{
    for (int i = 0; i < getCountOfRectangle_N(); i++)
    {
        _rectangles.push_back(rectanglesCoordinates[i]);
    }
}

int SolveVersion1::solve(std::vector<Rectangle> &coordinateRectangles)
{
    _allPoints = getIntersects(_allPoints);
    for (int i = 0; i < _allPoints.size(); i++)
    {
        for (int j = 0; j < _allPoints.size(); j++)
        {
            step++;
            Point A, B, C, D;
            A = _allPoints[i];
            C = _allPoints[j];
            B.x = C.x;
            B.y = A.y;
            D.x = A.x;
            D.y = C.y;
            if (!_hasPoint.count({B.x, B.y}) || !_hasPoint.count({D.x, D.y}) || A.x >= C.x || A.y >= C.y)
                continue;
            if (goodRectangle({A, C}))
            {
                coordinateRectangles.push_back({A, C});
            }
        }
    }
    return coordinateRectangles.size();
}

std::vector<Point> SolveVersion1::getIntersects(std::vector<Point> allPoints)
{
    std::vector<Segment> verticalSegments;
    std::vector<Segment> horizontalSegments;
    int step = 0;

    for (int i = 0; i < getCountOfRectangle_N(); i++)
    {
        step++;
        verticalSegments.push_back({{_rectangles[i].getLeftDownPoint()},
                                    {_rectangles[i].getLeftDownPoint_X(), _rectangles[i].getRightUpperPoint_Y()}});
        horizontalSegments.push_back({{_rectangles[i].getLeftDownPoint()},
                                      {_rectangles[i].getRightUpperPoint_X(), _rectangles[i].getLeftDownPoint_Y()}});
        verticalSegments.push_back({{_rectangles[i].getRightUpperPoint_X(), _rectangles[i].getLeftDownPoint_Y()},
                                    _rectangles[i].getRightUpperPoint()});
        horizontalSegments.push_back({{_rectangles[i].getLeftDownPoint_X(), _rectangles[i].getRightUpperPoint_Y()},
                                      _rectangles[i].getRightUpperPoint()});
    }

    for (int i = 0; i < horizontalSegments.size(); i++)
    {
        for (int j = 0; j < verticalSegments.size(); j++)
        {
            step++;

            if (isIntersect(horizontalSegments[i], verticalSegments[j]))
            {
                Point pointIntersect;
                pointIntersect.x = verticalSegments[j].leftPoint.x;
                pointIntersect.y = horizontalSegments[i].leftPoint.y;
                if (!_hasPoint.count({pointIntersect.x, pointIntersect.y}))
                {
                    _hasPoint[{pointIntersect.x, pointIntersect.y}] = true;
                    allPoints.push_back(pointIntersect);
                }
            }
        }
    }

    
    return allPoints;
}

bool SolveVersion1::isIntersect(Segment a, Segment b)
{
    return ((a.leftPoint.x <= b.rightPoint.x) &&
            (b.leftPoint.x <= a.rightPoint.x) &&
            (b.leftPoint.y <= a.leftPoint.y) &&
            (a.leftPoint.y <= b.rightPoint.y));
}

bool SolveVersion1::goodRectangle(Rectangle someRectangle)
{
    int count = 0;
    for (int i = 0; i < getCountOfRectangle_N(); i++)
    {
         step++;
        if (CheckingForSuitablePointsOfRectangles(someRectangle, _rectangles[i]))
        {
            count++;
        }
    }
    return count >= getCountOfCoating_K();
}

bool SolveVersion1::CheckingForSuitablePointsOfRectangles(Rectangle A, Rectangle B)
{
    return (B.getLeftDownPoint_X() <= A.getLeftDownPoint_Y() &&
            A.getRightUpperPoint_X() <= B.getRightUpperPoint_X() &&
            B.getLeftDownPoint_Y() <= A.getLeftDownPoint_Y() &&
            A.getRightUpperPoint_Y() <= B.getRightUpperPoint_Y());
}

int SolveVersion1::getSteps()
{
    return step;
}

void SolveVersion1::setSteps(int steps)
{
    this->step = steps;
}
