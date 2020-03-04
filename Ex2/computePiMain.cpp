#include <iostream>
#include <random>
#include <cmath>

// Todo: 3.0 -> Implement the Pi computation
// You are free to add more files
double x, y, distance, ratio;
double in = 0;
int darts = 10;

int main ()
{
    std::cout << "How many darts shoud be thrown: ";
    std::cin >> darts;
    
    std :: random_device rd;
    std :: mt19937 mt(rd ());
    std :: uniform_real_distribution < double > dist (0.0 , 1.0) ;

    for ( int i =0; i <darts; ++i){

        x = dist(mt);
        y = dist(mt);
        distance = sqrt(pow(x, 2)+pow(y, 2));

        if (distance <= 1.0){
            in ++;
        }        
    }

    std :: cout << darts << " darts were thrown." << "\n";
    std :: cout << in << " darts are in the circle." << "\n";
    std :: cout << "Calculated Pi is: "<< 4*in/darts << "\n";

    return 0;
}