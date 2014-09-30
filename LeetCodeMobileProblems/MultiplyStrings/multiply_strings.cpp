#include <iostream>
#include <string>

using namespace std;

string add_decimal(string a, string b) {
    if (a == "")
        return b;
    if (b== "")
        return a;

    string result = "";

    int a_index = a.size() - 1;
    int b_index = b.size() - 1;

    int carry = 0;
    while (a_index >= 0 && b_index >= 0) {
        int sum = carry + (int)(a[a_index] - '0') + (int)(b[b_index] - '0');
        carry = sum / 10;
        int num = sum % 10;
        result = (char)(num + '0') + result;
        a_index--;
        b_index--;
    }
    while (a_index >= 0) {
        int sum = carry + (int)(a[a_index] - '0');
        carry = sum / 10;
        int num = sum % 10;
        result = (char)(num + '0') + result;
        a_index--;
    }
    while (b_index >= 0) {
        int sum = carry + (int)(b[b_index] - '0');
        carry = sum / 10;
        int num = sum % 10;
        result = (char)(num + '0') + result;
        b_index--;
    }
    if (carry > 0) {
        result = (char)(carry + '0') + result;
    }
    return result;

}

string multiply_decimal(string a, string b) {
    if (a == "0" || b == "0")
        return "0";
    int sign_flag = 0;
    if (a[0] == '-') {
        sign_flag--;
        a = a.substr(1);
    }
    if (b[0] == '-') {
        sign_flag++;
        b = b.substr(1);
    }

    string result = "";

    int a_index = a.size() - 1;
    int b_index;
    while (a_index >= 0) {
        int current_multiplication = (int)(a[a_index] - '0');

        if (current_multiplication == 0) {
            a_index--;
            continue;
        }
        b_index = b.size() - 1;
        string temp_result = "";
        int carry = 0;

        while (b_index >= 0) {
            int one_multiply_one = (int)(b[b_index] - '0') * current_multiplication + carry;
            carry = one_multiply_one / 10;
            int num = one_multiply_one % 10;
            temp_result = (char)(num + '0') + temp_result;
            b_index--;
        }
        int zero_count = a.size() - 1 - a_index;
        for (int i = 0; i < zero_count; ++i)
            temp_result += '0';
        result = add_decimal(result, temp_result);

        a_index--;
    }

    if (sign_flag != 0)
        result = '-' + result;
    return result;
}


int main() {
    string a = "-11";
    string b = "-12";
    string result = multiply_decimal(a, b);
    cout << "result: " << result << endl;
}
