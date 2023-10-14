//
// Created by Paradoxia1 on 2023/10/13.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> arr(nums.size());
        arr[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            arr[i] = arr[i - 1] * nums[i - 1];
        }
        int temp = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            arr[i] = arr[i] * temp;
            temp *= nums[i];
        }
        return arr;
    }
};

int main() {
    Solution solu;
    vector<int> nums{1, 2, 3, 4};
    nums = solu.productExceptSelf(nums);
    cout << endl;
}