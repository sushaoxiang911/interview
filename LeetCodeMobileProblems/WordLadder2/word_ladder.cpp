#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

struct element {  
    string str;  
    vector<string> path;  
    set<string> hash;  
};


// bfs guarantees taht it is a shortest path
public vector<vector<string> > findLadders (string start, string end, set<string> dict) {  

    vector<vector<string> > result; 
    vector<string> path; 
    set<string> hash; 
    if(start.length() != end.length()) {  
        return result;  
    }  
    queue<element> q;  
    path.push(start);  
    hash.insert(start);  
    element node;
    node.str = start;
    node.path = path;
    node.hash = hash;
    int min_length = -1;  
    q.push(node);  
    while(!q.empty()) {  
        node = q.pop();  
        string str = node.str;  
        for(int i=0; i<str.length(); i++) {  
            
            string new_str = str;

            for(int ch = 'a'; ch <= 'z'; ch++) {  
                if (new_str[i] == ch) {  
                    continue;  
                }
                new_str[i] = ch;  
        
                if(new_str == end) {  
                    path = node.path;  
                    path.push_back(newWord);  
                    if(min_length==-1) {  
                        min_length = path.size();  
                    }  
                    if(path.size() > min_length) {  
                        return result;  
                    } else {
                        result.push_back(path);  
                        continue;  
                    }  
                } else {
                    auto dict_it = dict.find(new_str);
                    auto hash_it = node.hash.find(new_str);
                    if(dict_it != dict.end() && hash_it != node.hash.end()) {  
                        path = node.path;
                        hash = node.hash;
                        path.push_back(new_str);  
                        hash.insert(new_str);  
                        element new_node;
                        new_node.str = new_str;
                        new_node.path = path;
                        new_node.hash = hash; 
                        q.push(new_node);  
                    }  
                }  
            }  
        }  
    }  
    return result;  
}  
