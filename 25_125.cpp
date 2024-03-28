//
// Created by Paradoxia1 on 2024/3/27.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 运用双指针
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            // 为了防止溢出需要每次都判断
            while (left < right && !isalnum(s[left])) ++left;
            while (left < right && !isalnum(s[right])) --right;
            if (left >= right) break;
            if (tolower(s[left]) != tolower(s[right])) return false;
            ++left;
            --right;
        }
        return true;
    }
//    bool isPalindrome(string s) {
//        s = remove(s);
//        for (int i = 0; i < s.size() / 2; ++i) {
//            if (s[i] != s[s.size() - 1 - i]) return false;
//        }
//        return true;
//    }
//
//    string remove(string s) {
//        string out = "";
//        for (int i = 0; i < s.size(); ++i) {
//            if (isalnum(s[i])) {
//                if (isupper(s[i])) out += tolower(s[i]);
//                else out += s[i];
//            }
//        }
//        return out;
//    }
};

int main() {
    Solution solu;
    string s = ".,";
    cout << solu.isPalindrome(s) << endl;
}