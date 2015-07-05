
#include <iostream>
#include <exception>

#include "matrix.h"

using namespace std;

int main (void)
{
    try
    {
        Matrix m = Matrix("[ 1 10 1;1 2 3  ]");
        cout << m;
    }
    catch(exception const &e)
    {
        cerr << "Problem when analyzing entered string:\n\t" << e.what() << endl;
    }
    return 0;
}