#include <iostream>

using namespace std;


class A
{
public:
    A()
    {
        cout << "A constructor" << endl;
    }
    ~A()
    {
        cout << "A free" << endl;
    }
};


class B: public A
{
public:
    B()
    {
        cout << "B constructor" << endl;
    }
    ~B()
    {
        cout << "B free" << endl;
    }
};


int
main(int argc, char * argv[])
{
    B *b = new(B);
    delete b;

    return 0;
}
