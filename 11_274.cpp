//
// Created by Paradoxia1 on 2023/10/9.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        int left = 0, right = citations.size();
        while (left <= right) {
            int cnt = 0;
            int val = (left + right) / 2;
            for (int num: citations) {
                if (num >= val) {
                    ++cnt;
                    if (cnt >= val) {
                        break;
                    }
                }
            }
            if (cnt >= val) {
                left = val + 1;
            } else {
                right = val - 1;
            }
        }
        return right;
    }
};

int main() {
    Solution solu;
    vector<int> citations{0};
    cout << solu.hIndex(citations) << endl;
}