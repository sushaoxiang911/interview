#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct point {
    int x;
    int y;
};


int find_points(vector<point> points) {    
    if (points.empty())
        return 0;
    int result = 1;
    for (int i = 0; i < points.size(); ++i) {
        
        map<double, int> count;
        // consider the slope does not exist
        int non_exist_slope = 0;
        // consider the same points, don't calculate and add in the last
        int same_point_num = 0;        
        
        for (int j = i + 1; j < points.size(); ++j) {
            point current_point = points[i];
            point other_point = points[j];
            if (current_point.x == other_point.x &&
                current_point.y == other_point.y) {
                same_point_num++;
            }
            if (current_point.x == other_point.x &&
                current_point.y != other_point.y) {
                non_exist_slope++;
            }
            if (current_point.x != other_point.x) {
                double slope = (other_point.y - current_point.y) / 
                                    (other_point.x - current_point.x);
                auto it = count.find(slope);
                if (it == count.end()) {
                    count.insert(pair<double, int> (slope, 1));
                } else {
                    it -> second++;
                }
            }
        } 
        
        if (non_exist_slope + same_point_num > result)
            result = non_exist_slope + same_point_num;
        auto it = count.begin();
        while (it != count.end()) {
            int temp = it -> second;
            if (temp + same_point_num > result)
                result = temp + same_point_num;
            ++it;
        }
    }
    return result;
}

int main() {
    vector<point> points 
        {point{1, 3}, point{1, 4}, point{2, 4}, point{1, 2}, point{2, 6}, point{1, 2}};
    cout << "result: " << find_points(points) << endl;
}

