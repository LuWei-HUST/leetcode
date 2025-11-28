#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int flag = 1;
        int l = digits.size();
        int i = l-1;
        vector<int> r;

        while (i>=0 && flag==1) {
            int val = digits[i] + flag;
            if (val >= 10) {
                digits[i] = 0;
                flag = 1;
                i--;
            } else {
                digits[i] = val;
                flag = 0;
                break;
            }
        }

        if (flag == 1) {
            r.push_back(1);
            for (size_t i=0;i<l;i++) {
                r.push_back(digits[i]);
            }

            return r;
        }else {
            return digits;
        }
        
    }
};

int main() {
    Solution solution;

    vector<int> vec = {9};

    vector<int> r = solution.plusOne(vec);

    for (size_t i=0;i<r.size();i++) {
        cout << r[i] << endl;
    }

    return 0;
}