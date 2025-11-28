#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int flag = 0;
        int a_l = a.length();
        int b_l = b.length();
        int i = a_l - 1;
        int j = b_l - 1;
        stack<char> s;
        string r = "";

        while (i>=0 && j>=0) {
            int val = (a[i]-'0')+(b[j]-'0')+flag;
            if (val == 2) {
                flag = 1;
                s.push('0');
            } else if (val == 3) {
                flag = 1;
                s.push('1');
            } else {
                flag = 0;
                s.push('0'+val);
            }
            i--;
            j--;
        }
        
        while (i>=0) {
            int val = (a[i]-'0')+flag;
            if (val == 2) {
                flag = 1;
                s.push('0');
            } else {
                flag = 0;
                s.push('0'+val);
            }
            i--;
        }

        while (j>=0) {
            int val = (b[j]-'0')+flag;
            if (val == 2) {
                flag = 1;
                s.push('0');
            } else {
                flag = 0;
                s.push('0'+val);
            }
            j--;
        }

        if (flag == 1) {
            s.push('1');
        }

        while (!s.empty()) {
            char c = s.top();
            s.pop();
            r += c;
        }

        return r;
    }
};



int main() {
    Solution solution;

    string r = solution.addBinary("1", "111");

    cout << r << endl;

    return 0;
}
