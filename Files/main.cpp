#include <iostream>
#include "RectanglesSolve.h"
#include "SolveVersion1.h"

int main()
{
    std::vector<int> pointsValue = {1, 1, 10, 10, 2, 2, 8, 8, 3, 3, 7, 7, 4, 4, 6, 6, 2, 5, 6, 8};
    std::vector<Rectangle> RectangleRoster;
    for (int i = 0; i < pointsValue.size(); i+=4)
    {
        Point lol;
        lol.x = pointsValue[i];
        lol.y = pointsValue[i+1];
        Point kek;
        kek.x = pointsValue[i+2];
        kek.y = pointsValue[i+3];

        Rectangle rec(lol, kek);
        RectangleRoster.push_back(rec);
    }

    GeneratorTests *test = new GeneratorTests(5, 2, RectangleRoster);
    SolveVersion1 *Solve1 = new SolveVersion1(test);

    std::vector<Rectangle> emptyRoster;

    unsigned int time_start = clock();
    int answer = Solve1->solve(emptyRoster);
    unsigned int time_end = clock();
    double time = (double)(time_end - time_start) / CLOCKS_PER_SEC;
    double stepsOnTime = Solve1->getSteps() / time;

    std::vector<Rectangle> rectanglesCoordinates = test->getRectanglesRoster();

    std::cout << "Rectangles Coordinates: " << std::endl;
    for (Rectangle r : rectanglesCoordinates)
    {
        r.print();
    }
    std::cout << std::endl;
    std::cout << answer << std::endl;

    for (int i = 0; i < answer; i++)
    {
        emptyRoster[i].print();
    }

    std::cout << "Time: " << time << std::endl;
    std::cout << "Steps: " << Solve1->getSteps() << std::endl;
    std::cout << "Steps On Time: " << stepsOnTime << std::endl;
    std::cout << std::endl;

    delete test;
    delete Solve1;

    system("pause > nul");
    return 0;
}