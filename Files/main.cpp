#include <iostream>
#include "RectanglesSolve.h"
#include "SolveVersion1.h"

int main()
{
   
    SolveVersion1* Solve1 = new SolveVersion1(GeneratorTests());
    
    std::vector<Rectangle> emptyRoster;
    int answer = Solve1->solve(emptyRoster);

    std::cout<<answer<<std::endl;
    for (int i = 0; i < answer; i++)
    {
        emptyRoster[i].print();
    }
    system("pause > nul");
    return 0;
}