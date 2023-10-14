//
// Created by Paradoxia1 on 2023/10/13.
//
#include<bits/stdc++.h>

using namespace std;

class RandomizedSet {
public:
    bool insert(int val) {
        if (umap[val]) {
            return false;
        } else {
            umap[val] = 1;
            return true;
        }
    }

    bool remove(int val) {
        bool flag;
        if (umap[val]) {
            flag = true;
        } else {
            flag = false;
        }
        umap.erase(val);
        return flag;
    }

    int getRandom() {
        int idx = rand() % umap.size();
        return next(umap.begin(), idx)->first;
    }

private:
    unordered_map<int, int> umap;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
    RandomizedSet *obj = new RandomizedSet();
    bool param_1 = obj->insert(1);
    bool param_2 = obj->remove(2);
    bool param_3 = obj->insert(2);
    int param_4 = obj->getRandom();
    bool param_5 = obj->remove(1);
    bool param_6 = obj->insert(2);
    int param_7 = obj->getRandom();
    return 0;
}