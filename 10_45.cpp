//
// Created by Paradoxia1 on 2023/10/9.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        if (nums.size() == 1) {
            return 0;
        } else {
            for (int i = 0; i < nums.size(); ++i) {
                nums[i] += i;
            }
            int step = 0, left = 0, right = nums[0];
            while (right < nums.size() - 1) {
                int temp = right;
                for (; left <= right; ++left) {
                    if (nums[left] > temp) {
                        temp = nums[left];
                    }
                }
                right = temp;
                ++step;
            }
            return step + 1;
        }
    }
};

int main() {
    Solution solu;
    vector<int> nums{2, 3, 1, 1, 4};
    cout << solu.jump(nums) << endl;
}