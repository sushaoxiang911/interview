#include <iostream>
#include <string>

using namespace std;

string add_binary(string a, string b) {
    
    string result = "";
    // for the add-on
    int carry = 0;

    int a_index = a.size() - 1;
    int b_index = b.size() - 1;

    while (a_index >= 0 && b_index >= 0) {
        int sum = carry + (int)(a[a_index] - '0') + (int)(b[b_index] - '0');
        int num;
        if (sum >= 2) {
            carry = 1;
            num = sum - 2;
        } else {
            carry = 0;
            num = sum;
        }
        // notice taht result+= means result = result + 
        result = (char)(num + '0') + result;
        a_index--;
        b_index--;
    }
    while (a_index >= 0) {
        int sum = carry + (int)(a[a_index] - '0');
        // the former can be writen as
        carry = sum / 2;
        int num = sum % 2;
        result = (char)(num + '0') + result;
        a_index--;
    }

    while (b_index >= 0) {
        int sum = carry + (int)(b[b_index] - '0');
        carry = sum / 2;
        int num = sum % 2;
        result = (char)(num + '0') + result;
        b_index--;
    }
    if (carry > 0)
        result = (char)(carry + '0') + result;

    return result;

}

int main() {
    string a = "11";
    string b = "1";
    string result = add_binary(a, b);
    cout << result << endl;
}
