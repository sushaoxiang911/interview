#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct comb {
    int a;
    int b;
    int c;
    int d;
};

vector<comb> find_4_sum (vector<int> num_array, int target) {
    vector<comb> result;
    // if less than four elements
    if (num_array.size() < 4)
        return result;

    // sort the array
    sort(num_array.begin(), num_array.end());

    int outerloop_last_num;
    int innerloop_last_num;
    if (num_array[0] != 0)
        outerloop_last_num = -num_array[0];
    else
        outerloop_last_num = -1;
    

    for (int i = 0; i < num_array.size() - 3; ++i) {
        if (num_array[i] == outerloop_last_num)
            continue;
        outerloop_last_num = num_array[i];
        
        if (num_array[i+1] != 0)
            innerloop_last_num = -num_array[i+1];
        else
            innerloop_last_num = -1;
        for (int j = i + 1; j < num_array.size() - 2; ++j) {
        
            if (num_array[j] == innerloop_last_num)
                continue;
            innerloop_last_num = num_array[j];
            
            int required_num = target - innerloop_last_num - outerloop_last_num;

            int start = j + 1;
            int end = num_array.size() - 1;
            while (start != end) {
                if (num_array[start] + num_array[end] == required_num) {
                    comb temp{outerloop_last_num, innerloop_last_num, 
                            num_array[start], num_array[end]};

                    if (result.size() == 0 || (temp.c != result[result.size() - 1].c ||
                                                temp.d != result[result.size() - 1].d))
                        result.push_back(temp);
                    ++start;
                } else if (num_array[start] + num_array[end] > required_num)
                    --end;
                else
                    ++start;
            }    
        
        }
    }

}


int main() {
    vector<int> num_array{1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<comb> result = find_4_sum(num_array, target);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i].a << " + " << result[i].b << " + " << result[i].c << " + "
            << result[i].d << endl;
    
    }
    return 0;
}
