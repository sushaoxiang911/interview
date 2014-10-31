#include <iostream>
#include <vector>

using namespace std;

// consideration:
// assume (i,a) is left side and (j,b) is right side and we have the biggest container
// then for every coordinate with k < i, a is the biggest
// for every coordinate with k > j, b is the biggest
// proof:
// assume we have a (j+d, c) where c > b
// then (i,a), (j+d, c) makes the biggest container because
// (j+d-i)*min(a,c) must be bigger than (j-i)*min(a,b)

// pre-handle: two vectors to mark
// for i from 0 to n-1, if a side can be the left side of the max container
// for i from n-1 to 0, if a side can be the right side of the max container
// it takes o(n)
// then for every pair of potential sides, check the size

// notice that this method is just to a pruning of the numbers
// we get rid of some sides that cannot be the left side or right side of the biggest container
// however the complexity is still O(n^2)

// if the number is 1, 2, 3, 4, 5, 4, 3, 2, 1
// then the mark is 1, 1, 1, 1, 1, 0, 0, 0, 0
//                  0, 0, 0, 0, 1, 1, 1, 1, 1
// and it takes O(n^2)

// another optimization is
// for every left side, if we achieve a right side that is larger than the left side
// then we know that the size depends on the right side and for a bigger left side
// we can not use it to enlarge the container

// but it brings some idea that sometime we may not make n^2 to nlogn but we can do some pruning
// by finding some characteristics



int find (vector<int> height) {
    vector<bool> leftside_mark(height.size());
    vector<bool> rightside_mark(height.size());
    int left_max = -1;
    for (int i = 0; i < height.size(); ++i) {
        if (height[i] > left_max) {
            leftside_mark[i] = true;
            left_max = height[i];
        }       
    }
    int right_max = -1;
    for (int i = height.size() - 1; i >= 0; --i) {
        if (height[i] > right_max) {
            rightside_mark[i] = true;
            right_max = height[i];
        }
    }
    int max_size = 0;
    for (int i = 0; i < height.size(); ++i) {
        if (!leftside_mark[i])
            continue;
        for (int j = height.size() - 1; j >= 0; --j) {
            if (!rightside_mark[j])
                continue;
            int temp_side = height[i] < height[j] ? height[i] : height[j];
            int temp_size = temp_side * (j - i);
            if (temp_size > max_size)
                max_size = temp_size;
            if (height[i] <= height[j])
                break;
        }
    }
    return max_size;
}

// a easier way is that
// we set up two sides from left-most and right-most
// based on these we calculate the max water it can contain
// So the only way that we could get a better solution is that
// we move the shorter one so if we can get a taller one
// we can have a better solution
int find_2(vector<int> height) {
    if (height.empty())
        return 0;
    int result = 0;
    int left = 0;
    int right = height.size() - 1;
    while (left < right) {
        int left_side = height[left];
        int right_side = height[right];
        int deep = left_side < right_side ? left_side : right_side;
        int temp_result = deep * (right - left);
        if (temp_result > result)
            result = temp_result;
        if (left_side < right_side)
            left++;
        else
            right--;
    }
    return result;
}

int main() {
    vector<int> height {5, 2, 12, 1, 5, 3, 4, 11, 9, 4};
    cout << "result: " << find(height) << endl;
    cout << "result: " << find_2(height) << endl;
}





