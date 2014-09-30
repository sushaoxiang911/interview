#include <iostream>
#include <vector>

using namespace std;

// gray code is a kind of encoding
// from binary to gray, encoding
// we from the right most bit and put all the bit XOR with the one-left one by one
// from gray to binary, decoding
// we from the the second bit of left, and XOR with the one-left that has already decoded 
// one by one

vector<int> gray_encoding (int n) {
    // first find the total number of integers that formed by n bits
    int number = 1 << n;
    vector<int> result;
    for (int i = 0; i < number; ++i) {
        int current_num = (i >> 1) ^ i;
        result.push_back(current_num);
    }
    return result;
}

vector<int> gray_decoding (vector<int> encoded) {
    vector<int> result;
    for (int i = 0; i < encoded.size(); ++i) {
        int current_encoded = encoded[i];
        for (int mask = current_encoded >> 1; mask != 0; mask = mask >> 1)
            current_encoded = current_encoded ^ mask;
        result.push_back(current_encoded);
    }
    return result;
}

int main () {
    vector<int> encoded = gray_encoding (2);
    cout << "result: " << endl;
    for (int i = 0; i < encoded.size(); ++i) 
        cout << encoded[i] << " ";
    cout << endl;
    vector<int> decoded = gray_decoding(encoded);
    for (int i = 0; i < decoded.size(); ++i)
        cout << decoded[i] << " ";
    cout << endl;
}   
