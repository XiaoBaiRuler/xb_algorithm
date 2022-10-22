#include "../common/common.h"
/**
 * @brief 1245. 树的直径
 * https://leetcode.cn/problems/tree-diameter/
 * 
 * 
 */
class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        bool f = true;
        for (auto& e : edges){
            if (e[1] == 0){
                f = false;
                break;
            }
        }
        for (auto& e : edges){
            if (f){
                if (map.find(e[0]) == map.end()){
                    map[e[0]] = new vector<int>();
                }
                map[e[0]] -> push_back(e[1]);
            }
            else{
                if (map.find(e[1]) == map.end()){
                    map[e[1]] = new vector<int>();
                }
                map[e[1]] -> push_back(e[0]);
            }
        }
        select(0);
        return res;
    }
private:
    int select (int i){
        if (map.find(i) == map.end()){
            return 0;
        }
        int f = 0, s = 0, flag = 0;
        for (auto b = map[i] -> begin(), e = map[i] -> end(); b != e; ++ b){
            int n = select(*b);
            if (n > f){
                s = max(f, s);
                f = n;
            }
            else if (n > s){
                s = n;
            }
            flag ++;
        }
        f = flag > 0 ? f + 1 : 0;
        s = flag > 1 ? s + 1 : 0;
        res = max(res, f + s);
        return f;
    }
    unordered_map<int, vector<int>*> map;
    int res = 0;
};
int main(){
    vector<vector<int>> nums = {
        {0,1},{1,2},{2,3},{1,4},{4,5}
    };
    cout << Solution().treeDiameter(nums) << endl;
    return EXIT_SUCCESS;
}