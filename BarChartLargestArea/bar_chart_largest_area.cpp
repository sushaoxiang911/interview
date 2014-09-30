#include <iostream>
#include <vector>

using namespace std;

struct rectangle_in_progress {
    int start;
    int height;
};

int find_bar_chart_largest_area(vector<int> bar_chart) {
    // result is to keep track the biggest area
    // when there is one rec obtaining the end place check the area
    int result = 0;
    // it is to keep track all the rectangle that doesnot have a end point
    // the struct contains the start index and the height of the potential rectangle
    vector<rectangle_in_progress> potential_rectangle;

    for (int i = 0; i < bar_chart.size(); ++i) {
        int current_height = bar_chart[i];
        
        // first check for the current bar, where should be the start point
        // if there is a bar with that height, so nothing
        // if there is no bar with that height, find the start point
        rectangle_in_progress new_rectangle;
        new_rectangle.start = i;
        new_rectangle.height = current_height;
        bool if_already_exist = false;
        for (int j = 0; j < potential_rectangle.size(); ++j) {
            rectangle_in_progress temp = potential_rectangle[j];
            if (temp.height == current_height){
                if_already_exist = true;
                break;
            }
        // cannot break here since the start point of every potential rectangle is not sorted
            if (temp.height > current_height) {
                if (temp.start < new_rectangle.start)
                    new_rectangle.start = temp.start;
            }
        }
        if (!if_already_exist) {
            potential_rectangle.push_back(new_rectangle);
            cout << "push back rec with start " << new_rectangle.start << ", height " << 
                new_rectangle.height << endl; 
        }


        // check if it is an end of a rectangle in the potential list
        for (int j = 0; j < potential_rectangle.size(); ++j) {
            // if the potential rectangle has a higher height, meaning that 
            if (potential_rectangle[j].height > current_height) {
                
                // we have a completed rectangle
                // and check the area
                rectangle_in_progress complete_rectangle = potential_rectangle[j];
                int complete_area = complete_rectangle.height * (i - complete_rectangle.start);

                cout << "complete rec with start " << complete_rectangle.start << ", height " 
                << complete_rectangle.height << endl;
                if (complete_area > result)
                    result = complete_area;                

                // delete the complete from potential
                potential_rectangle.erase(potential_rectangle.begin() + j);
                --j;
            }
        }
    }
    
    // after interate all the bar, we have to handle the remained potential rectangle
    for (int i = 0; i < potential_rectangle.size(); ++i) {
        rectangle_in_progress complete_rectangle = potential_rectangle[i];
        int complete_area =  complete_rectangle.height * (bar_chart.size() 
                - complete_rectangle.start);
         cout << "complete rec with start " << complete_rectangle.start << ", height " 
                << complete_rectangle.height << endl;
        if (complete_area > result)
            result = complete_area;
    }
    return result;
}

int main() {
    vector<int> bar_chart{2, 4, 1, 3, 2, 4, 4, 3, 2};
    int result = find_bar_chart_largest_area(bar_chart);
    cout << "result is: " << result << endl;
}

