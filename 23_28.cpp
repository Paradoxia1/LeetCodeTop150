//
// Created by Paradoxia1 on 2024/3/20.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // KMP
    int strStr(string haystack, string needle) {
        int pos[needle.size() + 1];
        pos[0] = -1;
        int i = 0, j = -1;
        while (i < needle.size()) {
            if (j == -1 || needle[i] == needle[j]) {
                ++j;
                ++i;
                pos[i] = j;
            } else {
                j = pos[j];
            }
        }
        i = 0;
        j = 0;
        while (i < haystack.size() && j < int(needle.size())) {
            if (j == -1 || haystack[i] == needle[j]) {
                ++j;
                ++i;
            } else j = pos[j];
        }
        if (j == needle.size()) return i - j;
        return -1;
    }
//    int strStr(string haystack, string needle) {
//        for (int i = 0; i < haystack.size(); ++i) {
//            int j = 0;
//            for (; j < needle.size(); ++j) {
//                if (needle[j] != haystack[i + j]) break;
//            }
//            if (j == needle.size()) return i;
//        }
//        return -1;
//    }
};

int main() {
    Solution solu;
    string haystack = "sadbutsad", needle = "sad";
    cout << solu.strStr(haystack, needle) << endl;
}