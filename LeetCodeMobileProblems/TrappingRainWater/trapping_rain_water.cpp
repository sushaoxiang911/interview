#include <iostream>
#include <vector>

using namespace std;

// make sure that there is a bar that must be a side of the container
// 找到最长的那块木板，假设其下标为maxIdx。

// 分别从左侧和右侧向其逼近。

// 在左侧逼近过程中：

//    如果一个木板的长度小于已经遍历的最大长度max，即max>该木板<maxIdx，所以在该木板位置能存max - 该木板长度的水量（左右两侧各有一个木板长于它）。

//    如果一个木板的长度大于已经遍历的最大长度max，即max<该木板<maxIdx，所以在该木板位置不能存水（因为左右两侧只有一个木板（maxIdx）长于它）。更新max值。

// 右侧逼近过程与左侧相似。

int max_water(vector<int> bar) {
    if (bar.empty())
        return 0;
    
    int max_bar = 0;
    int max_index = 0;
    for (int i = 0; i < bar.size(); ++i) {
        if (bar[i] > max_bar) {
            max_bar = bar[i];
            max_index = i;
        }
    }

    int result = 0;
    max_bar = 0;
    for (int i = 0; i < max_index; ++i) {
        if (bar[i] < max_bar)
            result = result + max_bar - bar[i];
        else
            max_bar = bar[i];
    }
    max_bar = 0;
    for (int i = bar.size() - 1; i > max_index; --i) {
        if (bar[i] < max_bar)
            result = result + max_bar - bar[i];
        else
            max_bar = bar[i];
    }
    return result;
}

int main() {
    vector<int> bar{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "result: " << max_water(bar) << endl;
}
