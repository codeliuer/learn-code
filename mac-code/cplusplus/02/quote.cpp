#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int value = 0;
	int &qval = value;
	int& *pval = qval;

	return EXIT_SUCCESS;
}
