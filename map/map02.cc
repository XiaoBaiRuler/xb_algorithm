#include "..//common//common.h"
/**
 * @brief 433. 最小基因变化
 * https://leetcode-cn.com/problems/minimum-genetic-mutation/
 * 
 * bfs 从end层序遍历start(仅缺一个字符)
 * 注意 end 去掉一个刚好是start的情况
 */
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        sc = start;
        n = bank.size();
        for (int i = 0; i < n; ++ i){
            if (bank[i] == end){
                if (check(bank[i], sc)){
                    return 1;
                }
                unordered_set<int> tmp;
                tmp.insert(i);
                find(end, bank, 1, tmp);
            }
        }
        return res == 100 ? -1 : res;
    }
    void find(string& ec,  vector<string>& bc, int c, unordered_set<int>& index){
        for (int i = 0; i < n; ++ i){
            if (!index.count(i) && check(bc[i], ec)){
                if (check(bc[i], sc) && c + 1 < res){
                    res = c + 1;
                }
                unordered_set<int> tmp(index);
                tmp.insert(i);
                find(bc[i], bc, c + 1, tmp);
            }
        }
    }
    inline bool check(string& sc, string& ec){
        int c = 0;
        for (int i = 0; i < 8; ++ i){
            if (sc[i] != ec[i]){
                ++ c;
                if (c > 1){
                    return false;
                }
            }
        }
        return true;
    }
private:
    string sc;
    int res = 100;
    int n;
};
int main(){
    vector<string> start = {"AACCGGTT", "AACCGGTT", "AAAAACCC"};
    vector<string> end = {"AACCGGTA", "AAACGGTA", "AACCCCCC"};
    vector<vector<string>> bank = {
        {"AACCGGTA"},
        {"AACCGGTA","AACCGCTA","AAACGGTA"},
        {"AAAACCCC","AAACCCCC","AACCCCCC"}
    };
    int n = start.size();
    for (int i = 0; i < n; ++ i){
        Solution t;
        cout << t.minMutation(start[i], end[i], bank[i]) << " ";
    }
    cout << endl;
    return 0;
}