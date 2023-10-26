//
// Created by Paradoxia1 on 2023/10/14.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 贪心算法
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cursum = 0;
        int sum = 0;
        int start = 0;
        for(int i = 0; i < gas.size(); i++) {
            cursum += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if(cursum < 0) {
                start = i+1;
                cursum = 0;
            }
        }
        if(sum < 0) return -1;
        return start;
    }
};

int main() {
    Solution solu;
    vector<int> gas{}, cost{};
    cout << solu.canCompleteCircuit(gas, cost) << endl;
}