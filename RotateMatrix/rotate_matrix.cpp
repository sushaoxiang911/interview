#include <iostream>

using namespace std;

void rotate (int** mtr, int n)
{
    for (int i = 0; i < n/2; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int temp = mtr[i][j];
            mtr[i][j] = mtr[n-1-i][j];
            mtr[n-1-i][j] = temp;
        }
    }
    for (int i = 0; i < n/2; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int temp = mtr[j][i];
            mtr[j][i] = mtr[j][n-1-i];
            mtr[j][n-1-i] = temp;
        }
    }
}


int main()
{
    int** matrix = new int* [4];
    for (int i = 0; i < 4; i++)
        matrix[i] = new int[4];
    int val = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matrix[i][j] = val;
            val++;
        }
    }
    rotate (matrix, 4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << matrix[i][j] << " ";
    }
    cout << endl;
}
