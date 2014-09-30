#include <iostream>
#include <vector>
#include <map>

using namespace std;

// use a map to vector of char
// and use a dfs
// dfs, consider recursion first, because recursion is easier to write

void dfs(int index, vector<int> &digits, map<int, vector<char> > &dic, string ans,
            vector<string> &result) {
    if (index >= digits.size()) {
        result.push_back(ans);
        return;
    }
    
    int current_digit = digits[index];
    vector<char> current_dic = dic[current_digit];
    for (int i = 0; i < current_dic.size(); ++i) {
        dfs(index+1, digits, dic, ans+current_dic[i], result);
    }
}

vector<string> letter_combination (vector<int> digits) {
    map<int, vector<char> > dic;
    dic[2].push_back('a');
    dic[2].push_back('b');
    dic[2].push_back('c');
    dic[3].push_back('d');
    dic[3].push_back('e');
    dic[3].push_back('f');
    dic[4].push_back('g');
    dic[4].push_back('h');
    dic[4].push_back('i');
    dic[5].push_back('j');
    dic[5].push_back('k');
    dic[5].push_back('l');
    dic[6].push_back('m');
    dic[6].push_back('n');
    dic[6].push_back('o');
    dic[7].push_back('p');
    dic[7].push_back('q');
    dic[7].push_back('r');
    dic[7].push_back('s');
    dic[8].push_back('t');
    dic[8].push_back('u');
    dic[8].push_back('v');
    dic[9].push_back('w');
    dic[9].push_back('x');
    dic[9].push_back('y');
    dic[9].push_back('z');

    vector<string> result;
    dfs(0, digits, dic, "", result);
    return result;
} 

int main() {
    vector<int> digits {2, 3};
    vector<string> result = letter_combination(digits);
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << endl;
}



