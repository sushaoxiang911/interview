#include <iostream>
#include <vector>

using namespace std;

// to guarantee the biggest profit
// we find every increasing part of the prices
// for every part, use the highest price minus lowest to get the profit
// greedy

int buy_sell_stock(vector<int> prices) {
    if (prices.size() == 0)
        return 0;
    
    int result = 0;
    int last_value = prices[0];
    int start_value = prices[0];
    for (int i = 1; i < prices.size(); ++i) {
        int current_price = prices[i];
        if (current_price < last_value) {
            result += (last_value - start_value);
            start_value = current_price;
        }
        last_value = current_price;
    }
    // solve the last one value 
    result += (last_value - start_value);
    return result;
}

int main() {
    vector<int> prices {1, 4, 2, 3, 5, 8, 4};
    cout << "result: " << buy_sell_stock(prices) << endl;
}
