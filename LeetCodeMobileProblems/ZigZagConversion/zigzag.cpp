#include <iostream>
#include <string>

using namespace std;

string conversion(string str, int n) {
    if (str == "")
        return "";
    string result = "";
    int reoccur = n + n - 2;
   
    // iterate with row number 
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            for (int j = 0; j < str.size(); ++j) {
                if (j % reoccur == 0)
                    result += str[j];
            }
        } else if (i == n - 1) {
            for (int j = 0; j < str.size(); ++j) {
                if (j % reoccur == reoccur / 2)
                    result += str[j];
            }
        } else {
            for (int j = 0; j < str.size(); ++j) {
                if (j % reoccur == i || j % reoccur == reoccur - i)
                    result += str[j];
            }
        }
    }
    return result;
}

int main() {
    cout << "result: " << conversion("PAYPALISHIRING", 3) << endl;
}
