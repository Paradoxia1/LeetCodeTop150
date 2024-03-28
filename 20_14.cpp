//
// Created by Paradoxia1 on 2024/3/19.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string s = "";
        int minLen = 100;
        if(strs.size()==0) minLen=0;
        else{
            for (int i = 0; i < strs.size(); ++i) {
                if (strs[i].length() < minLen) minLen = strs[i].length();
            }
        }
        for (int i = 0; i < minLen; ++i) {
            int j = 0;
            while (j < strs.size() - 1) {
                if (strs[j][i] != strs[j + 1][i]) {
                    return s;
                }
                j++;
            }
            s.push_back(strs[j][i]);
        }
        return s;
    }
};

int main() {
    Solution solu;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << solu.longestCommonPrefix(strs) << endl;
}