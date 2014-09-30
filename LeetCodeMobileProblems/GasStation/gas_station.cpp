#include <iostream>
#include <vector>

using namespace std;

// solution 1
// if we want to guarantee the car can achieve one loop
// we want to accumulate as much fuel as we could
// the fuel accumulated is gas[i]-cost[i]
// we want to start at a place that gas[i]-cost[i] the largest
// we find diff[]'s max sub-array and diff[]'s min sub-array
// and we compare max sub-array and total - min sub-array


// solution 2
// if we start from index i, and before we arrive at k, we can make it
// and when we from k to k+1, the car run out of fuel
// we know that gas[i]-cost[i] >= 0, so even we start from i+1, we can not make it to k+1
// and no matter what j we start, j from i to k
// we know that from j, we accumulate with 0 fuel
// and if we start from i, we know when we arrive at j, we have accumulate >= 0 fuel
// so we can simply start from k+1

// optimization of solution 2
// if 0 is start point and when we run from p, we run out of fuel.
// diff[0] + diff[1] + ... + diff[p] = sum1 < 0
// then we follow the algorithm and start from p+1 and when we run from q, we run out of fuel.
// diff[p+1] + ... + diff[q] = sum2 < 0
// then we set q+1 as the start place and we run to size-1
// diff[q+1] + ... + diff[size-1] >= 0
// then we can simply check sum1 + sum2 + sum3 to see if we can return to q+1


int find_solution (vector<int> gas, vector<int> cost) {
    if (gas.size() == 0 ||
        cost.size() == 0 ||
        gas.size() != cost.size())
        return -1;
    int total = 0;
    int sum = 0;
    int start = 0;
// so actually we go through the vector add all the gas and minus all the cost
// if this total < 0 then we cannot go around
// if this total >= 0 then we can go around
// we only need to know where to begin
    for (int i = 0; i < gas.size(); ++i) {
        total = total + gas[i] - cost[i];
        if (sum < 0) {
            sum = gas[i] - cost[i];
            start = i;
        } else
            sum = sum + gas[i] - cost[i];
    }

    return total < 0 ? -1 : start;        
}

int find_solution_2 (vector<int> gas, vector<int> cost) {
    if (gas.size() == 0 ||
        cost.size() == 0 ||
        gas.size() != cost.size())
        return -1;
    // record the max sub-array and max start place
    int max = gas[0] - cost[0];
    int max_start = 0;    

    // record the min sub-array and min end place as the start of the overloop
    int min = gas[0] - cost[0];
    int min_end = 0;

    // for the temperary values
    int temp_max = max;
    int temp_max_start = max_start;
    int temp_min = min;
    int temp_min_end = min_end;

    int total = gas[0] - cost[0];
    for (int i = 1; i < gas.size(); ++i) {
        int diff = gas[i] - cost[i];
        total += diff;
        
        if (temp_max < 0) {
            temp_max = diff;
            temp_max_start = i;
        }
        temp_max += diff;
        if (temp_max > max) {
            max = temp_max;
            max_start = temp_max_start;
        }

        if (temp_min > 0) {
            temp_min = diff;
        }
        temp_min += diff;
        if (temp_min < min) {
            min = temp_min;
            min_end = i;
        }
        
    }
    if (total < 0)
        return -1;
    return max >= (total - min) ? max_start : (min_end + 1);
}

int main () {
    vector<int> gas  {0, 0, 5, 0, 0};
    vector<int> cost {1, 1, 1, 1, 1};
    
    cout << "result: " << find_solution_2(gas, cost) << endl;    

}













