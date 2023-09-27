//
// Created by Paradoxia1 on 2023/9/27.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int low = prices[0], high = low, max = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (low > prices[i]) {
                low = prices[i];
                high = low;
            } else if (high < prices[i]) {
                high = prices[i];
                if (high - low > max) max = high - low;
            }
        }
        return max;
    }
};

int main() {
    Solution solu;
    vector<int> nums{3, 3, 5, 0, 0, 3, 1, 4};
    cout << solu.maxProfit(nums) << endl;
}