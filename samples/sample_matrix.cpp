#include <iostream>
#include "utmatrix.h"

void main()
{
	TMatrix<int> m(3), m1(3), m2(3);

	for (int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++)
		{
			m[i][j - i] = 0;
		}

	cout << m << endl;
//	cout << m << endl << m1 << endl << m2 << endl;
//	m1 = m1 - m;
//	cout << m1 << endl;
}