#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct comb {
    int a;
    int b;
    int c;
};

vector<comb> find_3_sum (vector<int> num_array) {
    vector<comb> result;
    // if less than three elements
    if (num_array.size() < 3)
        return result;
    
    // sort the array
    sort(num_array.begin(), num_array.end());

    // two loops for iterate the first two numbers
    // two numbers to record last one
    int outerloop_last_num;
    int innerloop_last_num;
    if (num_array[0] != 0)
        outerloop_last_num = -num_array[0];
    else
        outerloop_last_num = -1;
    for (int i = 0; i < num_array.size() - 2; ++i) {
        if (num_array[i] == outerloop_last_num)
            continue;
        outerloop_last_num = num_array[i];
        
        if (num_array[i+1] != 0)
            innerloop_last_num = -num_array[i+1];
        else
            innerloop_last_num = -1;
        for (int j = i + 1; j < num_array.size() - 1; ++j) {
            if (num_array[j] == innerloop_last_num)
                continue;
            innerloop_last_num = num_array[j];

            // binary search
            int required_num = -(num_array[i] + num_array[j]);

            // find required_num from j+1 to array_num[array_num.size() - 1];
            int start = j + 1;
            int end = num_array.size() - 1;
            while (start <= end) {
                int mid_index = (start + end) / 2;
                int mid_num = num_array[mid_index];
                if (mid_num == required_num) {
                    comb temp{outerloop_last_num, innerloop_last_num, mid_num};
                    result.push_back(temp);
                    break;
                } else if (mid_num < required_num)
                    start = mid_index + 1;
                else
                    end = mid_index - 1;
            }
        }
    }
    return result;
    
}

int main() {
    vector<int> num_array{0, 0, 0, -1, -1, 1, -1, 2};
    vector<comb> result = find_3_sum(num_array);
    for(int i = 0; i < result.size(); ++i) {
        cout << result[i].a << " + " << result[i].b << " + " << result[i].c << endl;
    }
    return 0;
    

}
