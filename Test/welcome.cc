
#include <iostream>
#include <exception>

#include "matrix.h"

using namespace std;

int main (void)
{
    try
    {
        Matrix m1 = Matrix("[1 2 3]");
        Matrix m2 = Matrix("[2 4 6]");
        calculType_t d(2.);
        cout << d - m1;
    }
    catch(exception const &e)
    {
        cerr << "Problem when analyzing entered string:\n\t" << e.what() << endl;
    }
    return 0;
}