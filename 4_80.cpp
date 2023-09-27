//
// Created by 98751 on 2023/9/27.
//
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
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
};

int main() {
    Solution solu;
    vector<int> nums{0, 0, 1, 1, 1, 1, 2,2, 3, 3};
    cout << solu.removeDuplicates(nums) << endl;
}