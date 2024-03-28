//
// Created by Paradoxia1 on 2024/3/27.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans;
        int left = 0, right = numbers.size() - 1;
        int temp = 0;
        while (left < right) {
            temp = numbers[left] + numbers[right];
            if (temp == target) {
                ans.push_back(++left);
                ans.push_back(++right);
                return ans;
            } else if (temp < target) ++left;
            else if (temp > target) --right;
        }
        return ans;
    }
};

int main() {
    Solution solu;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> num = solu.twoSum(numbers, target);
    for (int i: num) {
        cout << i << endl;
    }
}