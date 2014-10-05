#include <iostream>
#include <string>
#include <stack>

using namespace std;

// use a stack to do that



string simplify_path(string path) {
    string result = "";
    if (path == "")
        return result;

    stack <string> directories;
    string dir_name = "";

    int index = 0;
    while (index < path.size()) {
        cout << "dir_name: " << dir_name << endl;
        if (path[index] == '/') {
            if (dir_name != "") {
                if (dir_name == "..") {
                    directories.pop();
                } else if (dir_name != ".") {
                    directories.push(dir_name);  
                }
                dir_name.clear();
            }
            ++index;
        } else {
            while (path[index] != '/') {
                dir_name += path[index];
                ++index;
            }
        }
    }

    while (!directories.empty()) {
        string current_dir = directories.top();
        result = "/" + current_dir + result;
        directories.pop();
    }
    return result;
}

int main() {
    string path = "/a/./b/../../c/";
    cout << "result: " << simplify_path(path) << endl;
}
