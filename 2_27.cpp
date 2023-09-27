//
// Created by 98751 on 2023/9/27.
//
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int tail = nums.size(), n = 0;
        while (tail > n) {
            if (nums[n] == val) {
                nums[n] = nums[--tail];
            } else n++;
        }
        return n;
    }
};

int main() {
    Solution solu;
    vector<int> nums{};
    int val = 0;
    cout << solu.removeElement(nums, val) << endl;
}