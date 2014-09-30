#include <iostream>
#include <string>

using namespace std;

string int_to_string (int num) {
    string result;
    if (num < 10) {
        char temp = (char)(num + '0');
        result += temp;
        return result;
    }
    int digit = num % 10;
    num = num / 10;
    char temp = (char)(digit + '0');
    result = int_to_string(num) + temp;
    return result;
}

string count_say (int n) {
    string s = "1";
    for (int i = 2; i <= n; ++i) {
        string new_string;
        int index = 0;
        int size = s.length();
        char current = s[0];
        int count = 0;
        while (index < size) {
            if (s[index] == current) {
                ++count;
            } else {
                new_string.append(int_to_string(count));
                new_string += current;
                count = 1;
                current = s[index];
            }
            ++index;
        }
        new_string.append(int_to_string(count));
        new_string += current;
        s = new_string;
    }
    return s;
}

int main() {
    cout << "result: " << count_say(9) << endl;
}
