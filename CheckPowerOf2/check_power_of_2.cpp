#include <iostream>

using namespace std;

bool check (int x)
{
    return (x && !(x&(x-1)));
}

int main()
{
    int a = 16;
    cout << check(a) << endl;
}
