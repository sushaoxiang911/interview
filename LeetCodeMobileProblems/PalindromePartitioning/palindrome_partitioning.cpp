#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dfs to do that
// just consider what is the one partition and if it is a palindrome, we can consider the 
// remain things


bool is_palindrome(string str) {
    int first = 0;
    int last = str.size() - 1;
    while (first <= last) {
        if (str[first] != str[last]) {
            break;
        } else {
            first++;
            last--;
        }
    }
    return (first > last);
}

void partitioning(vector<vector<string> > &result, string str, 
                    vector<string> &path) {
    if (str.size() <= 0) {
        result.push_back(path);
        return;
    }
    
    for (int i = 0; i < str.size(); ++i) {
        string current_partition = str.substr(0, i + 1);
        string remain = str.substr(i+1);
        if (is_palindrome(current_partition)) {
            path.push_back(current_partition);
            partitioning(result, remain, path);
            path.pop_back();
            
        }
    }

}


vector<vector<string> > palindrome_partitioning(string str) {
    vector<vector<string> > result;
    vector<string> path;
    path.clear();
    partitioning(result, str, path);
    return result;
}

int main() {
    string str = "abcba";
    vector<vector<string> > result = palindrome_partitioning(str);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j)
            cout << result[i][j] << " ";
        cout << endl;
    }
}



