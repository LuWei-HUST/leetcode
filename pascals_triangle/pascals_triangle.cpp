#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r;

        vector<int> vec = {1};
        r.push_back(vec);

        if (numRows == 1) {
            return r;
        }

        int layer = 2;

        while (layer <= numRows) {
            int i = 1;

            vector<int> vec(layer, 1);
            while (i <= layer-2) {
                vec[i] = r[layer-2][i-1] + r[layer-2][i];
                i++;
            }

            r.push_back(vec);

            layer++;
        }

        return r;
    }
};

int main() {
    Solution solution;

    int numRows = 5;
    vector<vector<int>> r = solution.generate(numRows);

    for (const auto& vec : r) {
        for (const auto& val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}