//
// Created by Paradoxia1 on 2024/3/20.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> vec;
        vector<vector<int>> idx;
        int *lens = new int[words.size()];
        int len = 0;
        int row = 0;
        vector<int> temp;
        for (int i = 0; i < words.size(); ++i) {
            if (len + words[i].size() + temp.size() > maxWidth) {
                lens[row] = len;
                idx.push_back(temp);
                ++row;
                len = 0;
                temp = {};
            }
            len += words[i].size();
            temp.push_back(i);
        }
        idx.push_back(temp);
        for (int i = 0; i < idx.size() - 1; ++i) {
            vec.emplace_back("");
            if (idx[i].size() == 1) {
                vec[i] += words[idx[i][0]];
                for (int j = 0; j < maxWidth - words[idx[i][0]].size(); ++j) {
                    vec[i] += " ";
                }
                continue;
            }
            int num = (maxWidth - lens[i]) / (idx[i].size() - 1);
            int rest = (maxWidth - lens[i]) % (idx[i].size() - 1);
            string suffix = "";
            for (int k = 0; k < num; ++k) {
                suffix += " ";
            }
            for (int j = 0; j < idx[i].size(); ++j) {
                vec[i] += words[idx[i][j]];
                if (j != idx[i].size() - 1) vec[i] += suffix;
                if (rest-- > 0) {
                    vec[i] += " ";
                }
            }
        }
        vec.emplace_back("");
        for (int i = 0; i < idx.back().size(); ++i) {
            vec.back() += words[idx.back()[i]];
            if (vec.back().size() < maxWidth) vec.back() += " ";
        }
        len = maxWidth - vec.back().size();
        for (int i = 0; i < len; ++i) {
            vec.back() += " ";
        }
        return vec;
    }
};

int main() {
    Solution solu;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    vector<string> ans = solu.fullJustify(words, maxWidth);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
}