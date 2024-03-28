//
// Created by Paradoxia1 on 2024/3/27.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        int minHeight = 0;
        minHeight = min(height[left], height[right]);
        ans = minHeight * (right - left);
        while (left < right) {
            if (minHeight == height[left]) {
                ++left;
            } else --right;
            minHeight = min(height[left], height[right]);
            ans = max(ans, minHeight * (right - left));
        }
        return ans;
    }
};

int main() {
    Solution solu;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << solu.maxArea(height) << endl;
}