#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>

using namespace std;

// use bfs to do that
// it is the shortest path


int word_ladder(string start, string end, set<string> dict) {
    if (start == end)
        return 1;
    
    queue<string> q;
    map<string, int> m;
    
    q.push(start);
    m.insert(pair<string, int> (start, 1));
    
    while (!q.empty()) {
        string current_str = q.front();
        auto it = m.find(current_str);
        int current_step = it -> second;
        q.pop();
        for (int i = 0; i < current_str.size(); ++i) {
            for (int j = 'a'; j <= 'z'; ++j) {
                string new_str = current_str;
                new_str[i] = j;
                if (new_str == end)
                    return current_step + 1;
                auto dict_it = dict.find(new_str);
                if (dict_it != dict.end()) {
                    auto it = m.find(new_str);
                    if (it == m.end()) {
                        q.push(new_str);
                        m.insert(pair<string, int> (new_str, current_step + 1));
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");
    
    cout << "result: " << word_ladder("hit", "cog", dict) << endl;
}
