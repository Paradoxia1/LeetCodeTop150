//
// Created by Paradoxia1 on 2023/10/26.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    unordered_map<char, int> symbols = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
    };

public:
    int romanToInt(string s) {
        int ans = 0;
        int temp = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (symbols[s[i]] >= temp) {
                ans += symbols[s[i]];
            } else {
                ans -= symbols[s[i]];
            }
            temp = symbols[s[i]];
        }
        return ans;
    }
};

int main() {
    Solution solu;
    string s = "LVIII";
    cout << solu.romanToInt(s) << endl;
}