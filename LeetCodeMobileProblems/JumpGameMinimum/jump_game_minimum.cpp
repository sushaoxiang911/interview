#include <iostream>
#include <vector>

using namespace std;

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

int main () {
    vector<int> jump {2, 3, 1, 1, 4};
    cout << "result: " << jump_game(jump) << endl;
}
