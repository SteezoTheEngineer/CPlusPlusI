#include <iostream>
#include <vector>

#include "shape.h"


using namespace std;

int main()
{
    Triangle t1(1 ,2);
    Triangle t2(3 ,4);
    Triangle t3(5 ,6);
    Square s1 (1);
    Square s2 (2);
    Square s3 (3);
    Circle c1 (1);
    Circle c2 (2);
    Circle c3 (3);

    vector<Shape*> shapeVec{ &t1, &t2 , &t3 , &s1 , &s2 , &s3 , &c1 , &c2 , &c3};
    for (const auto &element : shapeVec) {
        element->report();
    }

    return 0;
}
