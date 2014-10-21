#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// start from small and find all the prime factors
// notice that here we do not need to check if a number is a prime or not
// for example we start from 2, then 4 will never be a factor
// since we always divide by 2

// and also there is a formula that 
// we just need to iterate from 2 to n^(1/2)
// and if we cannot find any factor then that means the number is a prime

// assume the target number has a factor k that is bigger than sqrt(n)
// then there is must be a smaller factor which is target/k that is 
// smaller than sqrt(n)

// therefore



int find_prime(int target) {
    if (target <= 1)
        return -1; // as an error
    vector<int> factors;
    while (target > 1) {
        bool is_found = false;
        for (int i = 2; i < (int) sqrt(target); ++i) {
            if (target % i == 0) {
                is_found = true;
                factors.push_back(i);
                target = target / i;
                break;
            } 
        }
        if (!is_found) {
            factors.push_back(target);
            break;
        }
    }    
    return factors[factors.size() - 1];
}

int main() {
    cout << "result: " << find_prime(148) << endl;

}
