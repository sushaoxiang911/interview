#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<string> justification (vector<string> list, int length) {
    vector<string> result;
    if (list.empty()) {
        return result;
    }

    while(!list.empty()) {
        vector<string> packet;
        int current_sum = 0;
        bool is_last_one = true;
        while (!list.empty()) {
            if (current_sum + packet.size() + list[0].size() > length) {
                int space_sum = length - current_sum;
                int average_space = space_sum / (packet.size() - 1);
                int remain_space = space_sum % (packet.size() - 1);
                string current_string = "";
                for (int i = 0; i < packet.size() - 1; ++i) {
                    current_string += packet[i];
                    for (int j = 0; j < average_space; ++j)
                        current_string += " ";
                    if (remain_space > 0) {
                        current_string += " ";
                        --remain_space;
                    }
                }
                current_string += packet.back();
                result.push_back(current_string);
                is_last_one = false;
                break;
            }

            packet.push_back(list[0]);
            current_sum += list[0].size();
            list.erase(list.begin());
        }
        
        if (is_last_one) {
            string current_string = "";
            for (int i = 0; i < packet.size(); ++i) {
                current_string += packet[i];
                current_string += " ";
            }
            int current_size = current_string.size();
            for (int i = 0; i < length - current_size; ++i)
                current_string += " ";
            result.push_back(current_string);
        }
    }
    return result;
}

int main() {
    vector<string> list{"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> result = justification(list, 16);
    cout << "result: " << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
    
}

