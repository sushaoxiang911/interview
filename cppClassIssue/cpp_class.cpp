#include <iostream>

using namespace std;

class my_class
{
    private:
        int a;
        char b;
        double c;
};
// the following code can be compiled, meaning that
// there are default constructor, default copy constructor
// and equality assignment in cpp
int main()
{
    my_class temp1;
    my_class temp2(temp1);
    my_class temp3 = temp1;
}
