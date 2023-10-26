//
// Created by Paradoxia1 on 2023/10/22.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 不会再写第二遍的离谱算法，什么牛马思路
    int trap1(vector<int> &height) {
        int length = height.size();
        if (length < 2) return 0;
        int vol = 1;
        vector<int> top;
        for (int i = 1; i < length; ++i) {
            if (height[i] > height[i - 1]) {
                vol = 1;
            } else if (height[i] < height[i - 1] && vol) {
                vol = 0;
                top.push_back(i - 1);
            }
        }
        if (vol) {
            top.push_back(length - 1);
            vol = 0;
        }
        int left = 0, right = 0;
        length = top.size();
        int temp = 0;
        while (left < length) {
            temp = left + 1;
            for (right = left + 1; right < length; ++right) {
                if (height[top[left]] <= height[top[right]]) {
                    break;
                } else if (height[top[temp]] < height[top[right]]) {
                    temp = right;
                }
            }
            if (right == length) {
                if (left + 1 >= length) break;
                for (int i = top[temp] - 1; i > top[left]; --i) {
                    if (height[top[temp]] - height[i] >= 0) {
                        vol += height[top[temp]] - height[i];
                    } else break;
                }
                left = temp;
            } else {
                for (int i = top[left] + 1; i < top[right]; ++i) {
                    if (height[top[left]] - height[i] > 0) {
                        vol += height[top[left]] - height[i];
                    } else break;
                }
                left = right;
            }
        }
        return vol;
    }

    // 动态规划
    int trap2(vector<int> &height) {
        int n = height.size();
        if (n == 0) {
            return 0;
        }
        vector<int> leftMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        vector<int> rightMax(n);
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
};

int main() {
    Solution solu;
    vector<int> height{2, 8, 5, 5, 6, 1, 7, 4, 5};
    cout << solu.trap2(height) << endl;
}