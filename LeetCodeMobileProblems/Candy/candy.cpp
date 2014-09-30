#include <iostream>
#include <vector>

using namespace std;

// basic consideration is 
// for the increasing part, we start from 1 and for every student that rating bigger than previous// we add the candy by 1. and we cannot assign decreasing
// so we go from the beginning to end once and go from end to beginning once
// and for the top, it should satisefy both left side and right side,
// when we go forward and backward, we always use the bigger number assigned

int candy (vector<int> ratings) {
    vector<int> candy_assigned(ratings.size(), 1);
    for (int i = 1; i < ratings.size(); ++i) {
        if (ratings[i] > ratings[i - 1]) {
            candy_assigned[i] = candy_assigned[i - 1] + 1;
        }
    }
    
    for (int i = ratings.size() - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) {
            candy_assigned[i] = candy_assigned[i] > candy_assigned[i + 1] + 1 ?
                                    candy_assigned[i] : candy_assigned[i + 1] + 1;
        }
    }
    int min_sum = 0;
    for (int i = 0; i < candy_assigned.size(); ++i)
        min_sum += candy_assigned[i];
    return min_sum;
}

// actually we may not have to use a vector to do that
// if the array is non-decreasing, we just every time + 1
// if there is a decreasing, like 1, 5, 4, 3, 2
// we first assign 1 to 1 and 5 to 2 and then we find that the value of 5 should be adjusted
// and the adjustment is decided by the decreasing part length

int candy_2 (vector<int> ratings) {
    int sum = 1;
    int current_num = 1;
    int decreasing_start = -1;
    for (int i = 1; i < ratings.size(); ++i) {
        if (ratings[i] > ratings[i - 1]) {
            if (decreasing_start != -1)
                current_num = 1;
            current_num++;
            sum += current_num;
            decreasing_start = -1;
        } else if (ratings[i] == ratings[i - 1]) {
            sum++;
            current_num = 1;
            decreasing_start = -1;
        } else {
            if (decreasing_start == -1)
                decreasing_start = i;
            int length = i - decreasing_start + 1;
            sum = sum + length;
            if (current_num <= length) {
                sum++;
                current_num++;
            }
        }   
    }
    return sum;
}

int main() {
    vector<int> ratings {1, 2, 5, 5, 10};
    cout << "result: " << candy(ratings) << endl;
    cout << "result2: " << candy_2(ratings) << endl;
}
