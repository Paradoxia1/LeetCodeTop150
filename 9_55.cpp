//
// Created by Paradoxia1 on 2023/10/9.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int dp = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (dp > nums.size() - 2) {
                return true;
            }
            if (i > dp) {
                return false;
            }
            dp = max(dp, i + nums[i]);
        }
        return true;
    }
};

int main() {
    Solution solu;
    vector<int> nums{2, 3, 1, 1, 4};
    cout << solu.canJump(nums) << endl;
}