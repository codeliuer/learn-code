#include <stdlib.h>
#include <iostream>


using namespace std;


class coo
{
private:
    float x;
    float y;
    float z;
public:
    coo(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;

        cout << "structure" << endl;
    }
    ~coo(void)
    {
        cout << "free" << endl;
    }

    void print(void)
    {
        cout << "(" << this->x << " ," << this->y << " ," << this->z << ")" << endl; 
    }

    virtual void new_replace(void)
    {
        cout << "parent" << endl;
    }
};


class child : public coo
{
public:
    child(void) : coo(0, 0, 0)
    {
        cout << "child" << endl;
    }

    ~child(void)
    {
        cout << "free child" << endl;
    }

    void new_replace(void)
    {
        cout << "child" << endl;
    }
};



int
main(int argc, char *argv[])
{
    class coo c(1, 2, 3);
    c.print();

    coo *pch = new child();
    pch->new_replace();

    return EXIT_SUCCESS;
}
