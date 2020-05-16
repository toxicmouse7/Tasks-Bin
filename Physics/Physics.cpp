#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double res;
	double N[] = { 1.40625e+16,
1.21875e+16,
9.875e+15,
7.5e+15,
4.6875e+15,
2.8125e+15,
1.625e+15,
9.375e+14,
6.875e+14,
5e+14,
9.375e+13,
5e+13,
0 };

	double V[] = { 48693.1,
224806,
287645,
338914,
382665,
423306,
461316,
497061,
530923,
562822,
592775,
621652,
649242};

	for (int i = 0; i < 13; i++)
		cout << N[i] << ";" << V[i] << endl;

	return 0;
}