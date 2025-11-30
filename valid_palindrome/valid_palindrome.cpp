#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> s_char;

        for(size_t i=0;i<s.length();i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
                if (s[i] >= 'A' && s[i] <= 'Z') {
                    s_char.push_back(s[i]+32);
                } else {
                    s_char.push_back(s[i]);
                }
            }
        }

        int i = 0;
        int j = s_char.size() - 1;

        while (i <= j) {
            if (s_char[i] != s_char[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};

int main() {
    Solution solution;

    string s = "A man, a plan, a canal: Panama";
    bool result = solution.isPalindrome(s);
    cout << (result ? "True" : "False") << endl;
    s = "race a car";
    result = solution.isPalindrome(s);
    cout << (result ? "True" : "False") << endl;

    return 0;
}