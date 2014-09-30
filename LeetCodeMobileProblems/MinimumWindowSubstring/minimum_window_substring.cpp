#include <iostream>
#include <climits>
#include <string>
#include <queue>

using namespace std;

string find_window(string s, string t) {
    int result_size = INT_MAX;
    string result = "";
    int hash[256];
    bool exist[256];
    for (int i = 0; i < 256; ++i) {
        hash[i] = 0;
        exist[i] = false;
    }
    for (int i = 0; i < t.size(); ++i) {
        hash[(int)t[i]]++;
        exist[(int)t[i]] = true;
    }
   
    queue<int> index_q;

    for (int i = 0; i < s.size(); ++i) {
        bool new_result = false;
        char current_char = s[i];
        if (hash[current_char] > 0) {
            hash[current_char]--;
            index_q.push(i);
            new_result = true;
        } else {
            int first_index = index_q.front();
            if (s[first_index] == current_char) {
                index_q.pop();
                index_q.push(i);
                while (hash[s[index_q.front()]] < 0) {
                    hash[s[index_q.front()]]++;
                    index_q.pop();
                }
                new_result = true;
            } else { 
                if (exist[current_char]) {
                    hash[current_char]--;
                    index_q.push(i);
                }
            }
        }
        cout << endl;
        if (new_result) {
            bool complete = true;
            for (int i = 0; i < 256; ++i) {
                if (hash[i] > 0) {
                    complete = false;
                    break;
                }
            }
            if (complete) {
                int new_result_size = i - index_q.front() + 1;
                if (new_result_size < result_size) {
                    result_size = new_result_size;
                    result = s.substr(index_q.front(), new_result_size);
                }
            }
        }
    }
    return result;
    
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << "result: " << find_window(s, t) << endl;
}


