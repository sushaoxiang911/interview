#include <iostream>

using namespace std;

void print (int** mtr, int row, int col)
{
    int rs = 0;
    int cs = 0;
    int re = col - 1;
    int ce = row - 1;
    while (1)
    {
        for (int i = rs; i <= re; i++)
            cout << mtr[cs][i] << " ";
        cs++;
        if (ce < cs)
            break;
        for (int i = cs; i <= ce; i++)
            cout << mtr[i][re] << " ";
        re--;
        if (re < rs)
            break;
        for (int i = re; i >= rs; i--)
            cout << mtr[ce][i] << " ";
        ce--;
        if (ce < cs)
            break;
        for (int i = ce; i >= cs; i--)
            cout << mtr[i][rs] << " ";
        rs++;
        if (re < rs)
            break;
    }
    cout << endl;
}


int main()
{
    int** matrix = new int* [4];
    for (int i = 0; i < 4; i++)
        matrix[i] = new int[5];
    int val = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = val;
            val++;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << matrix[i][j] << " ";
    }
    cout << endl;
    print (matrix, 4, 5);
}
