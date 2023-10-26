//
// Created by Paradoxia1 on 2023/10/23.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        if (ratings.size() < 1) {
            return 0;
        } else {
            int c[ratings.size()];
            for (int i = 0; i < ratings.size(); ++i) {
                c[i] = 1;
            }
            for (int i = 1; i < ratings.size(); ++i) {
                if (ratings[i] > ratings[i - 1]) {
                    c[i] = c[i - 1] + 1;
                }
            }
            for (int i = ratings.size() - 2; i >= 0; --i) {
                if (ratings[i] > ratings[i + 1]) {
                    c[i] = max(c[i], c[i + 1] + 1);
                }
            }
            int sum = 0;
            for (auto x: c) {
                sum += x;
            }
            return sum;
        }
    }
};

int main() {
    Solution solu;
    vector<int> ratings{1, 0, 2};
    cout << solu.candy(ratings) << endl;
}