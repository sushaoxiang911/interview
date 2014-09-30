#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// dp
// actually we can sort the candidates, and every state we have an additonal num to keep track
// the index of the biggest num inside this ans and then next time we go through the candidate
// can starting from this index
vector<vector<int> > find_combinations (vector<int>candidates, int target) {
    vector<vector<vector<int> > > dp(target + 1);
    for (int i = 1; i <= target; ++i) {
        for (int j = 0; j < candidates.size(); ++j) {
            int current_candidate = candidates[j];
            if (i - current_candidate < 0)
                continue;
            if (i - current_candidate == 0) {
                vector<int> temp_result;
                temp_result.push_back(current_candidate);
                dp[i].push_back(temp_result);
            }
            if (i - current_candidate > 0) {
                vector<vector<int> > last_result_set = dp[i - current_candidate];
                if (last_result_set.empty()) {
                    continue;
                } else {
                    for (int k = 0; k < last_result_set.size(); ++k) {
                        vector<int> last_result = last_result_set[k];
                        if (current_candidate < last_result[last_result.size() - 1]) {
                            continue;
                        }
                        vector<int> temp_result = last_result;
                        temp_result.push_back(current_candidate);
                        dp[i].push_back(temp_result);
                    }
                }
            }
        }
    }
    return dp[target];
}


// use recursion to find
// if there is search, recursion is always working

// every state contains the current used candidates (partial solution), current index,
// the sum of the partial solution

// and the way to transfer to next state is consider how many kth candidate should i use
void recursion(vector<vector<int> >&ans, vector<int> &candidates, vector<int> &num, int k, int sum, int target) {
    // if we iterate to a num that is bigger than n-1 or the partial sum has already bigger than
    // sum, return
    if (k >= candidates.size() || sum > target)
        return;

    int i = 0;
    while (1) {
        if (sum > target)
            break;
        if (sum == target) {
            ans.push_back(num);
        } else { 
            recursion(ans, candidates, num, k+1, sum, target);
        }
        num.push_back(candidates[k]);
        sum += candidates[k];
        ++i;
    }
    while (i--) {
        num.pop_back();
    }
}


vector<vector<int> > find_combinations_2 (vector<int> candidates, int target) {
    // sort the candidates to guarantee that all results are sorted
    // and there is no duplicate
    sort(candidates.begin(), candidates.end());
    vector<vector<int> >ans;
    // current answer
    vector<int> num;
    int sum = 0;
    recursion(ans, candidates, num, 0, sum, target);
    return ans;
}



// referred from others
// this way is using dp mark all the path to be boolean 1
// then do a dfs to find the path
// my ways is always keep the path inside

vector<vector<int> > find_combinations_3(vector<int> &can, int target) {  
    // Note: The Solution object is instantiated only once and is reused by each test case.  
    sort(can.begin(), can.end());  
    int k = 0;  
    while(k < can.size() && can[k] <= target)  
        k++;  
    if(k <= 0)  
        return vector<vector<int> >();  
    vector<vector<bool> > dp(k, vector<bool>(target+1, false));  
    for(int i = 0; i <= target; i++)  
        if(i % can[0] == 0)  
            dp[0][i] = true;  
    for(int i = 1; i < k; i++){  
        for(int j = 0; j < can[i]; j++)  
            dp[i][j] = dp[i-1][j];  
        for(int j = can[i]; j <= target; j++)  
            dp[i][j] = dp[i-1][j] || dp[i][j-can[i]];  
    }  
    vector<vector<int> > ans;  
    vector<int> path;  
    create_path(ans, path, k-1, target, dp, can);  
    return ans;  
}  
void create_path(vector<vector<int> >& ans, vector<int>& path, int k, int tar, vector<vector<bool> >& dp, vector<int>& can) {  
    // for non-descending purpose
     if(tar == 0){  
        reverse(path.begin(), path.end());  
        ans.push_back(path);  
        reverse(path.begin(), path.end());  
        return;  
    }  
    if(k < 0 || !dp[k][tar])  
        return ;
    // follow dp's true path to find the result
    // means we dont need kth candidate to form the solution
    if(k > 0 && dp[k-1][tar])  
        create_path(ans, path, k-1, tar, dp, can); 
    // we use the kth candidate to form the solution 
    if (tar >= can[k] && dp[k][tar-can[k]]){  
        path.push_back(can[k]);  
        create_path(ans, path, k, tar - can[k], dp, can);  
        path.pop_back();  
    }  
} 

int main() {
    vector<int> candidates {1, 2, 3, 6, 7};
    vector<vector<int> > result = find_combinations (candidates, 7);
    cout << "result: " << endl;
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
