#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <climits>
#include <set>

using namespace std;

// this way is to hold a set that keeps track of all the suffix that cannot be matched
// that is 
// we recursively check the suffix and if there is a specific suffix that we have already
// checked and found it is not matched
// we directly ignored

// In my opinion, that is not true
// since we will always go to the suffix and if in the end of the stack, we didn't find it
// the track here is no need to check again during the for loop

bool wordBreakHelper(string s,unordered_set<string> &dict,set<string> &unmatched,int mn,int mx) {  
    if(s.size() < 1) return true;  
    int i = mx < s.length() ? mx : s.length();  
    for(; i >= mn ; i--) {      
        string preffixstr = s.substr(0,i);  
        if(dict.find(preffixstr) != dict.end()) {  
            string suffixstr = s.substr(i);  
            if(unmatched.find(suffixstr) != unmatched.end())  
                continue;  
            else {  
                if(wordBreakHelper(suffixstr, dict, unmatched,mn,mx))  
                    return true;  
                else  
                    unmatched.insert(suffixstr);  
            }  
        }
    }
    return false;  
}  
bool wordBreak(string s, unordered_set<string> &dict) {  
    
    if(s.length() < 1) return true;  
    if(dict.empty()) return false;  
    unordered_set<string>::iterator it = dict.begin();  
    int maxlen=(*it).length(), minlen=(*it).length();  
    for(it++; it != dict.end(); it++) { 
        if((*it).length() > maxlen)  
            maxlen = (*it).length();  
        else if((*it).length() < minlen)  
            minlen = (*it).length();
    }
    set<string> unmatched;  
    return wordBreakHelper(s,dict,unmatched,minlen,maxlen);  
} 



// dp
// dp[i] keep tracks of if the str[0...i] can be segmented

// we can also use a trie tree to accelerate the searching process
struct trie_node {
    bool exist;
    trie_node* next[26];
};
//     root
//    i/  |g
//    1   0
//   s|   \o
//    1    0
//          \o
//           0
//            \d
//             1

// and then we start from the first index
// and go check the trie tree and mark all the existing end to true
// and when we go through the whole string
// for every index i that dp[i-1] is true
// we traverse the trie tree from index i and mark the string
// until we hit the end

bool word_break(string s, unordered_set<string> dict) {
    if (s.empty())
        return true;
    if (dict.empty())
        return false;
    
    int max_len = INT_MIN;
    int min_len = INT_MAX;
    for (auto it = dict.begin(); it != dict.end(); ++it) {
        int current_size = (*it).size();
        if (current_size > max_len)
            max_len = current_size;
        if (current_size < min_len)
            min_len = current_size;
    } 
    
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i - max_len + 1; j <= i - min_len + 1; ++j) {
            if (j < 0)
                continue;
            else {
                auto it = dict.find(s.substr(j, i - j + 1));
                if (dp[j] && it != dict.end()) {
                    dp[i+1] = true;
                    break;
                }
            }
        }
    }
    return dp[s.size()];
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
    cout << "result: " << word_break("twitterisagoodplace", dict) << endl;
}




 
