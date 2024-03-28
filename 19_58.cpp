//
// Created by Paradoxia1 on 2024/3/19.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 直接倒着算，简单的没想到不应该
    int lengthOfLastWord(string s) {
        int cnt = 0;
        int idx = s.length() - 1;
        while (s[idx] == ' ') {
            --idx;
        }
        while (s[idx] != ' ' && idx > -1) {
            --idx;
            cnt++;
        }
        return cnt;
    }

//    int lengthOfLastWord(string s) {
//        int temp = 0;
//        int cnt = 0;
//        for (int i = 0; i < s.length(); ++i) {
//            if (s[i] != ' ') {
//                temp++;
//                cnt = temp;
//            } else temp = 0;
//        }
//        return cnt;
//    }
};

int main() {
    Solution solu;
    string s = "   fly me   to   the moon  ";
    cout << solu.lengthOfLastWord(s) << endl;
}