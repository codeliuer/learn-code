#include <iostream>


using namespace std;


class A
{
public:
    A()
    {
        cout << "A" << endl;
    }
    ~A()
    {
        cout << "~A" << endl;
    }

    virtual void func(void)
    {
        cout << "A func()" << endl;
    }
};

class B : public A
{
};


int main(int argc, char *argv[])
{

    return EXIT_SUCCESS;
}
