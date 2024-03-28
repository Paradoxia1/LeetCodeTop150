//
// Created by Paradoxia1 on 2024/3/19.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
//    string reverseWords(string s) {
//        string ans = "";
//        string temp;
//        int idx = 0;
//        while (idx < s.length()) {
//            temp = "";
//            while (idx < s.length() && s[idx] == ' ') {
//                ++idx;
//            }
//            while (idx < s.length() && s[idx] != ' ') {
//                temp.push_back(s[idx]);
//                ++idx;
//            }
//            if (ans.length() && temp.length()) ans = temp + ' ' + ans;
//            else ans = temp + ans;
//        }
//        return ans;
//    }
    // O(1) Space Complexity
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int idx = 0;
        int len;
        for (int ptr = 0; ptr < s.length(); ++ptr) {
            len = 0;
            if (s[ptr] != ' ') {
                if (idx != 0)s[idx++] = ' ';
                while (ptr < s.length() && s[ptr] != ' ') {
                    s[idx++] = s[ptr++];
                    ++len;
                }
                reverse(s.begin() + idx - len, s.begin() + idx);
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};

int main() {
    Solution solu;
    string s = "a good   example";
    cout << solu.reverseWords(s) << endl;
}