#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int find_3_sum_closest(vector<int> num_array, int target) {
    
    int result = -1;

    // sort first
    sort(num_array.begin(), num_array.end());
    
    
    // use binary search, and keep track of the i and j of the former loop
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
            // it is our duty to compare the last num remained with the previous and the next to find the better one among these threee
            int start = j + 1;
            int end = num_array.size() - 1;
            int required_num = target - num_array[i] - num_array[j];
            while (end != start) {
                int mid_index = (start + end) / 2;
                int mid_num = num_array[mid_index];
                if (mid_num == required_num)
                    return 0;
                else if (mid_num < required_num)
                    start = mid_index + 1;
                else
                    end = mid_index - 1;
            }
            
            // have to compare with the previous and next        
            int temp_result = abs(target - outerloop_last_num - innerloop_last_num - num_array[end]);
            if (result < 0)
                result = outerloop_last_num + innerloop_last_num + num_array[end];
            if (temp_result < result)
                result = outerloop_last_num + innerloop_last_num + num_array[end];
            if (end < num_array.size() - 1) {
                temp_result = abs(target - outerloop_last_num - innerloop_last_num - num_array[end + 1]);
                if (temp_result < result)    
                    result = outerloop_last_num + innerloop_last_num + num_array[end + 1];
            }
            if (end > j + 1) {
                temp_result = abs(target - outerloop_last_num - innerloop_last_num - num_array[end - 1]);
                if (temp_result < result)
                    result = outerloop_last_num + innerloop_last_num + num_array[end - 1];
            }
        }
    }
    return result;

}


int main() {
    vector<int> num_array{-1, 2, 1, -4};
    int target = 1;
    if (num_array.size() < 3)
        return 0;
    int result = find_3_sum_closest(num_array, target); 
    cout << "result is: " << result << endl;
}
