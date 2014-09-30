#include <iostream>
#include <vector>

using namespace std;

int decode_ways (string message) {

    // some trivial check
    if ((message.size() == 1 && message[0] > '0' && message[0] <= '9') || message.size() == 0)
        return 1;    
    if (message.size() == 1 && message[0] <= '0' && message[0] > '9')
        return 0;   

    int previous = 1;
    int previous_two = 1;
    int result = 0;    

    for (int i = 1; i < message.size(); ++i) {
        if (message[i] < '0' || message[i] > '9')
            return 0;
        if (message[i] == '0' && (message[i-1] == '1' || message[i-1] == '2')) {
            result = previous_two;
        else if (message[i] == '0' && message[i-1] != '1' && message[i-1] != '2')
            return 0;
        } else if (message[i-1] == '0' ||
            ((message[i-1] - '0') * 10 + (message[i] - '0') > 26)) {
            result = previous;
        } else {
            result = previous + previous_two;
        }
        previous_two = previous;
        previous = result;
    }
    return result;
}

int main (){
    string message = "12323";
    cout << "result: " << decode_ways(message) << endl;
}
