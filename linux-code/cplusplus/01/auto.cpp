#include <cstdlib>
#include <iostream>


using namespace std;


#define TO_STRING(a)        #a


int
main(int argc, char *argv[])
{
    auto a = 10;

    cout << TO_STRING(a) << "[" << a << "]" << endl;

    return EXIT_SUCCESS;
}
