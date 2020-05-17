#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	double res;
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
649242
	};
	double ln[] = { 1.40625e+16,
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
0
	};
	vector<int> myvec = { 48693 };
	vector<double> myvec1 = { 51891e+10 };
	double N0 = 25e+15;

	for (int i = 0; i < 13; i++)
		myvec1.push_back(myvec1[i] + 103782e+10);

	for (int i = 0; i < 13; i++)
		myvec.push_back(myvec[i] + 46196);

	

	for (int i = 0; i < 13; i++)
	{
		res = myvec1[i] / (N0 * myvec[i]);
		cout << V[i] << ";" << res << endl;
	}


	return 0;
}