//
// Created by Paradoxia1 on 2024/3/28.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ans = {};
        std::sort(nums.begin(), nums.end());
        int left, right;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] < 0) {
                    while (left < right && nums[left] == nums[++left]);
                } else if (nums[i] + nums[left] + nums[right] > 0) {
                    while (left < right && nums[right] == nums[--right]);
                } else if (nums[i] + nums[left] + nums[right] == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[++left]);
                    while (left < right && nums[right] == nums[--right]);
                }
            }
        }
        return ans;
    }
};


int main() {
    Solution solu;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    for (vector<int> vec: solu.threeSum(nums)) {
        for (int i: vec) {
            cout << i << " ";
        }
        cout << endl;
    }
}