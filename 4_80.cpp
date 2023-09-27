//
// Created by 98751 on 2023/9/27.
//
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    // 双指针计数法
    int removeDuplicates1(vector<int> &nums) {
        if (nums.empty()) return 0;
        int left = 0, ptr = 0;
        nums.push_back(-100);
        for (int right = 1; right < nums.size(); right++) {
            if (nums[right] != nums[left]) {
                ptr++;
                if (right - left > 1) {
                    nums[ptr] = nums[ptr - 1];
                    ptr++;
                }
                nums[ptr] = nums[right];
                left = right;
            }
        }
        return ptr;
    }

    // 快慢指针法
    int removeDuplicates2(vector<int> &nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int slow = 2, fast = 2;
        while (fast < n) {
            if (nums[slow - 2] != nums[fast]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};

int main() {
    Solution solu;
    vector<int> nums{0, 0, 1, 1, 1, 1, 2, 2, 3, 3};
    cout << solu.removeDuplicates1(nums) << endl;
}