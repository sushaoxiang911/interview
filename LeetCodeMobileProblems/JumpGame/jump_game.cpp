#include <iostream>
#include <vector>

using namespace std;


// greedy, every time we have to guarantee that we can move to the further place
// step = max(step, A[i])
// when consider greedy, ask what is the sub-optimal solution and where we can find it
bool jump_game (vector<int> jump) {
    if (jump.empty())
        return true;
    int max_index = 0;

    for (int i = 0; i < jump.size(); ++i) {
        if (max_index >= jump.size()-1)
            return true;
        if (max_index == i && jump[i] == 0)
            return false;
        int temp_index = jump[i] + i;
        if (temp_index > max_index)
            max_index = temp_index;
    }
}

int main () {
    vector<int> jump {3, 2, 1, 0, 4};
    cout << "result: " << jump_game(jump) << endl;
}
