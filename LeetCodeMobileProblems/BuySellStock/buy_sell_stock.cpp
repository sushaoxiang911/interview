#include <iostream>
#include <vector>

using namespace std;

// profit is later price minus previous price
// if occurs a lower price, 
// then we know that we would have a higher profit for later selling price
// key point here is how to find the lowest price and the highest price where 
// the index of the highest is bigger than the lowest

int buy_sell_stock(vector<int> prices) {
    if (prices.size() == 0)
        return 0;    

    int max_profit = 0;
    int low_price = prices[0];

    for (int i = 0; i < prices.size(); ++i) {
        if (prices[i] < low_price)
            low_price = prices[i];
        int temp_profit = prices[i] - low_price;
        if (temp_profit > max_profit)
            max_profit = temp_profit;
    }
    return max_profit;
}

int main() {
    vector<int> prices {5, 4, 2, 3, 5, 8, 4};
    cout << "result: " << buy_sell_stock(prices) << endl;
}
