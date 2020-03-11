#include <iostream>
#include <vector>
#include <memory>
#include <numeric>
#include <algorithm>

// Ex3 - template

void compute_2_1_1_a(const int* values, int nbrOfValues, int& sum, int& min, int& max)
{
    // todo: compute by index access using []
    // -> write result to sum, min, max
    min = values[0];
    for (int i = 0; i < nbrOfValues; i++){
        sum += values[i];
        if (max<values[i]){
            max = values[i];
        }
        if (min>values[i]){
            min = values[i];
        }
    }
}

void compute_2_1_1_b(const int* values, int nbrOfValues, int& sum, int& min, int& max)
{
    // todo: compute by pointer arithmetic
    // -> write result to sum, min, max
        min = *values;
    for (int i = 0; i < nbrOfValues; i++){
        sum += *(values+i);
        if (max<*(values+i)){
            max = *(values+i);
        }
        if (min>*(values+i)){
            min =*(values+i);
        }
    }
}

void compute_2_1_2(const std::unique_ptr<int[]>& values, int nbrOfValues, int& sum, int& min, int& max)
{
    // todo: compute by receiving smart pointer
    // -> write result to sum, min, max
    
    min = values[0];
    for (int i = 0; i < nbrOfValues; i++){
        sum += values[i];
        if (max<values[i]){
            max = values[i];
        }
        if (min>values[i]){
            min = values[i];
        }
    }

}

void compute_2_1_3(const std::vector<int>& values, int& sum, int& min, int& max)
{
    // todo: compute by receiving vector
    // -> write result to sum, min, max
    min = values[0];
    for (int i = 0; i < values.size(); i++){
        sum += values[i];
        if (max<values[i]){
            max = values[i];
        }
        if (min>values[i]){
            min = values[i];
        }
    }

}

/* todo:  Answer the questions under 2.2 -> as shorter as better :)

    What's wrong here? -> ...
    pointToAnInt = 9; accses the adress of the pointer and not the value
    right would be:
    *pointToAnInt = 9; now the value of the pointer will be set to 9

    Why and where does the program crash? -> ...
    Right at the start. The word new initialisied a pointer and not a int. int * pointToAnInt = new int
    One delet is enough because the second pointer is a copy of the frst one and the have the same adress.
    int main ()
{
    int * pointToAnInt = new int;
    int * pNumberCopy = pointToAnInt ;
    * pNumberCopy = 30;
    std :: cout << * pointToAnInt ;

    delete pointToAnInt ;
    return 0;
}


    Fix the function! -> ...
    Return should be a pointer array. Before the temp was just an int.
    int * allocateArray ( const int length ){
    int*  temp = new int [ length ];
    return temp;
}

    Hoopla! -> ...
    There was no value assigned to the 5 entry of the array. A random number is then the output.
    int array [4] { 0, 1, 2, 3 };
    for ( int count = 0; count <= 4; ++ count )
    std :: cout << array [ count ] << " ";
    return 0;

*/


int main ()
{
    // Testing your code with test input -> NO NEED TO PERFORM ANY INTERACTIVE USER INPUT

    // Generate test input -> DO NOT MODIFY :)
    int nbrOfValues = 5;

    // Three different containers
    int* arrValues = new int[nbrOfValues];
    std::unique_ptr<int[]> smartValues(new int[nbrOfValues]);
    std::vector<int> vecValues;

    // Filling the containers with identical data
    for(size_t i = 0; i < nbrOfValues; i++)
    {
        arrValues[i] = static_cast<int>(i);
        smartValues[i] = static_cast<int>(i);
        vecValues.push_back(static_cast<int>(i));
    }

    // arrValues, smartValues and vecValues, contain the values [0, 1, 2, 3, 4]
    // -> therefore SUM = 10, MIN = 0, MAX = 4

    int sum = 0; int min = 0; int max = 0;

    // testing if your code works correct -> DO NOT MODIFY :)

    compute_2_1_1_a(arrValues, nbrOfValues, sum, min, max);
    if( sum == 10 && min == 0 && max == 4 )
        std::cout << "2_1_1_a  ->  ok" << std::endl;
    else
        std::cout << "2_1_1_a  ->  failed" << std::endl;

    sum = 0; min = 0; max = 0;

    compute_2_1_1_b(arrValues, nbrOfValues, sum, min, max);
    if( sum == 10 && min == 0 && max == 4 )
        std::cout << "2_1_1_b  ->  ok" << std::endl;
    else
        std::cout << "2_1_1_b  ->  failed" << std::endl;

    sum = 0; min = 0; max = 0;

    compute_2_1_2(smartValues, nbrOfValues, sum, min, max);
    if( sum == 10 && min == 0 && max == 4 )
        std::cout << "2_1_2    ->  ok" << std::endl;
    else
        std::cout << "2_1_2    ->  failed" << std::endl;

    sum = 0; min = 0; max = 0;

    compute_2_1_3(vecValues, sum, min, max);
    if( sum == 10 && min == 0 && max == 4 )
        std::cout << "2_1_3    ->  ok" << std::endl;
    else
        std::cout << "2_1_3    ->  failed" << std::endl;


    // todo: Is there anything to delete? If so, please do it.
    delete[] arrValues;

    return 0;
}

/* If every thing works fine, you get following output:

            2_1_1_a  ->  ok
            2_1_1_b  ->  ok
            2_1_2    ->  ok
            2_1_3    ->  ok
*/

