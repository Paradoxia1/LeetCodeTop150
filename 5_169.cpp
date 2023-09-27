//
// Created by 98751 on 2023/9/27.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> dict;
        int cnt = nums.size() / 2;
        for (int num: nums) {
            if (dict.find(num) == dict.end()) dict[num] = 1;
            else dict[num]++;
            if (dict[num] > cnt) {
                return num;
            }
        }
        return 0;
    }
};

int main() {
    Solution solu;
    vector<int> nums{2, 2, 1, 1, 1, 2, 2};
    cout << solu.majorityElement(nums) << endl;
}