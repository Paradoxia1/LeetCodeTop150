//
// Created by 98751 on 2023/9/26.
//
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int ptr1 = m - 1, ptr2 = n - 1, end = m + n - 1, cur;
        while (ptr1 >= 0 || ptr2 >= 0) {
            if (ptr1 == -1) {
                cur = nums2[ptr2--];
            } else if (ptr2 == -1) {
                cur = nums1[ptr1--];
            } else if (nums1[ptr1] > nums2[ptr2]) {
                cur = nums1[ptr1--];
            } else {
                cur = nums2[ptr2--];
            }
            nums1[end--] = cur;
        }
    };
};

int main() {
    Solution solu;
    vector<int> nums1{0, 0, 0};
    vector<int> nums2{1, 2, 3};
    int m = 0, n = 3;
    solu.merge(nums1, m, nums2, n);
}