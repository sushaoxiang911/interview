#include <iostream>
#include <vector>

using namespace std;

// consider divide the vector in two parts
// find the biggest profit respectively
// notice that we need to iterate the whole vector,
// and when j++, the biggest profit of left l+1 can be obtained from l
// and the biggest profit of right r can be obtained from r-1
// just reverse the previous way

int buy_sell_stock (vector<int> prices) {
    if (prices.size() == 0)
        return 0;
    int result = 0;
    
    int size = prices.size();    

    vector<int> left (size, 0);
    vector<int> right (size, 0);

    // consider the left side
    // from no transaction to all of the prices is the range of left side
    int left_min = prices[0];
    left[0] = 0;
    for (int i = 1; i < size; ++i) {
        int temp_profit = prices[i] - left_min;
        if (temp_profit > left[i - 1])
            left[i] = temp_profit;
        else
            left[i] = left[i - 1];
        if (prices[i] < left_min)
            left_min = prices[i];
    }

    // consider the right side
    int right_max = prices[size - 1];
    right[0] = 0;
    for (int i = size - 2; i >= 0; --i) {
        int temp_profit = right_max - prices[i];
        if (temp_profit > right[i + 1])
            right[i] = temp_profit;
        else
            right[i] = right[i + 1];
        if (prices[i] > right_max)
            right_max = prices[i];
    }
    for (int i = 0; i < size; i++) {
        int temp_result = left[i] + right[i];
        result = result > temp_result ? result : temp_result;
    }
    return result;
}


int main () {
    vector<int> prices{2, 4, 2, 3, 5, 8, 4};
    cout << "result: " << buy_sell_stock(prices) << endl;
}
