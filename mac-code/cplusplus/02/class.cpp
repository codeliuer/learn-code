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
public:
    B()
    {
        cout << "B" << endl;
    }
    ~B()
    {
        cout << "~B" << endl;
    }

    virtual void func(void)
    {
        cout << "B func()" << endl;
    }
};


int main(int argc, char *argv[])
{
    A *pa = new B();

    return EXIT_SUCCESS;
}
