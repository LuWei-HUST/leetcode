#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> r;

        int numRows = rowIndex + 1;
        vector<int> vec = {1};
        r.push_back(vec);

        if (numRows == 1) {
            return {1};
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

        return r[rowIndex];
    }
};

int main() {
    Solution solution;

    int rowIndex = 3;
    vector<int> r = solution.getRow(rowIndex);

    for (const auto& val : r) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}