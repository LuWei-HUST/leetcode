#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        int mid = (r-l)/2 + l;

        if (x <= 1) {
            return x;
        }

        while (l <= r) {
            if (x / mid == mid) {
                return mid;
            }
            if (x / mid < mid) {
                r = mid - 1;
                mid = (r-l)/2 + l;
            }
            if (x / mid > mid) {
                l = mid + 1;
                mid = (r-l)/2 + l;
            }
        }

        return r;
    }
};

int main() {
    Solution solution;

    int r = solution.mySqrt(10);

    cout << "10的平方根：" << r << endl;

    return 0;
}