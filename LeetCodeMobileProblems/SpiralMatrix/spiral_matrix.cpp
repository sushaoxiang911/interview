#include <iostream>
#include <vector>

using namespace std;


vector<int> spiral_order(vector<vector<int> > matrix) {
    vector<int> result;
    int rs = 0;
    int re = matrix.size() - 1;
    int cs = 0;
    int ce = matrix[0].size() - 1;
    
    int side = 0;
    while (rs <= re && cs <= ce) {
        switch (side) {
            case 0:
                for (int i = cs; i <= ce; ++i)
                    result.push_back(matrix[rs][i]);
                ++rs;
                side = 1;
                break;
            case 1:
                for (int i = rs; i <= re; ++i)
                    result.push_back(matrix[i][ce]);
                --ce;
                side = 2;
                break;
            case 2:
                for (int i = ce; i >= cs; --i)
                    result.push_back(matrix[re][i]);
                --re;
                side = 3;
                break;
            default:
                for (int i = re; i >= rs; --i) 
                    result.push_back(matrix[i][cs]);
                ++cs;
                side = 0;
                break;
        }
    }
    return result;
}

int main() {
    vector<vector<int> > matrix {   {1, 2, 3}, 
                                    {4, 5, 6},
                                    {7, 8, 9},
                                    {10, 11, 12}};
    vector<int> result = spiral_order(matrix);
    cout << "result: " << endl;
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << " ";
    cout << endl;

}
