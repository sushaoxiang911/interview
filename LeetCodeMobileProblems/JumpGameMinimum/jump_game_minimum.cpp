#include <iostream>
#include <vector>

using namespace std;

// this takes O(n^2) 
int jump_game (vector<int> jump) {
    
    if (jump.empty())
        return 0;
    vector<int> dp(jump.size(), -1);
    dp[0] = 0;
    for (int i = 1; i < jump.size(); ++i) {
        int min_step = jump.size();
        for (int j = 0; j < i; j++) {
            if (dp[j] >= 0 && j + jump[j] >= i) {
                if (dp[j] + 1 < min_step)
                    min_step = dp[j] + 1;
            }       
        }
        if (min_step < jump.size())
            dp[i] = min_step;
    }
    return dp[dp.size()-1];
}


// O(n) solution
// when we iterate the array, we can achieve a place with a number of step
// and when we can have a farther place to achieve, we can always achieve that place by one more step
// 

int jump_game_2 (vector<int> jump) {
    if(jump.size() == 1)
        return 0;
    int max_distance = jump[0];
    int current_arrived = 0;
    int min_step = 0;
    for (int i = 1; i < jump.size(); ++i) {
        if (max_distance < i)
            return -1;
        if (current_arrived < i) {
            min_step++;
            current_arrived = max_distance;
            if (current_arrived >= jump.size() - 1)
                return min_step;
        }
        max_distance = max_distance > jump[i] + i ? max_distance : jump[i] + i;
    }
    return -1
}

int main () {
    vector<int> jump {2, 3, 1, 1, 4};
    cout << "result: " << jump_game_2(jump) << endl;
}
