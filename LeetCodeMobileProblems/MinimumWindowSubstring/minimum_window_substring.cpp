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
string find_window_2(string s, string t) {
    // simply use double cursor to do that
    int record[256];
    int current[256];
    // init
    for (int i = 0; i < 256; ++i) {
        record[i] = 0;
        current[i] = 0;
    }

    for (int i = 0; i < t.size(); ++i) 
        record[t[i]] ++;
    
    string result = "";
    int length = INT_MAX;

    int begin = 0;
    for (int end = 0; end < s.length(); ++end) {
        // if the current char is not in t
        // just ignore
        char current_char = s[end];
        if (record[current_char] == 0)
            continue;
        current[current_char]++;
        
        // check if we have a window that includes everything
        bool is_completed = true;
        for (int i = 0; i < 256; ++i) {
            if (current[i] < record[i]) {
                is_completed = false;
                break;
            }
        }
        // if completed, we can start to move the begin cursor
        if (is_completed) {
            while (1) {
                char begin_char = s[begin];
                if (record[begin_char] == 0) {
                    begin++;
                } else if (current[begin_char] > record[begin_char]) {
                    current[begin_char]--;
                    begin++;
                } else {
                    int current_length = end - begin + 1;
                    if (current_length < length) {
                        result = s.substr(begin, current_length);
                        length = result.size();
                    }
                    break;
                }
            }
        
        }
    }
    return result;
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << "result: " << find_window_2(s, t) << endl;
}


