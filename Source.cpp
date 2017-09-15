#include <iostream>
using namespace std;
int main()
{
	int Matrix_1[2][2]; // Fixed 2 x 2 Sized Matrices...
	int Matrix_2[2][2]; // ...with user defined values
	int Matrix_3[2][2];
	int i, j, k; // Indices for loops
	cout << "Enter the values of the first matrix :" << endl << endl; // User Input for First Matrix
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << "Row " << i << " Column " << j << " : ";
			cin >> Matrix_1[i][j];
		}
	}
	cout << "\n\n\nEnter the values of the second matrix :" << endl << endl; // User Input for Second Matrix
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << "Row " << i << " Column " << j << " : ";
			cin >> Matrix_2[i][j];
		}
	}
	for (i = 0; i < 2; i++) // Matrix Multiplication Using Iterative Approach
	{
		for (j = 0; j < 2; j++)
		{
			Matrix_3[i][j] = 0;
			for (k = 0; k < 2; k++)
			{
				Matrix_3[i][j] += Matrix_1[i][k] * Matrix_2[k][j];
			}
		}
	}
	cout << "\n\n\nAnswer (Using Iterative Approach) :" << endl << endl; // Answer Display
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << Matrix_3[i][j] << "\t";
		}
		cout << "\n";
	}
	int m1, m2, m3, m4, m5, m6, m7; //Matrix Multiplication Using Strassen's Algorithm
	m1 = (Matrix_1[0][0] + Matrix_1[1][1]) * (Matrix_2[0][0] + Matrix_2[1][1]);
	m2 = (Matrix_1[1][0] + Matrix_1[1][1]) * Matrix_2[0][0];
	m3 = Matrix_1[0][0] * (Matrix_2[0][1] - Matrix_2[1][1]);
	m4 = Matrix_1[1][1] * (Matrix_2[1][0] - Matrix_2[0][0]);
	m5 = (Matrix_1[0][0] + Matrix_1[0][1]) * Matrix_2[1][1];
	m6 = (Matrix_1[1][0] - Matrix_1[0][0]) * (Matrix_2[0][0] + Matrix_2[0][1]);
	m7 = (Matrix_1[0][1] - Matrix_1[1][1]) * (Matrix_2[1][0] + Matrix_2[1][1]);

	Matrix_3[0][0] = m1 + m4 - m5 + m7;
	Matrix_3[0][1] = m3 + m5;
	Matrix_3[1][0] = m2 + m4;
	Matrix_3[1][1] = m1 - m2 + m3 + m6;

	cout << "\n\n\nAnswer (Using Strassen's Algorithm) :" << endl << endl; // Answer Display
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << Matrix_3[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << endl << endl;
	system("pause");
	return 0;
}
