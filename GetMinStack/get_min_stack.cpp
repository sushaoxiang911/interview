#include <iostream>
#include <stack>

using namespace std;

class min_stack
{
    private:
        stack <int> number;
        stack <int> minimum;

    public:
        void pop_value();
        int top_value();
        void push_value(int val);
        int get_min();
};

void min_stack :: pop_value()
{
    number.pop();
    minimum.pop();
}

int min_stack ::  top_value()
{
    return number.top();
}

void min_stack :: push_value (int val)
{
    number.push(val);
    if(!minimum.empty())
    {
        if (val < minimum.top())
        {
            minimum.push(val);
        }   
        else
        {
            minimum.push(minimum.top());
        }
    }
    else
    {
        minimum.push(val);
    }
}

int min_stack :: get_min()
{
    return minimum.top();
}

int main()
{
    min_stack my_stack;
    my_stack.push_value(4);
    my_stack.push_value(2);
    my_stack.push_value(4);
    my_stack.push_value(1);
    my_stack.push_value(3);
    cout << my_stack.get_min() << endl;
}








