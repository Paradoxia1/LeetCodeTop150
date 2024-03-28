//
// Created by Paradoxia1 on 2024/3/19.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        vector<string> vec;
        if (s.size() == 1 || numRows == 1) {
            ans = s;
            return ans;
        }
        for (int i = 0; i < numRows; ++i) {
            vec.push_back("");
        }
        int row;
        for (int i = 0; i < s.size(); ++i) {
            row = i % (2 * numRows - 2);
            if (row < numRows) vec[row].push_back(s[i]);
            else vec[2 * numRows - 2 - row].push_back(s[i]);
        }
        for (int i = 0; i < vec.size(); ++i) {
            ans += vec[i];
        }
        return ans;
    }
};

int main() {
    Solution solu;
    string s = "AB";
    int numRows = 1;
    cout << solu.convert(s, numRows) << endl;
}