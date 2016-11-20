#include <iostream>


using namespace std;


void test(void)
{
	class B
	{
	public:
		B(void)
		{
			cout << "B\t";
		}

		~B(void)
		{
			cout << "~B\t";
		}
	};

	struct C
	{
		C(void)
		{
			cout << "C\t";
		}

		~C(void)
		{
			cout << "~C\t";
		}
	};

	struct D: B
	{
		D(void) 
		{
			cout << "D\t";
		}

		~D(void)
		{
			cout << "~D\t";
		}

		private:
			C c;
	};

	D d;
}


int
main(int argc, char *argv[])
{
	test();

	return EXIT_SUCCESS;
}
