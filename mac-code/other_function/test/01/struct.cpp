#include <iostream>

using namespace std;

class A
{
public:
	A(void)
	{
		printf("A\n");
	}
	 
	~A(void)
	{
		printf("~A\n");
	}
};


class B: public A
{
public:
	B(void)
	{
		cout << "B" << endl;
	}

	~B(void)
	{
		cout << "~B" << endl;
	}
};


int
main(int argc, char *argv[])
{
	B b;

	return EXIT_SUCCESS;
}
