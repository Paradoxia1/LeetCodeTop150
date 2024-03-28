//
// Created by Paradoxia1 on 2024/3/27.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // DP实现
    bool isSubsequence(string s,string t){

    }
//    bool isSubsequence(string s, string t) {
//        int idx = 0;
//        for (char i: s) {
//            while (idx < t.size() && t[idx] != i) ++idx;
//            if (idx == t.size()) return false;
//            ++idx;
//        }
//        return true;
//    }
};

int main() {
    Solution solu;
    string s = "aaaaaa", t = "bbaaaa";
    cout << solu.isSubsequence(s, t) << endl;
}