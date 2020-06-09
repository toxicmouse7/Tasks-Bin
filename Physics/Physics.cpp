#include <iostream>
#include <cmath>

using namespace std;

int comp(const void* arg1, const void* arg2)
{
	if (*(double*)arg1 > *(double*)arg2)
		return -1;
	if (*(double*)arg1 == *(double*)arg2)
		return 0;
	if (*(double*)arg1 < *(double*)arg2)
		return 1;
}

int main()
{
	double dif[] = { 40, 20, 80, 70 ,140,190,255,275,155,75,25 };
	//qsort(dif, 11, sizeof(double), comp);

	for (int i = 0; i < 11; i++)
	{
		cout << ((dif[i] * pow(10, 9)) / (1.44 * pow(10, 12) * 4.6 * pow(10, 4))) << endl;
	}
}