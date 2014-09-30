#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct interval {
    int start;
    int end;
};
struct comp {
    bool operator() (const interval &interval1, const interval &interval2) {
        return interval1.start < interval2.start;
    }
} comp_obj;

vector<interval> merge_intervals(vector<interval> intervals) {
    vector<interval> result;
    if (intervals.empty())
        return result;
    sort(intervals.begin(), intervals.end(), comp_obj);
    result.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
        interval current = intervals[i];
        interval last = result.back();
        if (current.start > last.end)
            result.push_back(current);
        else {
            result.pop_back();
            interval temp = current;
            if (last.start < temp.start)
                temp.start = last.start;
            if (last.end > temp.end)
                temp.end = last.end;
            result.push_back(temp);
        }
    }
    return result;
}

int main() {
    vector<interval> intervals {interval{1, 4}, interval{8, 9}, interval{20, 30},
                                interval{7, 14}, interval{2, 9}};
    vector<interval> result = merge_intervals(intervals);
    for (int i = 0; i < result.size(); ++i) {
        cout << "[" << result[i].start << ", " << result[i].end << "], ";
    }
    cout << endl;
}
