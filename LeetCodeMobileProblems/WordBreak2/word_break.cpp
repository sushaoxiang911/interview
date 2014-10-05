#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <climits>
using namespace std;


// change the dp to a vector<string> keep track all the possible answer

vector<string> word_break(string s, unordered_set<string> dict) {
    vector<string> result;
    if (s.empty()) {
        result.push_back("");
        return result;
    }
    if (dict.empty())
        return result;
    
    int max_len = INT_MIN;
    int min_len = INT_MAX;
    for (auto it = dict.begin(); it != dict.end(); ++it) {
        int current_size = (*it).size();
        if (current_size > max_len)
            max_len = current_size;
        if (current_size < min_len)
            min_len = current_size;
    }

    vector<vector<string> > dp(s.size() + 1);
    dp[0].push_back("");
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i - max_len + 1; j <= i - min_len + 1; ++j) {
            if (j < 0)
                continue;
            else {
                string suffix = s.substr(j, i - j + 1);
                auto it = dict.find(suffix);
                if (!dp[j].empty() && it != dict.end()) {
                    for (int k = 0; k < dp[j].size(); ++k) {
                        string temp = dp[j][k];
                        temp += suffix;
                        temp += " ";
                        dp[i+1].push_back(temp);
                    }
                }
            }
        }
    }
    result = dp[s.size()];
    for (int i = 0; i < result.size(); ++i) {
        result[i] = result[i].substr(0, result[i].size() - 1);
    }
    return result;
}

int main() {
    unordered_set<string> dict;
    dict.insert("twitter");
    dict.insert("twit");
    dict.insert("ter");
    dict.insert("is");
    dict.insert("i");
    dict.insert("a");
    dict.insert("good");
    dict.insert("place");
    dict.insert("goodplace");
    vector<string> result = word_break("twitterisagoodplace", dict);
    cout << "result: " << endl;
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << endl;
}

