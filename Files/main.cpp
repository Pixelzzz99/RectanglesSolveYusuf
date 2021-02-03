#include <iostream>
#include "RectanglesSolve.h"
#include "SolveVersion1.h"

int main()
{
    for (int n = 10; n < 1000; n += 10)
    {

        GeneratorTests *test = new GeneratorTests(n, 10);
        SolveVersion1 *Solve1 = new SolveVersion1(test);

        std::vector<Rectangle> emptyRoster;

        unsigned int time_start = clock();
        int answer = Solve1->solve(emptyRoster);
        unsigned int time_end = clock();
        double time = (double)(time_end - time_start) / CLOCKS_PER_SEC;
        double stepsOnTime = Solve1->getSteps() / time;

        std::cout << answer << std::endl;
        /*
        for (int i = 0; i < answer; i++)
        {
            emptyRoster[i].print();
        }
        */

        std::cout << "Time: " << time << std::endl;
        std::cout << "Steps: " << Solve1->getSteps() << std::endl;
        std::cout << "Steps On Time: " << stepsOnTime << std::endl;
        std::cout << std::endl;
        delete test;
        delete Solve1;
    }
    system("pause > nul");
    return 0;
}