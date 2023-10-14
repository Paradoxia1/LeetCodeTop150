//
// Created by Paradoxia1 on 2023/9/27.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit1(vector<int> &prices) {
        int low = prices[0], high = low, max = 0;
        for (int price: prices) {
            if (price > high) {
                high = price;
            } else if (price < high) {
                max += high - low;
                low = price;
                high = low;
            }
        }
        max += high - low;
        return max;
    }

    // 动态规划
    int maxProfit2(vector<int> &prices) {
        int n = prices.size();
        int dp[n][2];
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};

int main() {
    Solution solu;
    vector<int> nums{7, 6, 4, 3, 1};
    cout << solu.maxProfit2(nums) << endl;
}