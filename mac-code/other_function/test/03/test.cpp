#include <iostream>

using namespace std;

class A
{
public:
	A(void)
	{
		cout << "A" << endl;
	}

	~A(void)
	{
		cout << "~A" << endl;
	}
};


class D
{
public:
	D(void)
	{
		cout << "D" << endl;
	}

	~D(void)
	{
		cout << "~D" << endl;
	}
};


class B : public D
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

private:
	A a;
};


int
main(int argc, char *argv[])
{
	B b;

	return EXIT_SUCCESS;
}
