#include <iostream>
#include <vector>

using namespace std;
struct interval {
    int start;
    int end;
};

vector<interval> insert_merge (vector<interval> origin, interval new_interval) {
    
    vector<interval> result;
    bool has_inserted = false;
    for (int i = 0; i < origin.size(); ++i) {
        interval current = origin[i];
        if (has_inserted)
            result.push_back(current);
        else {
            if (new_interval.end < current.start) {
                result.push_back(new_interval);
                result.push_back(current);
                has_inserted = true;
            } else if (new_interval.start > current.end)
                result.push_back(current);
            else {
                interval temp;
                temp.start = new_interval.start < current.start ? 
                                new_interval.start : current.start;
                temp.end = new_interval.end < current.end ? 
                                current.end : new_interval.end;
                new_interval = temp;
            }
        }
    }
    if (!has_inserted)
        result.push_back(new_interval);
    return result;
}

int main() {
    vector<interval> origin{ interval{1, 2},
                             interval{3, 5},
                             interval{6, 7},
                             interval{8, 10},
                             interval{12, 16}};
    interval new_interval{4, 9};
    vector<interval> result = insert_merge(origin, new_interval);
    cout << "result: " << endl;
    for (int i = 0; i < result.size(); ++i)
        cout << "[" << result[i].start << ", " << result[i].end << "]" << " ";
    cout << endl;
}
