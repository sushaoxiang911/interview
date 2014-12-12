#include <iostream>
#include <vector>

using namespace std;

class OneDimensionIterator {
    private:
        vector<int> *ptr;
        int index;
        int size;

    public:
        OneDimensionIterator (vector<int> &arr) {
            ptr = &arr;
            size = arr.size();
            index = -1;
        }  
        
        bool hasNext() {
            if (index + 1 < size)
                return true;
            else
                return false;
        } 

        int next() {
            return (*ptr)[++index];
        }

};

class TwoDimensionIterator {
    private:
        int row;
        int col;
        vector<vector<int> > *ptr;
        int next_row;
        int next_col;

    public:
        TwoDimensionIterator(vector<vector<int> > &arr) {
            ptr = &arr;
            row = -1;
            col = -1;
            next_row = -1;
            next_col = -1;
        }

        bool hasNext() {
            if (row == -1 || col == (*ptr)[row].size() - 1) {
                for (next_row = row + 1; next_row < (*ptr).size(); ++next_row) {
                    if (!(*ptr)[next_row].empty()) {
                        next_col = 0;
                        return true;
                    }
                }
                return false;
            } else {
                next_row = row;
                next_col = col + 1;
                return true;
            }
        }

        int next() {
            row = next_row;
            col = next_col;
            return (*ptr)[row][col];
        }
};

int main() {
    vector<int> one_dimension = {1, 2};
    OneDimensionIterator it_1(one_dimension);
    cout << "one dimension result: " << endl;
    cout << "has next: " << it_1.hasNext() << endl;
    cout << "next: " << it_1.next() << endl;
    cout << "has next: " << it_1.hasNext() << endl;
    cout << "next: " << it_1.next() << endl;
    cout << "has next: " << it_1.hasNext() << endl;
   
    vector<vector<int> > two_dimension = {{}, {}, {1, 2}, {}, {}, {3}};
    TwoDimensionIterator it_2(two_dimension);


    cout << "two dimension result: " << endl;
    cout << "has next: " << it_2.hasNext() << endl;
    cout << "next: " << it_2.next() << endl;
    cout << "has next: " << it_2.hasNext() << endl;
    cout << "next: " << it_2.next() << endl;
    cout << "has next: " << it_2.hasNext() << endl;
    cout << "next: " << it_2.next() << endl;
    cout << "has next: " << it_2.hasNext() << endl;
}


