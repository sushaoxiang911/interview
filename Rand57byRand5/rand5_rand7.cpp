#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int rand5()
{
    return rand()%5;
}

int rand7()
{
    int a[][] = {{1, 2, 3, 4, 5}, 
                 {6, 7, 1, 2, 3}, 
                 {4, 5, 6, 7, 1},
                 {2, 3, 4, 5, 6},
                 {7, 0, 0, 0, 0}};
    int result = 0;
    while (result == 0)
    {
        int x = rand5();
        int y = rand5();
        result = a[x][y];
    }

}

int rand7_2()
{
    int val = 25;
    while (val >= 21)
    {
        int val = 5 * rand5() + rand5();
    }
    return val%7;
}


int main()
{
    srand(time(NULL));
    cout << rand7() << endl;
}



