#include <iostream>
#include <string>

using namespace std;

int last_word_length (string str) {
    int last_length = 0;
    bool space = false;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == ' ')
            space = true;
        else {
            if (space) {
                last_length = 1;
                space = false;
            } else 
                ++last_length;
        }
    }
    return last_length;
}

int main() {
    string str = "Hello World";
    cout << last_word_length (str) << endl;
}
