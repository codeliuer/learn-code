#include <iostream>
#include <stdlib.h>


using namespace std;


class parent
{
private:
    int x;
public:
    parent(int x)
    {
        cout << "parent new" << endl;
    }
    ~parent(void)
    {
        cout << "parent delete" << endl;
    }

    virtual void replace(void)
    {
        cout << "parent replace" << endl;
    }
};


class child : public parent
{
private:
    int x;
public:
    child(void) : parent(0)
    {
        cout << "child new" << endl;
    }
    ~child(void)
    {
        cout << "child delete" << endl;
    }

    void replace(void)
    {
        cout << "child replace" << endl;
    }
};


int
main(int argc, char *argv[])
{
    child *pa = new child();
    ((parent *)pa)->replace();

    delete pa;

    return EXIT_SUCCESS;
}
