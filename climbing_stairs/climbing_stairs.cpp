#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> vec;

        if (n == 1) {
            return 1;
        }

        if (n == 2) {
            return 2;
        }

        vec.push_back(1);
        vec.push_back(2);

        int i = 2;
        while (i < n) {
            vec.push_back(vec[i-1] + vec[i-2]);
            i++;
        }

        return vec[n-1];
    }
};

int main() {
    Solution solution;

    int r = solution.climbStairs(45);

    cout << r << endl;

    return 0;
}