//
// Created by Paradoxia1 on 2023/10/26.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    unordered_map<int, string> umap = {
            {1, "IXCM"},
            {5, "VLD"}
    };

public:
    string intToRoman(int num) {
        string roman;
        int k = 0;
        for (int idx = to_string(num).length() - 1; idx > -1; --idx) {
            k = num / int(pow(10,idx));
            num = num % int(pow(10,idx));
            if (k != 4 & k != 9) {
                if (k / 5) {
                    roman.push_back(umap[5][idx]);
                    k = k % 5;
                }
                for (int i = 0; i < k; ++i) {
                    roman.push_back(umap[1][idx]);
                }
            } else {
                roman.push_back(umap[1][idx]);
                if (k / 5) {
                    roman.push_back(umap[1][idx + 1]);
                } else roman.push_back(umap[5][idx]);
            }
        }

        return roman;
    }
};

int main() {
    Solution solu;
    int num = 3999;
    cout << solu.intToRoman(num) << endl;
}