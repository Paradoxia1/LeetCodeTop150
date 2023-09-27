//
// Created by 98751 on 2023/9/27.
//
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if(nums.empty()) return 0;
        int left = 0;
        for (int right = 1; right < nums.size(); right++) {
            if (nums[right] != nums[left]) {
                left++;
                nums[left] = nums[right];
            }
        }
        return left+1;
    }
};

int main() {
    Solution solu;
    vector<int> nums{};
    cout << solu.removeDuplicates(nums) << endl;
}