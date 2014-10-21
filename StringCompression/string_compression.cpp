#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;


// the problem is ab -> a1b1 which is longer than the original one
// we have to count the size of the new string first
// to find the right end place

// and second round we can safely change repeated ones since aaa -> a3 must be shorter
// and last we can change the single one




void compression(string &str) {
    if (str.empty())
        return;
    char current = str[0];
    int new_size = 0;
    int count = 1;
    for (int i = 1; i < str.size(); ++i) {
        if (str[i] == current)
            ++count;
        else {
            // check the count digit number
            // notice that count is bigger than 0
            int digit_need = (int) log10((double)count) + 1;
            // plus the character
            new_size = new_size + digit_need + 1;
            count = 1;
            current = str[i];
        }
    }
    int digit_need = (int) log10((double)count) + 1;
    new_size = new_size + digit_need + 1;

    if (new_size > str.size())
        return;

    // replace repeated to get enough size
    current = str[0];
    count = 1;
    int write_cursor = 0;
    int read_cursor = 1;
    
    while (read_cursor < str.size()) {
        if (str[read_cursor] == current) {
            read_cursor++;
            count++;
        } else {
            if (count == 1) {
                str[write_cursor] = current;
                write_cursor++;
            } else {
                str[write_cursor] = current;
                ++write_cursor;
                int digit_need = (int) log10((double)count) + 1;
                for (int i = digit_need - 1; i >= 0; --i) {
                    int digit = count % 10;
                    str[write_cursor + i] = (digit + '0');
                    count = count / 10;
                }
                write_cursor = write_cursor + digit_need;
            }
            current = str[read_cursor];
            ++read_cursor;
            count = 1;
        }
    }
    if (count == 1) {
        str[write_cursor] = current;
        write_cursor++;
    } else {
        str[write_cursor] = current;
        ++write_cursor;
        int digit_need = (int) log10((double)count) + 1;
        for (int i = digit_need - 1; i >= 0; --i) {
            int digit = count % 10;
            str[write_cursor + i] = (digit + '0');
            count = count / 10;
        }
        write_cursor = write_cursor + digit_need;
    }

    read_cursor = write_cursor - 1;
    write_cursor = new_size - 1;
    while (read_cursor >= 0) {
        char current = str[read_cursor];
        if ((current > '9' || current < '0') && 
                str[read_cursor + 1] > '9' || str[read_cursor + 1] < '0') {
            str[write_cursor] = '1';
            write_cursor--;
            str[write_cursor] = current;
            write_cursor--;
        } else {
            str[write_cursor] = current;
            write_cursor--;
        }
        read_cursor--;
    }
    str.resize(new_size);
}   


int main() {
    string str = "aaaabbkccd";
    compression(str);
    cout << "result: " << str << endl;
}
