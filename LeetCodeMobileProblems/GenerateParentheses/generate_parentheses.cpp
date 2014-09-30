#include <iostream>
#include <string>
#include <vector>

using namespace std;


// here consider what is a valid combination
// we totally have num '(' and num ')'
// if we have the number of '(' > the number of ')', we then can append a '(' or a ')'
// if we have the number of '(' ==  the number of ')', we can only append a '('
// until we use up all the '(' and ')' then we enter it into the result set

void generate_help(vector<string> &result, string current, int left_num, int right_num) {
    if (left_num == 0) {
        string temp = current;
        for (int i = 0; i < right_num; ++i)
            temp = temp + ")";
        result.push_back(temp);
        return;
    }
    if (left_num == right_num) {
        string temp = current + "(";
        generate_help(result, temp, left_num - 1, right_num);
    } else {
        string temp = current + "(";
        generate_help(result, temp, left_num - 1, right_num);
        temp = current + ")";
        generate_help(result, temp, left_num, right_num - 1);
    }
}

vector<string> generate (int num) {
    vector<string> result;
    string current = "";
    generate_help(result, current, num, num);
    return result;
}

int main() {
    vector<string> result = generate(3);
    cout << "result: " << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
}
