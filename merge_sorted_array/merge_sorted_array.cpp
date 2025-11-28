#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = m + n - 1;

        m -= 1;
        n -= 1;
        while (m>=0 && n>=0) {
            if (nums1[m] > nums2[n]) {
                nums1[l] = nums1[m];
                m--;
                l--;
            } else {
                nums1[l] = nums2[n];
                n--;
                l--;
            }
        }

        while (n>=0) {
            nums1[l] = nums2[n];
            n--;
            l--;
        }
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 2, 4, 0, 0};
    vector<int> nums2 = {1, 3};

    solution.merge(nums1, 3, nums2, 2);

    for (size_t i=0;i<5;i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;

    return 0;
}