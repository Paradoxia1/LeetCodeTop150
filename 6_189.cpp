//
// Created by 98751 on 2023/9/27.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate1(vector<int> &nums, int k) {
        int n = nums.size();
        k %= n;
        vector<int> douNums = nums;
        douNums.insert(douNums.end(), nums.begin(), nums.end());
        nums.assign(douNums.end() - k - n, douNums.end() - k);
    }

    // 环状替换
    void rotate2(vector<int> &nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = __gcd(k, n);
        for (int start = 0; start < count; ++start) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                swap(nums[next], prev);
                current = next;
            } while (start != current);
        }
    }
};

int main() {
    Solution solu;
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    solu.rotate2(nums, k);

}