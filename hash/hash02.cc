#include "..//common//common.h"
/**
 * @brief 1282. 用户分组
 * https://leetcode.cn/problems/group-the-people-given-the-group-size-they-belong-to/
 * 
 * hash分类 也可以
 * @param groupSizes 
 * @return vector<vector<int>> 
 */
vector<vector<int>> groupThePeople(vector<int>& groupSizes);
int main(){
    vector<int> nums = {3,3,3,3,3,1,3};
    vector<vector<int>> res = groupThePeople(nums);
    for (vector<int>& n : res){
        for (int i : n){
            cout << i << " ";
        }
        cout << endl;
    }
    return EXIT_SUCCESS;
}
vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    unordered_map<int, vector<int>*> m;
    int n = groupSizes.size();
    for (int i = 0; i < n; ++ i){
        if (m.find(groupSizes[i]) == m.end()){
            m[groupSizes[i]] = new vector<int>();
        }
        m[groupSizes[i]] -> push_back(i);
    }
    vector<vector<int>> res;
    for (auto b = m.begin(), e = m.end(); b != e; ++ b){
        int k = b -> second -> size(), g = b -> first;
        if (k == g){
            res.push_back(*b -> second);
        }
        else{
            for (int i = 0, d = k / g; i < d; ++ i){
                vector<int> it;
                for (int j = 0; j < g; ++ j){
                    it.push_back((*b -> second)[i * g + j]);
                }
                res.push_back(it);
            }
        }
    }
    return res;
}