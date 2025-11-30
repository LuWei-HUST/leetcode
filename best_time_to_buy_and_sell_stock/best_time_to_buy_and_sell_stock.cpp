#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> profit(prices.size(), 0);

        int i = 1;
        for (int i=1;i<prices.size();i++) {
            int val1 = profit[i-1] + prices[i] - prices[i-1];
            int val2 = prices[i] - prices[i-1];
            if (val2 > val1) {
                profit[i] = val2;
            } else {
                profit[i] = val1;
            }
        }

        return *max_element(profit.begin(), profit.end());
    }
};

int main() {
    Solution solution;

    vector<int> prices = {7,1,5,3,6,4};
    int result = solution.maxProfit(prices);

    cout << "Maximum Profit: " << result << endl;

    return 0;
}