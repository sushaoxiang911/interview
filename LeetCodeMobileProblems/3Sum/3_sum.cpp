#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// with a advanced sorting, this algorithm uses 2Sum which takes O(n) time complexity
// so this takes O(n^2)


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

    cout << "after sort" << endl;
    for(int i = 0; i < num_array.size(); ++i) 
        cout << num_array[i] << " ";
    cout << endl;
    for(int i = 0; i < num_array.size() - 2; i++) {
        // check if the current num is equal to the previous
        // if it is, we just ignore, since all the answers have already been obtained on the previous stage
        // case like -1, -1, 2, when iterate the first -1, all the answers that second -1 can obtain have been obtained
        if (i > 0 && num_array[i] == num_array[i-1])
            continue;

        // for every set[i], try to find two numbers from others that sum is -set[i]
        int required_sum = -num_array[i];
        int j = i + 1;
        int k = num_array.size() - 1;
        while (j != k) {
            if (num_array[j] + num_array[k] == required_sum) {
                cout << "find equal " << i << " " << j << " " << k << endl; 
                comb temp{num_array[i], num_array[j], num_array[k]};
                if (result.size() == 0 || (temp.a != result[result.size()-1].a || 
                                            temp.b != result[result.size()-1].b || 
                                            temp.c != result[result.size()-1].c))
                    result.push_back(temp);
                ++j;
            } else if (num_array[j] + num_array[k] > required_sum)
                --k;
            else
                ++j;
        }
    }
    return result;
}


int main ()
{
    vector<int> num_array{0, 0, 0, 0, -1, -1, 1, -1, 2};
    vector<comb> result = find_3_sum(num_array);
    for(int i = 0; i < result.size(); ++i) {
        cout << result[i].a << " + " << result[i].b << " + " << result[i].c << endl;    
    }
    return 0;
}
