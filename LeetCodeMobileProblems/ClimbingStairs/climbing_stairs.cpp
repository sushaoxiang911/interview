#include <iostream>

using namespace std;

// remember how many ways of climbing n - 2 stairs
// and climbing n - 1 stairs
int find_ways_of_climbing_stairs (int number) {
    if (number == 0)
        return 1;
    if (number == 1)
        return 1;
    int two_steps_ago = 1;
    int one_steps_ago = 1;
    int result = 0;
    for (int i = 2; i <= number; ++i) {
        result = one_steps_ago + two_steps_ago;
        two_steps_ago = one_steps_ago;
        one_steps_ago = result;
    }
    return result;
}

int main() {
    cout << find_ways_of_climbing_stairs(4) << endl;
}
